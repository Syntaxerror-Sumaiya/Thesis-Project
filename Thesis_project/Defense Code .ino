
#include <Servo.h>
//lcd 1602
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//start Rotary section
int buzzer = 8;
int pot = A5;
int value ;
//end rotary section

//soner sensor
const int trigPin1 = 22;
const int echoPin1 = 23;
const int trigPin2 = 24;
const int echoPin2 = 25;
const int trigPin3 = 26;
const int echoPin3 = 27;
const int trigPin4 = 28;
const int echoPin4 = 29;
long duration1, duration2, duration3, duration4;
int distanceCm1, distanceInch1, distanceCm2, distanceInch2, distanceCm3, distanceInch3, distanceCm4, distanceInch4;

//end sonar sensor
int pir1 = 41;
int pir2 = 40;
int pirbuzzer1 = 42;
int pirbuzzer2 = 43;
int pirstate1;
int pirstate2;

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  lcd.begin(16, 2);
  myservo.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  //start buzzer
  pinMode(pir1, INPUT);
  pinMode(pir2, INPUT);
  pinMode(pirbuzzer1, OUTPUT);
  pinMode(pirbuzzer2, OUTPUT);

  //send buzzer
  //soner sensor
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);

  //end sonser sensor

  // Start Rotary section

  pinMode(pot , INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  //end rotary section

}


void loop() {
  //potentiometer();


  //rotating clockwise
  for (pos = 0; pos <= 60; pos += 5) { // goes from 0 degrees to 180 degrees

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    
    potentiometer();
    sonersensor_1_4();
    read_pir();
    delay(100);
  }
  for (pos = 60; pos <= 120; pos += 5) {

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    
    potentiometer();
    sonersensor_1_4();
    read_pir();
    delay(100);
  }
  for (pos = 120; pos <= 180; pos += 5) {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    
    potentiometer();
   sonersensor_1_4();
    read_pir();
    delay(100);
  }
  // waits 15ms for the servo to reach the position


  for (pos = 180; pos >= 120; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    
   potentiometer();
    sonersensor_1_4();
    read_pir();
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 120; pos >= 60; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   
    potentiometer();
    sonersensor_1_4();
    read_pir();
    delay(100);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 60; pos >= 0; pos -= 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
   
    potentiometer();
    sonersensor_1_4();
    read_pir();
    delay(100);                       // waits 15ms for the servo to reach the position
  }

}

void read_pir() {
  pirstate1 = digitalRead(pir1);
  pirstate2 = digitalRead(pir2);
  // digitalWrite(pirbuzzer1,pirstate1);
  //digitalWrite(pirbuzzer2, pirstate2);
  Serial.print("pir 1:");
  Serial.print(pirstate1);
  lcd.setCursor(0, 0);
  lcd.print ("pir 1: ");
  lcd.print(pirstate1);
  Serial.print("pir2 :");
  Serial.println(pirstate2);
  lcd.setCursor(0, 1);
  lcd.print ("pir 2: ");
  lcd.print(pirstate2);
  delay (200);
  lcd.clear ();
  // pir1 sensor output section
  if (pirstate1 > 0) {
    tone(pirbuzzer1 , 800, 10000);
  }
  // pir2 sensor output section
  if (pirstate2 > 0) {
    tone(pirbuzzer2, 800, 10000);
  }

}


void sonersensor_1_4() {

  //soner sensor
  // sesnor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceCm1 = duration1 * 0.034 / 2;
  distanceInch1 = duration1 * 0.0133 / 2;
  Serial.print ("Sensor 1: ");
  Serial.print (distanceCm1);
  Serial.print (" cm ");
  Serial.print(distanceInch1);
  Serial.println(" Inc");
  lcd.setCursor(0, 0);
  lcd.print ("Sensor-1: ");
  lcd.print (distanceCm1);
  lcd.print ("cm");
  // sesnor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distanceCm2 = duration2 * 0.034 / 2;
  distanceInch2 = duration2 * 0.0133 / 2;
  Serial.print ("Sensor 2: ");
  Serial.print (distanceCm2);
  Serial.print (" cm ");
  lcd.setCursor(0, 1);
  lcd.print ("Sensor-2: ");
  lcd.print (distanceCm2);
  lcd.print ("cm");
  Serial.print(distanceInch2);
  Serial.println(" Inc");
  delay (200);
  lcd.clear ();

  // sesnor 3
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distanceCm3 = duration3 * 0.034 / 2;
  distanceInch3 = duration3 * 0.0133 / 2;
  Serial.print ("Sensor 3: ");
  Serial.print (distanceCm3);
  Serial.print (" cm ");
  Serial.print(distanceInch3);
  Serial.println(" Inc");
  lcd.setCursor(0, 0);
  lcd.print ("Sensor-3: ");
  lcd.print (distanceCm3);
  lcd.print ("cm");

  // sesnor 4
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin4, LOW);
  duration4 = pulseIn(echoPin4, HIGH);
  distanceCm4 = duration4 * 0.034 / 2;
  distanceInch4 = duration4 * 0.0133 / 2;
  Serial.print ("Sensor 4: ");
  Serial.print (distanceCm4);
  Serial.print (" cm ");
  Serial.print(distanceInch4);
  Serial.println(" Inc");
  lcd.setCursor(0, 1);
  lcd.print ("Sensor-4: ");
  lcd.print (distanceCm4);
  lcd.print ("cm");
  delay (200);
  lcd.clear ();


  //end soner sensor



}

void potentiometer () {
  //start rutary section
  value = 31.2805474096 * analogRead(pot);
  Serial.println("Friquency :");
  Serial.print(value);
  Serial.println (" HZ");
  tone (buzzer, value, 10000);
  lcd.setCursor(0, 0);
  lcd.print ("..Frequency..");
  lcd.setCursor(0, 1);
  lcd.print ("-:");
  lcd.print (value);
  lcd.print ("HZ");
  delay (300);
  lcd.clear ();
  //end rotary setion

}
