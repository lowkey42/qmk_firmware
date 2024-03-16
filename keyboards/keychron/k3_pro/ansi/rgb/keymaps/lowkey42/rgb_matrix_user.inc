RGB_MATRIX_EFFECT(lowkey_reactive)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static uint8_t lowkey_reactive_math(int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = (tick - dist);
    if (effect > 255) effect = 255;
    effect = qmul8(effect, effect);
    effect = qadd8(effect, dist);
    return 255 - effect;
}

static bool lowkey_reactive(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        
        uint8_t click_effect_strength = 0;
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            uint8_t v = lowkey_reactive_math(dx, dy, dist, tick);
            if(v > click_effect_strength)
	            click_effect_strength = v;
        }
        
        uint8_t t = abs8(g_led_config.point[i].y + time + scale8(sin8(g_led_config.point[i].x - scale8(time, 64)), 128));
        t = qsub8(255, qmul8(t,t));
        HSV hsv = rgb_matrix_config.hsv;
        hsv.h = qsub8(hsv.h, scale8(t, 10));
        hsv.v = qadd8(scale8(qsub8(255, t), 80), 255-80);
                
        if(click_effect_strength > 0) {
		    hsv.h = blend8(hsv.h, qadd8(hsv.h, 5), click_effect_strength);
		    hsv.s = blend8(hsv.s, 200, click_effect_strength);
		    hsv.v = blend8(hsv.v, 255, click_effect_strength);
        }
        
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
