#include<LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

const int trig1 = 10;
const int trig2 = 8;
const int echo1 = 11;
const int echo2 = 9;

const int buzzPin = 7;
long duration;
int distanceCm1;
int distanceCm2;


void setup()
{
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
  Serial.begin(9600);
}


void loop() 
{
  digitalWrite(buzzPin, HIGH);
  
  digitalWrite(trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);  
  delayMicroseconds(10);
  digitalWrite(trig1, LOW);
  duration = pulseIn(echo1, HIGH);
  distanceCm1 = duration*0.034/2;

  digitalWrite(trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);  
  delayMicroseconds(10);
  digitalWrite(trig2, LOW);
  duration = pulseIn(echo2, HIGH);
  distanceCm2 = duration*0.034/2;

  
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm1); // Prints the distance value from the sensor
  lcd.print(" cm");

  lcd.setCursor(0,1); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm2); // Prints the distance value from the sensor
  lcd.print(" cm");

  Serial.print("Distance1 is: ");
  Serial.println(distanceCm1); 

  Serial.print("Distance2 is: ");
  Serial.println(distanceCm2); 

  if ((distanceCm1 < 30) && (distanceCm1 > 0) || (distanceCm2 < 30) && (distanceCm2 > 0))
  {
    digitalWrite(buzzPin, LOW);
  }
  else if ((distanceCm1 < 70) && (distanceCm1 > 0) || (distanceCm2 < 70) && (distanceCm2 > 0))
  {
    
    digitalWrite(buzzPin, LOW);
    delay(2000);
    digitalWrite(buzzPin, HIGH);
  }
  else if ((distanceCm1 < 100) && (distanceCm1 > 0) || (distanceCm2 < 100) && (distanceCm2 > 0))
  {
    
    digitalWrite(buzzPin, LOW);
    delay(1000);
    digitalWrite(buzzPin, HIGH);
  }
  delay(1000);
}
