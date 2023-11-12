#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "sound.h"

const uint16_t FreqArray[]={2179,2189,2381,2229,2478,2441,2405,2336,2417,2491,2314,2543};
uint Slice_num;

void Sound_play(uint8_t sound){
	uint8_t mydiv = 2;
	float Divider = 1.f;
	if(sound == SOUND_ROW){
		pwm_set_enabled(Slice_num, true);
		for(int i=0; i<12; i++){
			Divider = clock_get_hz(clk_sys)/FreqArray[i];
			pwm_set_gpio_level(BUZZER_PIN, FreqArray[i]/mydiv);
			pwm_set_clkdiv(Slice_num, Divider);
			sleep_ms(25);
		}
		pwm_set_enabled(Slice_num, false);
	}
	if(sound == SOUND_FALL){
		pwm_set_enabled(Slice_num, true);
		for(int i=11; i>=6; i=i-1){
			Divider = clock_get_hz(clk_sys)/FreqArray[i];
			pwm_set_gpio_level(BUZZER_PIN, FreqArray[i]/mydiv);
			pwm_set_clkdiv(Slice_num, Divider);
			sleep_ms(25);
		}
		pwm_set_enabled(Slice_num, false);
	}
	if(sound == SOUND_BAH){
		pwm_set_enabled(Slice_num, true);
		for(int i=11; i>=6; i=i-2){
			Divider = clock_get_hz(clk_sys)/FreqArray[i];
			pwm_set_gpio_level(BUZZER_PIN, FreqArray[i]/mydiv);
			pwm_set_clkdiv(Slice_num, Divider);
			sleep_ms(330);
		}
		pwm_set_enabled(Slice_num, false);
	}
	if(sound == SOUND_YEH){
		pwm_set_enabled(Slice_num, true);
		for(int i=4; i<8; i=i+2){
			Divider = clock_get_hz(clk_sys)/FreqArray[i];
			pwm_set_gpio_level(BUZZER_PIN, FreqArray[i]/mydiv);
			pwm_set_clkdiv(Slice_num, Divider);
			sleep_ms(330);
		}
		Divider = clock_get_hz(clk_sys)/FreqArray[3];
		pwm_set_gpio_level(BUZZER_PIN, FreqArray[3]/mydiv);
		pwm_set_clkdiv(Slice_num, Divider);
		sleep_ms(330);
		Divider = clock_get_hz(clk_sys)/FreqArray[9];
		pwm_set_gpio_level(BUZZER_PIN, FreqArray[9]/mydiv);
		pwm_set_clkdiv(Slice_num, Divider);
		sleep_ms(660);
		pwm_set_enabled(Slice_num, false);
	}
}

void sound_init(){
	gpio_set_function(BUZZER_PIN, GPIO_FUNC_PWM);
	Slice_num = pwm_gpio_to_slice_num(BUZZER_PIN);
}
