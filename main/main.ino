int redPin = 22;
int yellowPin = 26;
int greenPin = 24;
int analogPin = A7;
int readVal;
float v2;
int dt = 500;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  readVal = analogRead(analogPin);
  v2 = (5./1023.) * readVal;
  if (v2 < 3.00) {
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  }
  if (v2 >= 3.00 && v2 < 4.00) {
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
  }
  if (v2 >= 4.00) {
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  }
  Serial.println(v2);
  delay(dt);
}