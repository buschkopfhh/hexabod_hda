/* 
* BluetoothInterface.h
*
* Created: 24.05.2018 09:35:26
* Author: henri
*/


#ifndef __BLUETOOTHINTERFACE_H__
#define __BLUETOOTHINTERFACE_H__

#define BluetoothSerial Serial3

class BluetoothInterface
{
//variables

public:

char appValue;
int m_diretionX;
int m_diretionY;
int m_diretionZ;


protected:
private:


//functions
public:
	BluetoothInterface();
	unsigned char readInput();
	int getDirectionX();
	int getDirectionY();
	int getDirectionZ();
	unsigned char hello();
	
	int int2char(char temp);
	
	
	~BluetoothInterface();
	int calcAngle(int appValue);
	
	
protected:
private:
	


}; //BluetoothInterface

#endif //__BLUETOOTHINTERFACE_H__
