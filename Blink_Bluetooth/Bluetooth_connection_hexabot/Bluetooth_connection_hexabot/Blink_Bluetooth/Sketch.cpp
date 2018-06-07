/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <HardwareSerial.h>
#include "BluetoothInterface.h"


// the setup function runs once when you press reset or power the board

//int count = 0;


/*
int Angle(char tempappValue)
{
	int appValue = (int) tempappValue;
	appValue = appValue*param;
	
	Serial.println(appValue);
	return appValue;
	
		
}

int int2char(char temp)
{
	int integer = (int) temp - '0';
	return integer;
	
}

*/
void setup() {
	// initialize digital pin LED_BUILTIN as an output.
	

	Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
	Serial.println("This is the arduino for Hexapod!!!");
	Serial.println(" ");
	Serial.println("To connect, start the LED Controller App on your Smartphone");
	Serial.println("and connect to Bluetooth HC-05");


	//int count = 0;
//	BluetoothInterface to;
//	to:BluetoothInterface();	
	digitalWrite(LED_BUILTIN, HIGH); 
  
}


// the loop function runs over and over again forever
void loop() {
	
	
/*	
	BluetoothInterface to;
	to.readInput();
	
	servoAngle1 = to.getDirectionX();
	servoAngle2 = to.getDirectionY();
	servoAngle3 = to.getDirectionZ();
	
	
	Serial.print(servoAngle1);
	Serial.print(servoAngle2);
	Serial.println(servoAngle3);

	*/
	/*char lotto[7];
	int i;
	int k;
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
				for(k=0; k<7; k++){
					Serial.print(lotto[k]);
				}
		Serial.println();
		
		count = 0;
		
/*	servoAngle1 = calcAngle(lotto[1]);
	servoAngle2 = calcAngle(lotto[3]);
	servoAngle3 = calcAngle(lotto[5]);
	
	Serial.print("Angle of servo 1 = ");
	Serial.println(servoAngle1);
	
		}

	}
}

	*/
// 
// 	BluetoothInterface myBluetoothclass;
// 	myBluetoothclass.readInput();
/*	
	Serial.print("Printing the Value for Servo1: ");
	Serial.println(myBluetoothclass.getDirectionX());
	
	Serial.print("Printing the Value for Servo2: ");
	Serial.println(myBluetoothclass.getDirectionY());
	
	Serial.print("Printing the Value for Servo3: ");
	Serial.println(myBluetoothclass.getDirectionZ());
*/

	//data = Serial.read();  // Reads the data from the serial port
	
// 	int serv1;
// 	int serv2;
// 	int serv3;
// 	char data;
		
	BluetoothInterface myBluetooth;
	
	myBluetooth.readInput();
	
	
// 	for(k=0;k<7;k++){
// 		if(Serial.available() > 0){
// 				lotto[count] = Serial.read();
// 				Serial.println(Angle(lotto[count]));
// 				Serial.print("debug k: "); // k is hier zufällig, deshalb zählt count nicht hoch
// 				Serial.println(k);
// 				Serial.println(lotto[count]);
// 				Serial.print("debug count: ");
// 				Serial.println(count);
// 				count++;
// 			
// 		}
// 	}
// 		if(count == 6){
// 			Serial.println("yes it runs");
// 			int i;
// 			for(i=0; i<7; i++){
// 				Serial.print(lotto[i]);
// 			}
// 				//	Serial.println();
// 				
// 				//count = 0;
// 			
// 	}
	



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