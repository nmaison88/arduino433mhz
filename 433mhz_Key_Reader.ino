
#include <RCSwitch.h>
#include <EEPROM.h>
unsigned long time;
boolean first=true;

RCSwitch mySwitch = RCSwitch();

void setup() {
  
  Serial.begin(115200);
  Serial.println("Power ON");
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
}


void loop() {
 time = millis();//global Timer, check each message agains timer to debounce. 

  if (mySwitch.available()) {
    String value;
    value= mySwitch.getReceivedValue();
//          Serial.println( "got" + value );
    mySwitch.resetAvailable();

    if (value == 0) {
      Serial.print("Unknown encoding");
    } 
    
     if  (value == "13476776"){
         int snap = time;
         int hold;

        if(first==true){
         first=false;
         hold=snap+1000;
        Serial.print("Key Sensor Codes ");
        Serial.println( value + " Time " + hold );
        }
        else if(hold<=time) {
          
        Serial.print("Key Sensor Codes ");
        Serial.println( value + " Time " + hold );
        }
//      
      
     }  
      else if  (value == "4289350"){
      Serial.print("DOOR SENSOR 2 ");
      Serial.println( value );  
      
    }else {
      Serial.print("Received Random one ");
      Serial.println( value );  
    }

  }
//  Serial.println(time);
}
