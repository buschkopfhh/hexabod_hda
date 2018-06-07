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
	m_diretionX=0;
	m_diretionY=0;
	m_diretionZ=0;
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(12, OUTPUT); //also pin 12 as LED output

/*	Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
	Serial.println("This is the arduino for Hexapod!!!");
	Serial.println(" ");
	Serial.println("To connect, start the LED Controller App on your Smartphone");
	Serial.println("and connect to Bluetooth HC-05");
*/	
	
	
	BluetoothSerial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
} //BluetoothInterface



int BluetoothInterface::int2char(char temp){
	int integer = (int) temp - '0';
	return integer;
}

unsigned char BluetoothInterface::readInput(){

	int i;
	int data;
	char servo1;
	char servo2;
	char servo3;

	int count;
	if(BluetoothSerial.available() > 0)
	{
		data = Serial.read();
		Serial.println(data);
		Serial.print("Count: ");
		Serial.println(count);
		switch (count)
		{
			case 0:
				if(data == 'A'){
					count++;
					Serial.println("data = A");
				}
				else{
					Serial.println("Case 0");
				}
	
			break;
	
			case 1:
				if(int2char(data) >= 0 && int2char(data) < 10){
					servo1 = data;
					count++;
					Serial.print("Servo1 = ");
					Serial.println(servo1);
				}
				else{
					Serial.println("Case 1");
				}
	
			break;
	
			case 2:
				if(data == 'B'){
					count++;
					Serial.println("data = B");
				}
				else{
					Serial.println("Case 2");
				}
	
				break;
	
			case 3:
				if(int2char(data) >= 0 && int2char(data) < 10){
					servo2 = data;
					count++;
					Serial.print("Servo2 = ");
					Serial.println(servo2);
				}
				else{
					Serial.println("Case 3");
				}
	
			break;
	
			case 4:
				if(data == 'C'){
					count++;
					Serial.println("data = C");
				}
				else{
					Serial.println("Case 4");
				}
	
				break;
	
			case 5:
				if(int2char(data) >= 0 && int2char(data) < 10){
					servo3 = data;
					count++;
					Serial.print("Servo3 = ");
					Serial.println(servo3);
				}
				else{
					Serial.println("Case 5");
				}
	
			break;
	
			case 6:
				if(data == '#'){
					count = 0;
				}
				else{
					Serial.println("Case 6");
				}
	
			break;
	
			default:
				Serial.println("default");
	
		}
		
		
		m_diretionX =  int2char(servo1);
		m_diretionY =  int2char(servo2);
		m_diretionZ =  int2char(servo3);
	
	}
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
// default destructor
BluetoothInterface::~BluetoothInterface()
{
} //~BluetoothInterface
