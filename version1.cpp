#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#define PIN 3	
#define NUM_PIXELS 20

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

//void count();

int i = 0;
int red = 0;
int green = 0;
int blue = 0;
//int button_count = 0;
int sensorValue = 0;

void setup() {
	Serial.begin(9600);
	pixels.begin();
	//pinMode (2, INPUT);
	//attachInterrupt(digitalPinToInterrupt(2), count, RISING);
	pinMode(A5, INPUT);
}

// void count() {
//   	button_count++;
// }

void loop() {
	sensorValue = analogRead(A5);
	Serial.println(sensorValue, DEC);

	if(sensorValue < 515) {
    	for(i = 0; i < 10; i++) {
    		pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    		pixels.show();
 
    		delay(100);
  		}
	}

	if(sensorValue = 516) {
		for(i = 0; i <= NUM_PIXELS; i++) {
			if(i == NUM_PIXELS) {
				for(i = NUM_PIXELS; i >= 0; i--) {
				pixels.setPixelColor(i, pixels.Color(0, 255, 0));
				pixels.show();
		
				delay(250);
				}
			}

    		pixels.setPixelColor(i, pixels.Color(200, 0, 200));
    		pixels.show();
 
    		delay(250);
		}
    }

	if(sensorValue > 517) {
		for(i = 0; i <= NUM_PIXELS; i++) {
			red = random(0, 255);
			green = random(0, 255);
			blue = random(0, 255);
			pixels.setPixelColor(i, pixels.Color(red, green, blue));
			pixels.show();

			delay(100);

			pixels.setPixelColor(i, pixels.Color(0, 0, 0));
			pixels.show();
		}
	
	}
}

// void loop() {
// 	sensorValue = analogRead(A5);
// 	Serial.println(sensorValue, DEC);

//   	switch(button_count) {
//     case 0:
//   	for(i = 0; i <= NUM_PIXELS; i++) {
//     	pixels.setPixelColor(i, pixels.Color(0, 255, 255));
//     	pixels.show();
 
//     	delay(250);
//     }
//     break;
    
//     case 1:
//   	for(i = 0; i < NUM_PIXELS; i++) {
//     	red = random(0, 255);
//     	green = random(0, 255);
//     	blue = random(0, 255);

//     	pixels.setPixelColor(i, pixels.Color(red, green, blue));
//     	pixels.show();
 
//     	delay(250);
//   	}
//     break;
    
//     case 2:
//     for(i = NUM_PIXELS; i >= 0; i--) {
//     	pixels.setPixelColor(i, pixels.Color(200, 0, 200));
//     	pixels.show();
 
//     	delay(250);
//   	}
//     break;
    
//     case 3:
//     for(i = NUM_PIXELS; i >= 20; i--) {
//     	pixels.setPixelColor(i, pixels.Color(0, 0, 255));
//     	pixels.show();
 
//     	delay(250);
//   	}
//     for(i = 0; i < 20; i++) {
//     	pixels.setPixelColor(i, pixels.Color(0, 255, 0));
//     	pixels.show();
 
//     	delay(250);
//   	}
//     break;
    
//     case 4:
//     for(i = 0; i <= NUM_PIXELS; i++) {
//       	if(i == NUM_PIXELS) {
// 			for(i = NUM_PIXELS; i >= 0; i--) {
// 			pixels.setPixelColor(i, pixels.Color(0, 255, 0));
// 			pixels.show();
	
// 			delay(250);
// 			}
//       	}

//     	pixels.setPixelColor(i, pixels.Color(200, 0, 200));
//     	pixels.show();
 
//     	delay(250);
//     }
//     break;
    
//     default:
//     button_count = 0;
//   }
// }