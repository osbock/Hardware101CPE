#include <Adafruit_CircuitPlayground.h>
float value, ambient_value;
int counting = 0; // are we counting down?
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();
  // Take 10 millisecond of sound data to calculate ambient
  ambient_value = CircuitPlayground.mic.soundPressureLevel(50);
  Serial.print("ambient: ");Serial.println(ambient_value);
}

void lightup(){
  CircuitPlayground.setPixelColor(0, 255,   0,   0);
  CircuitPlayground.setPixelColor(1, 128, 128,   0);
  CircuitPlayground.setPixelColor(2,   0, 255,   0);
  CircuitPlayground.setPixelColor(3,   0, 128, 128);
  CircuitPlayground.setPixelColor(4,   0,   0, 255);
  
  CircuitPlayground.setPixelColor(5, 0xFF0000);
  CircuitPlayground.setPixelColor(6, 0x808000);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  CircuitPlayground.setPixelColor(8, 0x008080);
  CircuitPlayground.setPixelColor(9, 0x0000FF);
}
void loop() {
  
// Take 10 milliseconds of sound data to calculate
  value = CircuitPlayground.mic.soundPressureLevel(50);
  Serial.println(value-ambient_value);
  if ((value - ambient_value) > 20  )
  {
    lightup();
    for (int i = 9 ; i >=0; i--){
      delay(2000);
      CircuitPlayground.setPixelColor(i,0x000000);
    }
  }
  delay(100);
}
