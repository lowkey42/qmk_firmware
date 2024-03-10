RGB_MATRIX_EFFECT(lowkey_reactive)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV lowkey_reactive_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = (tick - dist) << 1;
    if (effect > 255) effect = 255;
    if (dist > 150) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    if (effect < 10 && dist<=4) hsv.s = 0;
    return hsv;
}

static bool lowkey_reactive(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        hsv.v   = 0;
        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));
            hsv           = lowkey_reactive_math(hsv, dx, dy, dist, tick);
        }
        
        HSV hsv_base = rgb_matrix_config.hsv;
        hsv_base.v = scale8(hsv_base.v, 220);
        hsv_base.h = qadd8(hsv_base.h, 15);
        uint16_t time = scale16by8(g_rgb_timer - (i * 315), rgb_matrix_config.speed / 16);
        hsv_base.v    = qadd8(80, scale8(abs8(sin8(time) - 128)*2, hsv_base.v));
        
        hsv.h = qadd8(scale8(hsv.v, rgb_matrix_config.hsv.h), scale8(255-hsv.v, hsv_base.h));
        hsv.v = scale8(hsv.v, 4);
        hsv.v = qadd8(scale8(hsv.v, 255), scale8(255-hsv.v, hsv_base.v));
        
        RGB rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
