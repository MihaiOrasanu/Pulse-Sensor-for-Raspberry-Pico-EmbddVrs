
#include "pulse.h"

 
//=================================================  
PulseSensor::PulseSensor(int analogPin)
{
  _analogPin = analogPin;
 
}

//================================================
void PulseSensor::begin() 
{
	init();
}

// init the states
//================================================
void PulseSensor::init() 
{
    state = 0;
    beat = 0;
    t1 = millis();
    t2 = millis();
}

//automat cu 3 stari -> nici aici nu am gandit-o prea bine dar nu da eroare

int PulseSensor::read_beat()
{
    int beat = 0;
    
    uint16_t value = analogRead(_analogPin);
    
    if (state==0)
    {
        if (value > BMP_VALUE_HI)
        {
            state = 1;
            t1 = millis();
        }
    }
    else if (state==1)
    {   
        if (value < BMP_VALUE_LO)
            state = 2;
    }
    else if  (state==2)
    {
       if (value > BMP_VALUE_HI)
       {
            t2 = millis();
            beat = int(60000.0 / (t2 - t1));  //60 de secunde deci 60*10^3 milisecunde
            t1 = t2;
            state = 1;
            if (beat < 40 || beat > 240)
            {    beat = 0;
                state = 0;
            }
       }
    }
    return beat  ;  
}
