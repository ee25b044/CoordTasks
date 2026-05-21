const int ledPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("LED IS ON");
  delay(1000); 
  
  digitalWrite(ledPin, LOW);
  Serial.println("LED IS OFF");
  delay(1000); 
}