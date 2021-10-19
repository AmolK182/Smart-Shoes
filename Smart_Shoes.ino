// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;
const int trigPin0 = 5;
const int echoPin0 = 6;

// defines variables
long duration;
int distance;
int dist;
int dur;
int safetyDistance1;
int safetyDistance0;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT);// Sets the echoPin as an Input
pinMode(trigPin0, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin0, INPUT);
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Us 2
digitalWrite(trigPin0, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin0, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin0, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
dur = pulseIn(echoPin0, HIGH);
// Calculating the distance
dist= dur*0.034/2;


//Loops 
safetyDistance1 = distance;
if (safetyDistance1 <= 60){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
safetyDistance0 = dist;
if (safetyDistance0 <= 60){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}
}
