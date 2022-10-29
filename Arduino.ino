#define THRESHOLD 440

const int trigPin = 9;
const int echoPin = 10;

int led1 =5;
int led2=4; 

int water; //random variable 
int RELAY_PIN=3;
int MOISTURE_PIN=6;

long duration;
int distance;
void setup()
   {
    pinMode(trigPin,OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin,INPUT); // Sets the echoPin as an Input
    Serial.begin(9600); // Starts the serial communication

    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);

    pinMode(RELAY_PIN, OUTPUT);
   }

void loop() 
{
    digitalWrite(trigPin, LOW); // Clears the trigPin
    delayMicroseconds(2); // Sets the trigPin on HIGH state for 10 micro seconds
 
    digitalWrite(trigPin, HIGH); // write the Trigger for MCU on Module 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW); // Reads the echoPin, returns the sound wave travel time in microseconds
 
    duration = pulseIn(echoPin, HIGH); // Using the Formula
    distance= duration*0.034/2;

    Serial.print("Water Level: ");
    Serial.println(distance);// Prints the distance on the Serial Monitor

    delay(40); 
    if(distance>=8)
    {
      digitalWrite(led1,HIGH); 
    }
    else
    {
      digitalWrite(led1,LOW);
    }
    if(distance<8)
    {
      digitalWrite(led2,HIGH); 
    }
    else
    {
      digitalWrite(led2,LOW);
    }
    
    int value = analogRead(MOISTURE_PIN); // read the analog value from sensor
    if (value < THRESHOLD) {
      Serial.print("The soil is DRY => turn pump ON");
      digitalWrite(RELAY_PIN, HIGH);
    } else {
      Serial.print("The soil is WET => turn pump OFF");
      digitalWrite(RELAY_PIN, LOW);
    }
    Serial.print(" (");
    Serial.print(value);
    Serial.println(")");
    delay(400);
  }