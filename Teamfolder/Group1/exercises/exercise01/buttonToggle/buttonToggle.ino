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
    if(ledState == LOW) {
       ledState = HIGH;  
       Serial.println("Turning LED on");
    }
    else {
      ledState = LOW;
      Serial.println("Turning LED off");
    }
 
    // control LED arccoding to the toggled state
    digitalWrite(LED1, ledState);  //turns the LED on or off based on the variable
   digitalWrite(LED2, ledState);  
  }
}
