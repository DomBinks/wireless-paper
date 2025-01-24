#include "HT_lCMEN2R13EFC1.h"

#define WIDTH 250
#define HEIGHT 122

HT_ICMEN2R13EFC1 display(6, 5, 4, 7, 3, 2, -1);

void setup()
{
    uint8_t arr[] = {
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF
    };

    Serial.begin(115200);
    Serial.println("START");

    pinMode(45, OUTPUT);
    digitalWrite(45, LOW);
    delay(100);

    display.init();

    display.clear();
    display.drawXbm(100, 100, 32, 4, arr);
    display.update(BLACK_BUFFER);
    display.display();

    Serial.println("END");
}

void loop()
{
}
