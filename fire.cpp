#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#define PIN 3, 4
#define NUM_PIXELS 25

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

int sensorValue = 0;

void setPixelHeatColor (int Pixel, byte temperature) {
  // Scale 'heat' down from 0-255 to 0-191
  byte t192 = round((temperature / 255.0) * 191);
 
  // calculate ramp up from
  byte heatramp = t192 & 0x3F; // 0..63
  heatramp <<= 2; // scale up to 0..252
 
  // figure out which third of the spectrum we're in:
  if( t192 > 0x80) {                     // hottest
    pixels.setPixelColor(Pixel, 255, 255, heatramp);
  } else if( t192 > 0x40 ) {             // middle
    pixels.setPixelColor(Pixel, 255, heatramp, 0);
  } else {                               // coolest
    pixels.setPixelColor(Pixel, heatramp, 0, 0);
  }
}

void Fire(int Cooling, int Sparking, int SpeedDelay) {
  static byte heat[NUM_PIXELS];
  int cooldown;
 
  // Step 1.  Cool down every cell a little
  for( int i = 0; i < NUM_PIXELS; i++) {
    cooldown = random(0, ((Cooling * 10) / NUM_PIXELS) + 2);
   
    if(cooldown > heat[i]) {
      heat[i] = 0;
    } else {
      heat[i] = heat[i] - cooldown;
    }
  }
 
  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for( int k = NUM_PIXELS - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }
   
  // Step 3.  Randomly ignite new 'sparks' near the bottom
  if( random(255) < Sparking ) {
    int y = random(7);
    heat[y] += random(160, 255);
  }

  // Step 4.  Convert heat to LED colors
  for( int j = 0; j < NUM_PIXELS; j++) {
    setPixelHeatColor(j, heat[j]);
  }

  pixels.show();
  delay(SpeedDelay);
}

void setup() {
	Serial.begin(9600);
	pixels.begin();
  pixels.clear();
	pinMode(A5, INPUT);
}

void loop() {
  sensorValue = analogRead(A5);
  Serial.println(sensorValue, DEC);
  Fire(55, 120, 50);
}