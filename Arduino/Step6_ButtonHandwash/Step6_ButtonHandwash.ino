#include <Adafruit_CircuitPlayground.h>
#define BUTTONA 4
#define BUTTONB 5
long lastUpdate = 0L;
#define UPDATERATE 2000
enum state {
  COUNTING,
  STOPPED
} State = STOPPED;
int Counter = 10;

void stopIt(){
  CircuitPlayground.clearPixels();
  Counter=10;
  State = STOPPED;
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
  State=COUNTING;
}
void setup() {
  Serial.begin(115200);
  pinMode(BUTTONA, INPUT_PULLDOWN);
  pinMode(BUTTONB, INPUT_PULLDOWN);
  CircuitPlayground.begin();
  CircuitPlayground.clearPixels();

}
int lastAReading=0;
int lastBReading=0;


void loop() {
  int Areading = digitalRead(BUTTONA);
  int Breading = digitalRead(BUTTONB);
  
  if ((Areading != lastAReading ) && Areading ==0){
    lightup();
    Serial.println("Lightup");
    delay(100);
  }
  if ((Breading != lastBReading ) && Breading ==0){
    stopIt();
    Serial.println("Stop");
    delay(100);
  }
  lastAReading = Areading;
  lastBReading = Breading;

  long current = millis();
  if ((current - lastUpdate)>UPDATERATE && State == COUNTING){
    lastUpdate = current;
    CircuitPlayground.setPixelColor(Counter,0x000000);
    Counter--;
    if (Counter < 0)
      stopIt();
  }

}
