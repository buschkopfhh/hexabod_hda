/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <HardwareSerial.h>
//#include "move.h"
#include <string.h>
#include "BluetoothInterface.h"


// the setup function runs once when you press reset or power the board

int count = 0;
int servoAngle1 = 0;
int servoAngle2 = 0;
int servoAngle3 = 0;
int param = 10;

/*
int calcAngle(int appValue)
{
	appValue = appValue*param;
	
	Serial.println(appValue);
	return appValue;
	
		
}
*/

void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(12, OUTPUT); //also pin 12 as LED output

	Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
	Serial.println("This is the arduino for Hexapod!!!");
	Serial.println(" ");
	Serial.println("To connect, start the LED Controller App on your Smartphone");
	Serial.println("and connect to Bluetooth HC-05");


//	BluetoothInterface to;
//	to:BluetoothInterface();	
	digitalWrite(LED_BUILTIN, HIGH); 
  
}


// the loop function runs over and over again forever
void loop() {
	
	
	
	BluetoothInterface to;
	to.readInput();
	
	servoAngle1 = to.getDirectionX();
	servoAngle2 = to.getDirectionY();
	servoAngle3 = to.getDirectionZ();
	
	
	Serial.print(servoAngle1);
	Serial.print(servoAngle2);
	Serial.println(servoAngle3);
	delay(1000);
	
}




	/*
	int i;
		for (i=0; i<7; i++)
	{
		if(Serial.available() > 0)
		{
			lotto[count] = Serial.read();
			count++;		
			
		}
		if(count == 7)
		{
			Serial.println("Reading successful"); 
			for(i=0; i<7; i++){
			Serial.print(lotto[i]);
		}
		Serial.println();
		
		count = 0;
		
	servoAngle1 = calcAngle(lotto[1]);
	servoAngle2 = calcAngle(lotto[3]);
	servoAngle3 = calcAngle(lotto[5]);
	
	Serial.print("Angle of servo 1 = ");
	Serial.println(servoAngle1);
		
	}
	
	
	
	
	
	
	}
	
	
}







/*
if(Serial.available() > 0){ // Checks whether data is coming from the serial port
	//data = Serial.read();  // Reads the data from the serial port
	lotto[count] = Serial.read();
	count++;
	if(count == 6)
	{
		Serial.println("fuck this shit");
		for(i=0; i<6; i++){
			Serial.print(lotto[i]);
		}
		Serial.println();
		
		count = 0;	
	}
	
  // data = 0;
	//char type;
	//int input;
       //Print Value inside data in Serial monitor
   // Serial.print(data);

 /*
 if(data == '1')            //Checks whether value of data is equal to 1
	{
	//digitalWrite(12, HIGH);
	//Serial.println("LED is ON");
	//int t=1;
     

	
	}

  else if(data == '0')       //Checks whether value of data is equal to 0
    {
	digitalWrite(12, LOW);   //If value is 0 then LED turns OFF
 //   digitalWrite(LED_BUILTIN, LOW);
 	Serial.println("LED is OFF");
	 
	
	 */
	 
	 
	 

	/*for(i=0; i<10; i++) {
		digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
		delay(50);
		digitalWrite(13, LOW);
		delay(50);
	}*/