#include "Wire.h"
#define S 10

int  U4PortA, U4PortB = 0; // Define variables to hold I/O port readings.
int count = 0;

void setup()
{
  Serial.begin(9600);                      // Begin Serial Communication
  Wire.begin();                            // Begin I2C Communication
  /*
      The following code starts I2C communication with MCP23017(U2).Please refer MCP23017 datasheet
      for register addresses. Sets all GPIOs of this IC to INPUT
  */
  // Ends I2C communication with MCP23017(U2) IC
  /*
      The following code starts I2C communication with MCP23017(U4).Please refer MCP23017 datasheet
      for register addresses. Sets all GPIOs of this IC to INPUT
  */
  Wire.beginTransmission(0x21);            // Starts communication with MCP23017(U4) IC
  Wire.write(0x00);                        // Set MCP23017 memory pointer to IODIRA address
  Wire.write(0x00);                        // Set all PORTA pins to OUTPUT
  Wire.endTransmission();                  // Ends I2C communication with MCP23017(U4) IC
  /*
    Wire.beginTransmission(0x21);            // Starts communication with MCP23017(U4) IC
    Wire.write(0x00);                        // Set MCP23017 memory pointer to IODIRB address
    Wire.write(0xFF);                        // Set all PORTB pins to OUTPUT
    Wire.endTransmission();                  // Ends I2C communication with MCP23017(U4) IC
  */
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
}

void loop()
{
  // Store the incoming byte of PORTB into "U2PortB"
  /*
    Wire.beginTransmission(0x21);            // Start I2C communication with MCP23017(U4)
    Wire.write(0x12);                        // Set MCP23017 memory pointer to PORTA address
    Wire.endTransmission();                  // Ends I2C communication with U4
    Wire.requestFrom(0x21, 1);             // Request one byte of data from MCP20317(U4)
    U4PortA = Wire.read();                   // Store the incoming byte of PORTA into "U4PortA"

    Wire.beginTransmission(0x21);            // Start I2C communication with U4
    Wire.write(0x13);                     // Set MCP23017 memory pointer to PORTB address
    Wire.endTransmission();                  // Ends I2C communication with U4
    Wire.requestFrom(0x21, 1);               // Request one byte of data from MCP20317
    U4PortB = Wire.read();                   // Store the incoming byte of PORTB into "U4PortB"

  */
  count %= (T / 2);
  if (p == 0) {
    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(0);
    Wire.endTransmission();
    U4PortA = analogRead(A0);

    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(1);
    Wire.endTransmission();
    U4PortB = analogRead(A1);
  }
  else if(p == 1){
    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(2);
    Wire.endTransmission();
    U4PortA = analogRead(A2);

    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(3);
    Wire.endTransmission();
    U4PortB = analogRead(A3);    
  }
    else if(p == 2){
    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(4);
    Wire.endTransmission();
    U4PortA = analogRead(A5);

    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(5);
    Wire.endTransmission();
    U4PortB = analogRead(A6);    
  }
    else if(p == 3){
    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(6);
    Wire.endTransmission();
    U4PortA = analogRead(A6);

    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(7);
    Wire.endTransmission();
    U4PortB = analogRead(A7);    
  }
    else if(p == 4){
    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(8);
    Wire.endTransmission();
    U4PortA = analogRead(A8);

    Wire.beginTransmission(0x21);
    Wire.write(0x12);
    Wire.write(9);
    Wire.endTransmission();
    U4PortB = analogRead(A9);    
  }
  Serial.print(U4PortA);
  Serial.print(",");            // Print the contents of the PORTA register in binary
  Serial.print(U4PortB);            // Print the contents of the PORTB register in binary
  Serial.print(",");
  if(p==4){
    Serial.println("");
  }
  count++;
//  delay(200);
}
