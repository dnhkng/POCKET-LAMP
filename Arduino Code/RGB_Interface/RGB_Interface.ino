
#define UV_pin 16
#define red_LED 14
#define green_LED 2  
#define blue_LED 3

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);
  Serial.println("RGB LED tests");
  
  // initialize digital pins as outputs.
  pinMode(UV_pin, OUTPUT);
  pinMode(red_LED, OUTPUT);
  pinMode(green_LED, OUTPUT);
  pinMode(blue_LED, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  Serial.println("Warmup");
  for (int i = 0;  i < 10; i++) { 
    digitalWrite(blue_LED, HIGH);
    delay(500);
    digitalWrite(blue_LED, LOW);
    delay(500); 
  }
  
  Serial.println("Ready, Insert Sample");
  digitalWrite(green_LED, HIGH);
  delay(5000);
  digitalWrite(green_LED, LOW);

  Serial.println("Running");
  for (int i = 0;  i < 10; i++) { 
    digitalWrite(green_LED, HIGH);
    delay(500);
    digitalWrite(green_LED, LOW);
    delay(500);
  }

  Serial.println("Test Negative");
  digitalWrite(blue_LED, HIGH);
  digitalWrite(green_LED, HIGH);
  delay(5000);
  digitalWrite(blue_LED, LOW);
  digitalWrite(green_LED, LOW);

  Serial.println("Test Positive");
  digitalWrite(blue_LED, HIGH);
  digitalWrite(red_LED, HIGH);
  delay(5000);
  digitalWrite(blue_LED, LOW);
  digitalWrite(red_LED, LOW); 
   
  Serial.println("Error Detected");
  for (int i = 0;  i < 20; i++) { 
    digitalWrite(red_LED, HIGH);
    delay(250);
    digitalWrite(red_LED, LOW);
    delay(250);
  }  

  Serial.println("RGB Test Complete");
  delay(10000);
}
