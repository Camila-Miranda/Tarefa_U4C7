#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO_PIN 22 // GPIO do servo
#define LED_R 12
#define LED_G 13
#define LED_B 14

#define PWM_FREQ 50      // Frequência do PWM (50Hz)
#define PWM_WRAP 20000   // PWM_WRAP baseado em clock de 1MHz (20ms = 20000 ticks)

// Configura os LEDs RGB
void set_rgb_color(uint color) {
    gpio_put(LED_R, (color & 0x1) != 0);
    gpio_put(LED_G, (color & 0x2) != 0);
    gpio_put(LED_B, (color & 0x4) != 0);
}

// Configuração do PWM para o servo
void pwm_setup() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM);
    uint sliceNum = pwm_gpio_to_slice_num(SERVO_PIN);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 125.f); // Ajuste correto do clock para 50Hz
    pwm_config_set_wrap(&config, PWM_WRAP);

    pwm_init(sliceNum, &config, true);
}

// Move o servo para um determinado pulso (em microssegundos)
void move_servo(uint gpio, uint pulse_width) {
    uint sliceNum = pwm_gpio_to_slice_num(gpio);
    uint level = (pulse_width * PWM_WRAP) / 20000; // Cálculo correto do duty cycle
    pwm_set_gpio_level(gpio, level);
}

// Movimento suave do servo entre 0° e 180°
void smooth_movement() {
    for (uint pulse = 500; pulse <= 2400; pulse += 5) {
        move_servo(SERVO_PIN, pulse);
        set_rgb_color(0x1); // Vermelho enquanto sobe
        sleep_ms(10);
    }
    for (uint pulse = 2400; pulse >= 500; pulse -= 5) {
        move_servo(SERVO_PIN, pulse);
        set_rgb_color(0x2); // Verde enquanto desce
        sleep_ms(10);
    }
}

int main() {
    stdio_init_all();

    // Inicialização dos LEDs
    gpio_init(LED_R);
    gpio_set_dir(LED_R, GPIO_OUT);
    gpio_init(LED_G);
    gpio_set_dir(LED_G, GPIO_OUT);
    gpio_init(LED_B);
    gpio_set_dir(LED_B, GPIO_OUT);

    pwm_setup();

    printf("Movendo para 180 graus...\n");
    move_servo(SERVO_PIN, 2400);
    sleep_ms(5000);

    printf("Movendo para 90 graus...\n");
    move_servo(SERVO_PIN, 1470);
    sleep_ms(5000);

    printf("Movendo para 0 graus...\n");
    move_servo(SERVO_PIN, 500);
    sleep_ms(5000);

    printf("Movimentação suave entre 0 e 180 graus...\n");
    while (1) {
        smooth_movement();
    }

    return 0;
}
