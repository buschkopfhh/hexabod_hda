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
			
		for(int count = 0; count < 7; count++){		
			delay(100);		
			data = BluetoothSerial.read();
			Serial.println(count);
			switch (count)
			{
				case 0:
				if(data == 'A'){
					count++;
					//					Serial.println("data = A");*/
				}
				else{
					Serial.println("Case 0");
					count++;			
					Serial.println(count);
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
					// 					Serial.println("data = B");
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
				}				break;
				case 4:
				if(data == 'C'){
					count++;
					// 					Serial.println("data = C");
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
				}				break;				
				case 6:
				if(data == '#'){
					count = 0;
					Serial.println("==============");
				}
				else{
					Serial.println("Case 6");
				}
				break;
				default:
				Serial.println("default");
			}
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