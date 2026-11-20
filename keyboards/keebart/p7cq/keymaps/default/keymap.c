#include QMK_KEYBOARD_H
#include "transactions.h"
#include "usb_device_state.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX,         KC_Q,         KC_W,         KC_E,         KC_R,           KC_T,        XXXXXXX,           XXXXXXX,           KC_Y,         KC_U,         KC_I,         KC_O,            KC_P,       XXXXXXX,
        XXXXXXX, LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),           KC_G,        XXXXXXX,           XXXXXXX,           KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN),       XXXXXXX,
        XXXXXXX,         KC_Z,         KC_X,         KC_C,         KC_V,           KC_B,                                              KC_N,         KC_M,      KC_COMM,       KC_DOT,         KC_SLSH,       XXXXXXX,
                                                                 KC_ESC, LT(1, KC_QUOT),  LT(4, KC_TAB),    LT(3, KC_BSPC),  LT(2, KC_SPC),       KC_ENT
    ),
    [1] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,        XXXXXXX,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,   LCTL(KC_LEFT),       XXXXXXX,
        XXXXXXX,      _______,      _______,      _______,      _______,        XXXXXXX,        XXXXXXX,           XXXXXXX,        KC_LEFT,      KC_DOWN,        KC_UP,      KC_RGHT,   LCTL(KC_BSLS),       XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,                                     LCTL(KC_RGHT),      KC_HOME,      KC_PGDN,      KC_PGUP,          KC_END,       XXXXXXX,
                                                                XXXXXXX,        _______,        XXXXXXX,            KC_DEL,        XXXXXXX,      XXXXXXX
    ),
    [2] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX,      KC_LBRC,         KC_7,         KC_8,         KC_9,        KC_RBRC,        XXXXXXX,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,         XXXXXXX,       XXXXXXX,
        XXXXXXX,      KC_MINS,         KC_4,         KC_5,         KC_6,         KC_EQL,        XXXXXXX,           XXXXXXX,        XXXXXXX,      _______,      _______,      _______,         _______,       XXXXXXX,
        XXXXXXX,       KC_GRV,         KC_1,         KC_2,         KC_3,        KC_BSLS,                                           XXXXXXX,      XXXXXXX,      XXXXXXX,      KC_PDOT,         XXXXXXX,       XXXXXXX,
                                                                XXXXXXX,           KC_0,        XXXXXXX,           XXXXXXX,        _______,      XXXXXXX
    ),
    [3] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX,       KC_F12,        KC_F7,        KC_F8,        KC_F9,        KC_PSCR,        XXXXXXX,           XXXXXXX,        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,         XXXXXXX,       XXXXXXX,
        XXXXXXX,       KC_F11,        KC_F4,        KC_F5,        KC_F6,        KC_SCRL,        XXXXXXX,           XXXXXXX,        XXXXXXX,      _______,      _______,      _______,         _______,       XXXXXXX,
        XXXXXXX,       KC_F10,        KC_F1,        KC_F2,        KC_F3,        KC_PAUS,                                           XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,         XXXXXXX,       XXXXXXX,
                                                                KC_MUTE,        KC_VOLD,        KC_VOLU,           _______,        XXXXXXX,      XXXXXXX
    ),
    [4] = LAYOUT_split_3x6_3_ex2(
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,        XXXXXXX,           XXXXXXX,        XXXXXXX,      XXXXXXX,      MS_WHLU,      XXXXXXX,         XXXXXXX,       XXXXXXX,
        XXXXXXX,      _______,      _______,      _______,      _______,        XXXXXXX,        XXXXXXX,           XXXXXXX,        MS_LEFT,      MS_DOWN,        MS_UP,      MS_RGHT,         XXXXXXX,       XXXXXXX,
        XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,      XXXXXXX,        XXXXXXX,                                           XXXXXXX,      XXXXXXX,      MS_WHLD,      XXXXXXX,         KC_CAPS,       XXXXXXX,
                                                                XXXXXXX,        XXXXXXX,        _______,           MS_BTN1,        MS_BTN3,      MS_BTN2
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [1] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [2] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [3] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
    [4] =
    {
        ENCODER_CCW_CW(RGB_MOD, RGB_RMOD),
        ENCODER_CCW_CW(RGB_HUI, RGB_HUD),
        ENCODER_CCW_CW(RGB_VAI, RGB_VAD),
        ENCODER_CCW_CW(RGB_SAI, RGB_SAD),
    },
};
#endif

#ifdef RGB_MATRIX_ENABLE

#define INDICATOR_BRIGHTNESS 10

/* Indicator colors as sRGB {r, g, b}, gamma-corrected and scaled by INDICATOR_BRIGHTNESS */
static const uint8_t caps_lock_color[3] = {0xCC, 0x24, 0x1D};
static const uint8_t power_on_color[3]  = {0x45, 0x85, 0x88};

/* How long the power-on indicator stays lit, in milliseconds */
#define POWER_ON_INDICATOR_MS 3000

/* Power-on indicator keys, as {row, col} */
static const uint8_t power_on_keys[][2] = {
    {3, 5}, {7, 5},
};

/* Caps Lock indicator keys, as {row, col} */
static const uint8_t caps_lock_keys[][2] = {
    {3, 5}, {7, 5},
};

enum indicator_state {
    INDICATOR_CAPS_LOCK = 1 << 0,
    INDICATOR_POWER_ON  = 1 << 1,
};

/*
 * Power-on indicator state. The half connected to the computer decides it and
 * sends it to the other half, so both halves light up and go dark together
 */
