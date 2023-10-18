#define LED1 18
#define LED2 19
#define BUTTON 21
int buttonState;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(BUTTON);
  if (buttonState == HIGH)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
  }
  else {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
  }
}
