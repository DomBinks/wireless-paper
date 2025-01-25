#include "HT_lCMEN2R13EFC1.h"

#define WIDTH 250
#define HEIGHT 122

HT_ICMEN2R13EFC1 display(6, 5, 4, 7, 3, 2, -1);

struct Segment {
    int x;
    int y;
    int w;
    int h;
};

struct Segment sa = {10, 0, 30, 10};
struct Segment sb = {0, 10, 10, 30};
struct Segment sc = {40, 10, 10, 30};
struct Segment sd = {10, 40, 30, 10};
struct Segment se = {0, 50, 10, 30};
struct Segment sf = {40, 50, 10, 30};
struct Segment sg = {10, 80, 30, 10};

struct Segment sx = {0, 20, 10, 10};
struct Segment sy = {0, 60, 10, 10};

struct Segment one[2] = {sc, sf};
struct Segment two[5] = {sa, sc, sd, se, sg};
struct Segment three[5] = {sa, sc, sd, sf, sg};
struct Segment four[4] = {sb, sc, sd, sf};
struct Segment five[5] = {sa, sb, sd, sf, sg};
struct Segment six[6] = {sa, sb, sd, se, sf, sg};
struct Segment seven[3] = {sa, sc, sf};
struct Segment eight[7] = {sa, sb, sc, sd, se, sf, sg};
struct Segment nine[5] = {sa, sb, sc, sd, sf};

void drawSegment(struct Segment* s, int size, int offset) {
    for (int i = 0; i < size; i++) {
        display.drawRect(
            s[i].x+offset,
            s[i].y,
            s[i].w,
            s[i].h
        );
    }
}

void fillSegment(struct Segment* s, int size, int offset) {
    for (int i = 0; i < size; i++) {
        display.fillRect(
            s[i].x+offset,
            s[i].y,
            s[i].w,
            s[i].h
        );
    }
}

void drawBar() {
    display.drawRect(
        0,
        110,
        250,
        10
    );
}

void setup()
{
    Serial.begin(115200);
    Serial.println("START SETUP");

    pinMode(45, OUTPUT);
    digitalWrite(45, LOW);
    delay(100);

    display.init();
    display.clear();
    
    Serial.println("END SETUP");
}

void loop()
{
    display.clear();

    int offset = 0;
    for(int o = 0; o < 4; o++) {
        drawSegment(eight, sizeof(eight) / sizeof(eight[0]), offset);
        fillSegment(one, sizeof(one) / sizeof(one[0]), offset);

        offset += 60;

        if (offset == 120) {
            struct Segment a[2] = {sx, sy};
            fillSegment(a, 2, offset);

            offset += 20;
        }
    }

    drawBar();

    display.update(BLACK_BUFFER);
    display.display();

    while (true) {
        delay(10000);
    };
}
