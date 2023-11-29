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

uint16_t area[4];

int main(){
	stdio_init_all();
//	flash_init(0);
//	sound_init();
	ili9341_init();
	ili9341_touch_init();
	setOrientation(VERTICAL);
	setBgColor(0x0000);
//	buttons_init();
	printf("\nstart\n");
	while(1){
		uint16_t *pos = ili9341_getTouch();
		if(pos[0]<0xffff){
			area[0]=pos[0];
			area[1]=pos[1];
			area[2]=pos[0]+2;
			area[3]=pos[1]+2;
			printf("%d, %d\n", pos[0], pos[1]);
			paintRect(area, 0xffff);
		}
		sleep_ms(100);
	}
}
