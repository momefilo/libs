#ifndef momefilo_sound_h
#define momefilo_sound_h 1

#define BUZZER_PIN 5
#define SOUND_FALL 1
#define SOUND_ROW 2
#define SOUND_BAH 3
#define SOUND_YEH 4

void sound_init();
void Sound_play(uint8_t sound);
#endif