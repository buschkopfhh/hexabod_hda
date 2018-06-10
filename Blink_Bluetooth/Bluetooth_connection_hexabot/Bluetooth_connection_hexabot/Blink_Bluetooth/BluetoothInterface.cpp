/* 
* BluetoothInterface.cpp
*
* Created: 24.05.2018 09:35:26
* Author: henri
*/


#include "BluetoothInterface.h"
#include <HardwareSerial.h>
#include <Arduino.h>


// default constructor
BluetoothInterface::BluetoothInterface(){
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(12, OUTPUT); //also pin 12 as LED output
	BluetoothSerial.begin(9600);
	
	
} //BluetoothInterface



unsigned char BluetoothInterface::readInput()
{
	char servo1;
	char servo2;
	char servo3;
	char data;

	int count = 0;
	
	if(BluetoothSerial.available() > 0){
			
		
			delay(100);		
			data = BluetoothSerial.read();
			delay(100);

			switch (data)
			{
				case 'A':
				servo1 = BluetoothSerial.read();
				Serial.println("IN A");
				Serial.println(servo1);
				break;
				
				case 'B':
				servo2 = BluetoothSerial.read();
				Serial.println("IN b");
				Serial.println(servo2);
				
				break;
				case 'C':
				servo3 = BluetoothSerial.read();
				Serial.println("IN c");
				Serial.println(servo3);
				
				break;
				
				case '#':
				
				Serial.println("=========");
								
				break;
				
				default:
				Serial.println("default");
			
		}
			
	}
}

int BluetoothInterface::sendData()
{
	Serial.println("Now in Loop");
	if(BluetoothSerial.available ()>0)
	{
		Serial.println("BT is available");
	
		char buffer_value = BluetoothSerial.read();
		Serial.println(buffer_value);
		if(buffer_value == 'a' || buffer_value == 'A')
		{
			digitalWrite(13, HIGH);    //Turn ON LED
			Serial.println("LED ON");  //Arduino Terminal of Desktop
			BluetoothSerial.println("LED ON"); //Bluetooth Terminal on Mobile
		}
		else if(buffer_value == 'b' || buffer_value == 'B')
		{
			digitalWrite(13, LOW);      //Turn OFF LED
			Serial.println("LED OFF");  //Arduino Terminal on Desktop
			BluetoothSerial.println("LED OFF"); //Bluetooth Terminal on Mobile
		}
	}
}

int BluetoothInterface::int2char(char temp){
	int integer = (int) temp - '0';
	return integer;
}



int BluetoothInterface::calcAngle(int appValue){
	int param = 10;
	//int appValue = (int) tempappValue,
	
	appValue = appValue*param;
	return appValue;

}
int BluetoothInterface::getDirectionX(){
	return m_diretionX;

}

int BluetoothInterface::getDirectionY(){
	return m_diretionY;
}

int BluetoothInterface::getDirectionZ(){
	return m_diretionZ;
}

unsigned char BluetoothInterface::hello()
{
	Serial.println("Class is working");
	delay(50);
}

// default destructor
BluetoothInterface::~BluetoothInterface()
{
} //~BluetoothInterface