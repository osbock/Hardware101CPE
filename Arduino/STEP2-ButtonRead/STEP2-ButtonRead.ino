#define BUTTON_A 4
#define BUTTON_B 5
void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_A,INPUT_PULLDOWN);

}

void loop() {
  int reading = digitalRead(BUTTON_A);
  Serial.println(reading);

}