static bool power_on_lit = false;

static void power_on_sync_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    if (in_buflen == sizeof(power_on_lit)) {
        memcpy(&power_on_lit, in_data, sizeof(power_on_lit));
    }
}

void keyboard_post_init_user(void) {
    transaction_register_rpc(USER_SYNC_POWER_ON, power_on_sync_handler);
}

/*
 * Runs on the half connected to the computer. The indicator starts only once
 * USB is configured to avoid blinking.
 */
static void power_on_task(void) {
    static enum { WAITING, LIT, DONE } phase = WAITING;
    static uint32_t lit_timer  = 0;
    static uint32_t sync_timer = 0;
    static bool     synced     = false;

    if (phase == WAITING && usb_device_state_get_configure_state() == USB_DEVICE_STATE_CONFIGURED) {
        phase        = LIT;
        lit_timer    = timer_read32();
        power_on_lit = true;
    } else if (phase == LIT && timer_elapsed32(lit_timer) >= POWER_ON_INDICATOR_MS) {
        phase        = DONE;
        power_on_lit = false;
    }

    /* Resend until the other half has received the current state */
    if (power_on_lit != synced && timer_elapsed32(sync_timer) > 20) {
        sync_timer = timer_read32();
        if (transaction_rpc_send(USER_SYNC_POWER_ON, sizeof(power_on_lit), &power_on_lit)) {
            synced = power_on_lit;
        }
    }
}

static uint8_t get_indicator_state(void) {
    uint8_t state = 0;
    if (host_keyboard_led_state().caps_lock) {
        state |= INDICATOR_CAPS_LOCK;
    }
    if (power_on_lit) {
        state |= INDICATOR_POWER_ON;
    }
    return state;
}

static void set_color_for_key(uint8_t row, uint8_t col, uint8_t r, uint8_t g, uint8_t b, uint8_t led_min, uint8_t led_max) {
    uint8_t led = g_led_config.matrix_co[row][col];
    if (led != NO_LED && led >= led_min && led < led_max) {
        rgb_matrix_set_color(led, r, g, b);
    }
}

/*
 * Convert an sRGB color channel to an LED level at the indicator brightness,
 * or to zero when the indicator is off. The channel is gamma-corrected (~2.0)
 */
static uint8_t indicator_level(uint8_t channel, bool on) {
    return on ? ((uint32_t)channel * channel * INDICATOR_BRIGHTNESS + 255 * 255 / 2) / (255 * 255) : 0;
}

/* Set every key in `keys` to `color`, or to off when `on` is false */
static void draw_keys(const uint8_t keys[][2], uint8_t count, const uint8_t color[3], bool on, uint8_t led_min, uint8_t led_max) {
    uint8_t r = indicator_level(color[0], on);
    uint8_t g = indicator_level(color[1], on);
    uint8_t b = indicator_level(color[2], on);
    for (uint8_t i = 0; i < count; i++) {
        set_color_for_key(keys[i][0], keys[i][1], r, g, b, led_min, led_max);
    }
}

/*
 * Draw the indicators in `state`. With `clear` set, all indicator keys are
 * blanked first, so an inactive indicator never blanks a key shared with an
 * active one. Later indicators win on shared keys
 */
static void draw_indicators(uint8_t state, bool clear, uint8_t led_min, uint8_t led_max) {
    if (clear) {
        draw_keys(power_on_keys, ARRAY_SIZE(power_on_keys), power_on_color, false, led_min, led_max);
        draw_keys(caps_lock_keys, ARRAY_SIZE(caps_lock_keys), caps_lock_color, false, led_min, led_max);
    }
    if (state & INDICATOR_POWER_ON) {
        draw_keys(power_on_keys, ARRAY_SIZE(power_on_keys), power_on_color, true, led_min, led_max);
    }
    if (state & INDICATOR_CAPS_LOCK) {
        draw_keys(caps_lock_keys, ARRAY_SIZE(caps_lock_keys), caps_lock_color, true, led_min, led_max);
    }
}

/* RGB matrix enabled: draw indicators on top of the active effect */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    draw_indicators(get_indicator_state(), false, led_min, led_max);
    return true;
}

/*
 * RGB matrix disabled: the indicator LEDs are written and flushed directly
 * while everything else stays dark
 */
static uint8_t direct_state = 0;

static void write_indicators_direct(uint8_t state) {
    /* Only touch the LEDs driven by this half */
    const uint8_t split[2] = RGB_MATRIX_SPLIT;
    uint8_t       led_min  = is_keyboard_left() ? 0 : split[0];
    uint8_t       led_max  = is_keyboard_left() ? split[0] : split[0] + split[1];

    draw_indicators(state, true, led_min, led_max);
    rgb_matrix_update_pwm_buffers();
    direct_state = state;
}

void housekeeping_task_user(void) {
    static uint32_t last_refresh = 0;

    if (is_keyboard_master()) {
        power_on_task();
    }

    if (rgb_matrix_is_enabled()) {
        direct_state = 0;
        return;
    }

    uint8_t state = get_indicator_state();
    /*
     * The periodic refresh restores the indicators after the matrix blanks all
     * LEDs once when it gets switched off
     */
    if (state != direct_state || (state && timer_elapsed32(last_refresh) > 250)) {
        write_indicators_direct(state);
        last_refresh = timer_read32();
    }
}

void suspend_power_down_user(void) {
    if (direct_state) {
        write_indicators_direct(0);
    }
}
#endif
