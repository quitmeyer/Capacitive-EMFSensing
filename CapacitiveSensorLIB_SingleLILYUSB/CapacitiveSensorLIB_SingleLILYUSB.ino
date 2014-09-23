#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_Sender_Sensor = CapacitiveSensor(A2,A3);        // 10M resistor between pins A2 & A3, pin A3 is sensor pin, add a wire and or foil
int LED= 13;
int motor = 9;
long timer=0;
void setup()                    
{
   cs_Sender_Sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);   //This is just a big number in HEX = 4294967295  // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
       long testtotal =  cs_Sender_Sensor.capacitiveSensor(30);
    delay(250);
    cs_Sender_Sensor.reset_CS_AutoCal()
   timer=millis();
}

void loop()                    
{
  if(millis()-timer>10000){  //Reset after 10 secs
    digitalWrite(LED,LOW);
    delay(250);
    cs_Sender_Sensor.reset_CS_AutoCal()
     digitalWrite(LED,HIGH);
    delay(50);
     digitalWrite(LED,LOW);
    delay(50);
    digitalWrite(LED,HIGH);
    delay(50);
     digitalWrite(LED,LOW);
    delay(50);
  }

    long total3 =  cs_Sender_Sensor.capacitiveSensor(30);
    
analogWrite(LED, val);
analogWrite(motor,val);

    Serial.println(total3);                // print sensor output 3

    delay(10);                             // arbitrary delay to limit data to serial port 
}
