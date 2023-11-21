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
Spielt die zwoelf Toene ueber zwei Oktaven\
sound_init() muss zu erst aufgerufen werden!\
sound_play(uint8_t note, uint8_t dauer, uint8_t oktave)\
note: 0=C bis 11=B\
dauer: Teilt die 1,5 Sekunden tondauer (1,5sec/dauer)\
oktave: 0=Grundoktave, 1=eine Oktave hoeher\
\
#ili9341:\
Displaygrafik mit 565-bit Farbcodierung\
Zwie Textfunktionen, eine mit 12x12-Pixel und eine mit 16x16-Pixel Font\
Zwei Rechteck-Zeichenfunktionen, eine Solid die andere mit Verlauf von zwei Farben\
Genaue Informationen finden sich in der Datei "ili9341/ili9341.h"\
\
#st7735:\
Displaygrafik mit 444-bit Farbcodierung\
Zwie Textfunktionen, eine mit 12x12-Pixel und eine mit 16x16-Pixel Font\
Zwei Rechteck-Zeichenfunktionen mit 656-Bit Farbcodierung, eine Solid die andere mit
Verlauf von zwei Farben\
Genaue Informationen finden sich in der Datei "st7735/st7735.h"\
\
#fonts:\
Die Fonts fuer Displaygrafik\
