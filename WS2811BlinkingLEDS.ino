#include <Adafruit_NeoPixel.h>

#define PIN 6 //Data
#define NUM_LEDS 50

Adafruit_NeoPixel strip(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int LEDR = 0;
int LEDG = 255;
int LEDB = 0;
int BRIGHTNESS = 0;
bool isBrightnessIncreasing = true;

void setup() {
  strip.begin();
  strip.setBrightness(100);
  strip.show();
}

void loop(){
  strip.setPixelColor(12, strip.Color(0,255,0));
  strip.setBrightness(BRIGHTNESS);
  if(isBrightnessIncreasing){
    BRIGHTNESS += 10;
    for(int i=0; i<13; i++){
      if(i != 12){
        strip.setPixelColor(i, strip.Color(LEDG,LEDR,LEDB));
      }
    }
    delay(50);
    if(BRIGHTNESS >= 240){
      isBrightnessIncreasing = false;
    }
  }
  if(!isBrightnessIncreasing){
    BRIGHTNESS -= 10;
    for(int i=0; i<13; i++){
      if(i != 12){
        strip.setPixelColor(i, strip.Color(LEDG,LEDR,LEDB));
      }
    }
    delay(50);
    if(BRIGHTNESS <= 15){
      isBrightnessIncreasing = true;
    }
  }
  strip.show();
}

// void loop() {
//   LEDG += 1;
//   strip.setPixelColor(12, strip.Color(0,255,0));
//   for(int i=0; i<13; i++){
//     LEDG += 1;
//     if(i != 12){
//       strip.setPixelColor(i, strip.Color(LEDG,0,0));
//     }
//     delay(10);
//   }
//   if(LEDG >= 244){
//     LEDG = 0;
//   }
//   strip.show();
// }
