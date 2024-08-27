// C++ code
//
/*
  My thief detecting alarm system
*/

int sensorValue = 0;

int sensor = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(0, OUTPUT);
}

void loop()
{
  sensor = 0.01723 * readUltrasonicDistance(3, 2);
  Serial.println(sensor);
  if (sensor <= 50) {
    digitalWrite(8, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(9, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(10, LOW);
    delay(500); // Wait for 500 millisecond(s)
    tone(11, 294, 1000); // play tone 50 (D4 = 294 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(11, 932, 1000); // play tone 70 (A#5 = 932 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(11, 294, 1000); // play tone 50 (D4 = 294 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(11, 932, 1000); // play tone 70 (A#5 = 932 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(11, 294, 1000); // play tone 50 (D4 = 294 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(11, 932, 1000); // play tone 70 (A#5 = 932 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(11, 294, 1000); // play tone 50 (D4 = 294 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(0, 932, 1000); // play tone 70 (A#5 = 932 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(0, 294, 1000); // play tone 50 (D4 = 294 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(0, 932, 1000); // play tone 70 (A#5 = 932 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(0, 294, 1000); // play tone 50 (D4 = 294 Hz)
    delay(500); // Wait for 500 millisecond(s)
    tone(0, 932, 1000); // play tone 70 (A#5 = 932 Hz)
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    noTone(11);
  }
}