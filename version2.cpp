/*************************************************PULSE*************************************************/
#include <FastLED.h>

#define LED_PIN 3 //Arduino data output pin 3
#define NUM_LEDS 60 //enter Number of LEDS

int r = 252; //LED color variable 'red'
int g = 0; //LED color variable 'green'
int b = 0; //LED color variable 'blue'
int sensorValue = 0; //Microphone variable 'sensor value'

CRGB leds[NUM_LEDS]; //in FastLED each LED strip is an array of CRGB colors, one color each pixel 

void setup() { //intitial setup for system
  FastLED.addLeds<WS2813, LED_PIN, GRB>(leds, NUM_LEDS); //define strip settings like color order ex RGB, GBR was WS2812

  for(int i = 59; i >= 0; i--) {
    leds[i] = CRGB(r, g, b); //light LEDs 0 - 29
    leds[59 - i] = CRGB(r, g, b); //light LEDs 59 - 30
    delay(40); //time delay here
    FastLED.show(); //send data to LED for display
  }
 
  pinMode(A5,INPUT); //configure analog pin 5 for input from microphone

  Serial.begin(9600); //serial port initialiazation
}
void loop() { //always run
  sensorValue = analogRead(A5); //analog reading of input pin A5 and assign to variable
  Serial.println(sensorValue, DEC); //print sensor values to consol and display in decimal
  //change sensitivity
//   if(sensorValue == 530) { //second condition for sensorValue reading
//     leds[29] = CRGB::GhostWhite; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::GhostWhite;
//   }
//   else if(sensorValue == 531) { //first condition for sensorValue reading 
//     leds[29] = CRGB::Yellow; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::Yellow;
//   }
//   else if(sensorValue == 532) { //first condition for sensorValue reading 
//     leds[29] = CRGB::LightGoldenrodYellow; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::LightGoldenrodYellow;
//   }
//   else if(sensorValue == 533) { //first condition for sensorValue reading 
//     leds[29] = CRGB::Gold; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::Gold;
//   }
//   else if(sensorValue == 534) { //second condition for sensorValue reading
//     leds[29] = CRGB::Blue; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::Blue;
//   }
//   else if(sensorValue == 535) { //second condition for sensorValue reading
//     leds[29] = CRGB::Amethyst; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::Amethyst;
//   }
//   else if(sensorValue == 536) { //second condition for sensorValue reading
//     leds[29] = CRGB::Purple; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::Purple;
//   }
//   else if(sensorValue == 537) { //second condition for sensorValue reading
//     leds[29] = CRGB::Teal; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::Teal;
//   }
//   else if(sensorValue == 538) { //second condition for sensorValue reading
//     leds[29] = CRGB::DarkGreen; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::DarkGreen;
//   }
//   else if(sensorValue == 539) { //second condition for sensorValue reading
//     leds[29] = CRGB::HotPink; //set color as specified starting at LED 29 and 30 if conditon met
//     leds[30] = CRGB::HotPink;
//   }
//   else { //otherwise do this
//     leds[29] = CRGB (r, g, b); //no sound maintain initial color settings starting at LEDS 29 and 30
//     leds[30] = CRGB (r, g, b);
//   }

//   for(int i = 0; i <= 28; i++) {
//     leds[i] = leds[i + 1]; //propagate above specified LED settings down lower half  
//     leds[59 - i] = leds[58 - i]; //propagate above specified LED settings down upper half
//   }
  if((sensorValue >= 530) && (sensorValue <= 535)) { //second condition for sensorValue reading
    leds[29] = CRGB (20, 217, 30); //set color as specified starting at LED 29 and 30 if conditon met
    leds[30] = CRGB (20, 217, 30);
  }
  else if((sensorValue >= 536) && (sensorValue <= 540)) { //first condition for sensorValue reading 
    leds[29] = CRGB (20, 135, 217); //set color as specified starting at LED 29 and 30 if conditon met
    leds[30] = CRGB (20, 135, 217); //can also use CRGB::HotPink;
  }
  else if((sensorValue >= 536) && (sensorValue <= 540)) { //second condition for sensorValue reading
    leds[29] = CRGB::Amethyst; //set color as specified starting at LED 29 and 30 if conditon met
    leds[30] = CRGB::Amethyst;
  }
  else if((sensorValue >= 541) && (sensorValue <= 545)) { //second condition for sensorValue reading
    leds[29] = CRGB::Azure; //set color as specified starting at LED 29 and 30 if conditon met
    leds[30] = CRGB::Azure;
  }
  else { //otherwise do this
    leds[29] = CRGB (r, g, b); //no sound maintain initial color settings starting at LEDS 29 and 30
    leds[30] = CRGB (r, g, b);
  }

  for(int i = 0; i <= 28; i++) {
    leds[i] = leds[i + 1]; //propagate above specified LED settings down lower half  
    leds[59 - i] = leds[58 - i]; //propagate above specified LED settings down upper half
  }

  FastLED.show(); //send data to LED for display
  delay(30); //time delay here
}


/*************************************************BOUNCE*************************************************/
// #include <FastLED.h>

// #define LED_PIN 3
// #define NUM_LEDS 60

// int r, g, b;
// int HALF_LEDS = (NUM_LEDS / 2) - 1;

// CRGB leds[NUM_LEDS];

// void setup() {
//   FastLED.addLeds < WS2813, LED_PIN, GRB>(leds, NUM_LEDS);
//   pinMode(A5,INPUT);
// }

// void loop() {
//   int j;
//   j = (528 - analogRead(A5)) * 2;

//   if(j < 0)
//     j = -j;

//   if(j < 29) { 
//     for (int i = 0; i <= j; i++) {
//       if(i < 5) {
//         r = 0;
//         g = 0;
//         b = 255;
//       }
//       else if(i < 10) {
//         r = 0;
//         g = 127;
//         b = 255;
//       }
//       else if(i < 15) {
//         r = 0;
//         g = 255;
//         b = 127;
//       }
//       else if(i < 20) {
//         r = 127;
//         g = 255;
//         b = 0;
//       }
//       else if(i < 25) {
//         r = 255;
//         g = 127;
//         b = 0;
//       }
//       else {
//         r = 255;
//         g = 0;
//         b = 0;
//       }
      
//       leds[HALF_LEDS - i] = CRGB(r, g, b);
//       leds[HALF_LEDS + i] = CRGB(r, g, b);
//       FastLED.show();
//     }
 
//     for (int i = j; i <= HALF_LEDS; i++) {
//       leds[HALF_LEDS - i] = CRGB(0, 0, 0);
//       leds[i + HALF_LEDS] = CRGB(0, 0, 0);
//       FastLED.show();
//     }
//   }
// }