#define LED_BUILTIN_ESP 2
void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN_ESP, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN_ESP, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN_ESP, LOW);
  delay(1000);
}
