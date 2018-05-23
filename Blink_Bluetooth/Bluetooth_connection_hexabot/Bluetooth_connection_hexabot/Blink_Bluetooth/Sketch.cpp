/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <HardwareSerial.h>
#include <move.h>
#include <string.h>

/*End of auto generated code by Atmel studio */


char data = 0;
// the setup function runs once when you press reset or power the board


void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(12, OUTPUT);

	Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
	Serial.println("This is the arduino for Hexapod!!!");
	Serial.println(" ");
	Serial.println("To connect, start the LED Controller App on your Smartphone");
	Serial.println("and connect to Bluetooth HC-05");
	
	digitalWrite(LED_BUILTIN, HIGH); 
  
}


// the loop function runs over and over again forever
void loop() {
int i;
if(Serial.available() > 0){ // Checks whether data is comming from the serial port

    data = Serial.read();   // Reads the data from the serial port
  // data = 0;
    Serial.println(data);        //Print Value inside data in Serial monitor
    
 if(data == '1')            //Checks whether value of data is equal to 1
	{
	digitalWrite(12, HIGH);
	Serial.println("LED is ON");
	
	move to; // class move, object: to
	
	}

  else if(data == '0')       //Checks whether value of data is equal to 0
    {
	digitalWrite(12, LOW);   //If value is 0 then LED turns OFF
 //   digitalWrite(LED_BUILTIN, LOW);
 	Serial.println("LED is OFF");
	 
	
	 
	 
	 
	 
	}
	}
}
	/*for(i=0; i<10; i++) {
		digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
		delay(50);
		digitalWrite(13, LOW);
		delay(50);
	}*/