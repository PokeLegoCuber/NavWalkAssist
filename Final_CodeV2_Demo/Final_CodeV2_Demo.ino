// defines pins numbers
const int trigPin = 11;//Input
const int echoPin = 13;//Output
const int speakerPin = 8;
const int thresholdDist = 178 / 2;
const int maxDelay = 1500;
const int freq = 3000;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() 
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(500000);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  if(distance < thresholdDist * 0.125)
  {
    Serial.println("level 1");
    tone(speakerPin,freq,200);
    delay(10);
  }
  else if(distance < thresholdDist * 0.25)
  {
    Serial.println("level 2");
    tone(speakerPin,freq,200);
    delay(200);
  }
  else if(distance < thresholdDist * 0.5)
  {
    Serial.println("level 3");
    tone(speakerPin,freq,200);
    delay(700);
  }
  else if(distance < thresholdDist)
  {
    Serial.println("level 4");
    tone(speakerPin,freq,200);
    delay(1000);
  }
  
}
