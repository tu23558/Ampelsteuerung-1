const int SENDEN = 12; 
const int ECHO = 13; 
int Entfernung = 0; 

void setup()
{ 
Serial.begin(9600);
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

}