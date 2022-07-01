/*
  Created by Yvan / https://Brainy-Bits.com

  This code is in the public domain...
  You can: copy it, use it, modify it, share it or just plain ignore it!
  Thx!

*/

/* taken from https://www.seeedstudio.com/blog/2019/11/21/nrf24l01-getting-started-arduino-guide/ */

// NRF24L01 Module Tutorial - Code for Transmitter using Arduino NANO

//Include needed Libraries at beginning
#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

#define SwitchPin 7 // Arcade switch is connected to Pin 8 on NANO
int SentMessage[1] = {000}; // Used to store value before being sent through the NRF24L01

RF24 radio(9, 10); // NRF24L01 used SPI pins + Pin 9 and 10 on the UNO

const uint64_t pipe = 0x0000EDB15DEE; // Needs to be the same for communicating between 2 NRF24L01

void setup(void) {

  //  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(SwitchPin, INPUT_PULLUP); // Define the arcade switch NANO pin as an Input using Internal Pullups
  digitalWrite(SwitchPin, HIGH); // Set Pin to HIGH at beginning
  const uint64_t pipe = 0xE6E6E6E6E6E6; // Needs to be the same for communicating between 2 NRF24L01
  radio.begin(); // Start the NRF24L01
  radio.openWritingPipe(pipe); // Get NRF24L01 ready to transmit
}

void loop(void) {

  if (digitalRead(SwitchPin) == LOW) { // If Switch is Activated
    SentMessage[0] = 111;
    radio.write(SentMessage, 1); // Send value through NRF24L01
    //    Serial.println("pressed");
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else {
    SentMessage[0] = 000;
    radio.write(SentMessage, 1);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
