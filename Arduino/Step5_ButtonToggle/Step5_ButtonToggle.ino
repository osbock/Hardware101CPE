#define BUTTONA 4
#define BUTTONB 5
void setup() {
  Serial.begin(115200);
  pinMode(BUTTONA, INPUT_PULLDOWN);
  pinMode(BUTTONB, INPUT_PULLDOWN);

}
int lastAReading=0;
int lastBReading=0;

void loop() {
  int Areading = digitalRead(BUTTONA);
  int Breading = digitalRead(BUTTONB);
  
  if ((Areading != lastAReading ) && Areading ==0){
    Serial.println("A Button-toggle");
    delay(100);
  }
  if ((Breading != lastBReading ) && Breading ==0){
    Serial.println("B Button-toggle");
    delay(100);
  }
  lastAReading = Areading;
  lastBReading = Breading;
  

}
