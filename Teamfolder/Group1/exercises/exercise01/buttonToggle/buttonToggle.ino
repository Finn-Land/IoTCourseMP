// C++ code
//
#define LED1 18
#define LED2 19
#define BUTTON 21
int currentButtonState;
int lastButtonState;
int ledState;
int counter = 0;
void setup()
{
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}


void loop() {
  lastButtonState    = currentButtonState;                // save the last state
  currentButtonState = digitalRead(BUTTON); // read new state
  
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.print("The button is pressed: ");
  
    // toggle state of LED
    if(currentButtonState == LOW) {
       currentButtonState = HIGH;  
       Serial.println("Turning LED on");
    }
    else {
      currentButtonState = LOW;
      Serial.println("Turning LED off");
    } 
  }
}
