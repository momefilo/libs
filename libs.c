// momefilo Desing
#include <stdio.h>
#include "pico/stdlib.h"
#include "flash/flash.h"
#include "sound/sound.h"
#include "ili9341/ili9341.h"
#include "buttons/buttons.h"
//#include "st7735/st7735.h"

/*void test_flash(){
	uint32_t newData[63];
	for(uint8_t i=0; i<63; i++) newData[i] = 0;
	flash_setDataRow(0,62, newData);

	for(uint32_t page=0; page<50; page++){
		uint32_t *data = flash_getData();
		uint32_t newData[63];
		bool diff = false;
		for(uint8_t i=0; i<63; i++){
			if(data[i] != page) diff = true;
			newData[i] = page + 1;
		}
		flash_setDataRow(0,62, newData);
		if(diff) printf("diff_page:%d\n", page - 1);
		printf("p %d", page - 1);
	}
}
*/

/*void test_sound(){
	uint8_t oktave = 1;
	sound_play(7,4,oktave);
	sound_play(4,4,oktave);
	sound_play(2,4,oktave);
	sound_play(0,4,oktave);
	sound_play(2,4,oktave);
	sound_play(4,4,oktave);
	sound_play(7,4,oktave);
	sound_play(4,4,oktave);
	sound_play(2,4,oktave);
	sound_play(0,4,oktave);
	sound_play(2,8,oktave);
	sound_play(4,8,oktave);
	sound_play(2,8,oktave);
	sound_play(4,8,oktave);
	sound_play(7,4,oktave);
	sound_play(4,4,oktave);
	sound_play(7,4,oktave);
	sound_play(9,4,oktave);
	sound_play(4,4,oktave);
	sound_play(9,4,oktave);
	sound_play(7,4,oktave);
	sound_play(4,4,oktave);
	sound_play(2,4,oktave);
	sound_play(0,1,oktave);
}
*/


int main(){
	stdio_init_all();
//	flash_init(0);
	sound_init();
	ili9341_init();
	buttons_init();
	printf("\nstart\n");
//	test_sound();
	sleep_ms(500);
	while(1){

	}
}
