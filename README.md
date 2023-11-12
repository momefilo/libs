# libs
Bibliotheken für Raspi Pico\
\
#flash:\
Verwaltet beliebig viele 4kb Sektoren des Flashspeichers vom Ende herab.\
Stellt pro 4kb-Sektor 63 uint32_t Werte in eimen eindimensionalen Array zur verfuegung welche nur 1/16 der Loeschvorgange im Flashspeicher benoetigen. Die Funktion Schaltet die IRQs beim schreiben in den Flash ab\
Es gibt vier Funktionen von denen flash_init(stage) zuerst aufgerufen werden muss bevor
auf die anderen drei zugegriffen werden kann. Weitere Informationen finden sich in den Kommentaren der flash.h Datei.\
void flash_init(uint8_t stage): initialisiert den Speicher mit der Kennung stage. Ist der Speicher neu wird er mit 0en gefuellt.\
void flash_setData(uint8_t id, uint32_t data): Speichert den Wert data an der Position id im uint32_t Array.\
void flash_setDataRow(uint8_t start, uint8_t end, uint32_t *data): Speichert fortlaufen von start bis einschliesslich end die Daten von *data im uint32_t Array.\
uint32_t *flash_getData(): Gibt das uint32_t Array[63] zurueck\
\
#sound:\
Giebt Toene mit einem Passivbuzzer aus\
\
#ili9341:\
Displaygrafik\
\
#st7735:\
Displaygrafik\
\
#fonts:\
Die Fonts fuer Displaygrafik\
