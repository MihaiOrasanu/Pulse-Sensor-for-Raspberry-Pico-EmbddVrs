// Note de subsol: n-am niciun comentariu. Doar nu afiseaza valorile :(


#include "pulse.h" 




#define LED  25
#define ADC_PIN       A0 

PulseSensor pulse(ADC_PIN); 

unsigned long t1,t2;

//============================================================
void setup() 
{
    Serial.begin(115200);
    
    Serial.println("Pulse sensor");
    
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);
    

    pulse.begin();
}
 
//============================================================
void loop() 
{
     
    int beat = pulse.read_beat();
    if (beat != 0)
    {
        if (beat<100) Serial.print(" ");
        Serial.print(beat);
        Serial.print(" BPM");
        t1 = millis();
    }  
   
      
    t2 = millis();
    delay(10);
}
