/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/
//int data = 0;
char data = 0;
// the setup function runs once when you press reset or power the board


void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(13, OUTPUT);

  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission


  
}


// the loop function runs over and over again forever
void loop() {

if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    
    
    data = Serial.read();   // Reads the data from the serial port
  // data = 0;
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line 
    
 if(data == '1')            //Checks whether value of data is equal to 1 
    digitalWrite(13, HIGH);  //If value is 1 then LED turns ON
  else if(data == '0')       //Checks whether value of data is equal to 0
    digitalWrite(13, LOW);   //If value is 0 then LED turns OFF



}



 

 
/*
 
    data = 1;
    

      
      
    
   
    
    
    
    }
  */
/*
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(200);                       // wait for a second


*/
/* if (state == '0') {
  digitalWrite(LED_BUILTIN, LOW); // Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: ON"
  state = 0;
 }
 
 else if (state == '1') {
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED: ON");;
  state = 0;
 }
 */
}
