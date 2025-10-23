#include <Servo.h>
const int SENDEN = 12; 
const int ECHO = 13;  
Servo servoMotor;
int pos = 0; 
int Entfernung = 0;
int servoPin = 16; 
const int AmpelRot = 5; 
const int AmpelGelb = 4; 
const int AmpelGruen = 0; 

void setup()
{ 
Serial.begin(9600);
pinMode(AmpelRot, OUTPUT);
pinMode(AmpelGelb, OUTPUT);
pinMode(AmpelGruen, OUTPUT);
servoMotor.attach(2);
servoMotor.write(0);
pinMode(SENDEN, OUTPUT);
pinMode(ECHO, INPUT);


} 
void loop()
{ 
 // Sender kurz ausschalten, um Störungen des Signals zu vermeiden
 digitalWrite(SENDEN, LOW);
 delay(5);
 // Signal für 10 Microsekunden senden, danach wieder ausschalten
 digitalWrite(SENDEN, HIGH);
 delayMicroseconds(10);
 digitalWrite(SENDEN, LOW);
 // pulseIn -> Zeit messen, bis das Signal zurückkommt
 long Zeit = pulseIn(ECHO, HIGH);
 // Entfernung in cm berechnen
 // Zeit/2 -> nur eine Strecke
 Entfernung = (Zeit / 2) * 0.03432; 
 delay(500);
 
 // Messdaten anzeigen
 Serial.print("Entfernung in cm: ");
 Serial.println(Entfernung);

  if (Entfernung > 80) {
servoMotor.write(95);
trafficLightControl(4, 1, 0);

} 
else { 
servoMotor.write(5);
trafficLightControl(0, 1, 4);
}
delay(1000);
}
void trafficLightControl(int redDuration, int yellowDuration,
int greenDuration)
{
digitalWrite(AmpelRot, HIGH);
delay(redDuration * 1000);
digitalWrite(AmpelRot, LOW);
digitalWrite(AmpelGelb, HIGH);
delay(yellowDuration * 1000);
digitalWrite(AmpelGelb, LOW);
digitalWrite(AmpelGruen, HIGH);
delay(greenDuration * 1000);
digitalWrite(AmpelGruen, LOW);
} 
