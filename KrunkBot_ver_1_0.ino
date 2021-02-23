/*
==========================================
Title:  Arduino coding best practices 
author: GhostOverrider
Date:   23 Feb 2021

Note:   The below trashy code has not been updated 
        as yet.
==========================================
*/
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// this constant won't change:
const int  button1Pin = 9;    // the pin that the pushbutton is attached to
const int  button2Pin = 8;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int button1PushCounter = 0;   // counter for the number of button presses
int button2PushCounter = 0;   // counter for the number of button presses
int button1State = 0;         // current state of the button
int button2State = 0;         // current state of the button
int lastButton1State = 0;     // previous state of the button
int lastButton2State = 0;     // previous state of the button

void setup() {
  
    // set up the LCD's number of columns and rows: 
  //
  //lcd.begin(0, 1);
  // Print a message to the LCD.
  lcd.begin(16, 2);
  lcd.print("KRUNKBOT 1.0");
  
  // initialize the button pin as a input:
  pinMode(button1Pin, INPUT);
  
    // initialize the button pin as a input:
  pinMode(button2Pin, INPUT);
  
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  

  
  pushOne();
  pushTwo();
  disp();

}

void pushOne(){

  // read the pushbutton input pin:
  button1State = digitalRead(button1Pin);

  // compare the buttonState to its previous state
  if (button1State != lastButton1State) {
    // if the state has changed, increment the counter
    if (button1State == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      button1PushCounter++;
      Serial.println("button 1 on");
      Serial.print("number of button pushes:  ");
      Serial.println(button1PushCounter);
      lcd.setCursor(0, 1);
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  
  lastButton1State = button1State;
  
  if (button1PushCounter >= 4) {
       button1PushCounter = 0;
    }
  
  /*if (button1PushCounter==1){
  
    lcd.print("The number is ");
  }
  else{
  lcd.print(button1PushCounter);
  }
  */
   lcd.setCursor(0, 1);
  
  switch (button1PushCounter) {
     case 1:
       
        lcd.print("ICE TEA");
        //lcd.setCursor(0, 1);
        if (button2PushCounter==1)
        {lcd.print("I-T");}
        if (button2PushCounter >= 1) {
       button2PushCounter = 0;
       

    }
        break;
     case 2:
    
       // lcd.setCursor(0, 1);
       //lcd.setCursor(6, 1); 
       
       //lcd.setCursor(0, 1);
        lcd.print("RUM     ");
        if (button2PushCounter==1)
        {lcd.print("RM");}
        if (button2PushCounter >= 1) {
       button2PushCounter = 0;
        }
        break;
     case 3:
      //  lcd.setCursor(0, 1);
        lcd.print("VODKA   ");
                if (button2PushCounter==1)
        {lcd.print("VD");}
        if (button2PushCounter >= 1) {
       button2PushCounter = 0;
        }
        break;
     case 4:
        lcd.setCursor(0, 1);
        lcd.print("end");
        break;
  }
  
    //if ()
  
  // turns on the LED every four button pushes by
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of
  // the division of two numbers:
 /* if (button1PushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }*/
}
  
  void pushTwo(){

  // read the pushbutton input pin:
  button2State = digitalRead(button2Pin);

  // compare the buttonState to its previous state
  if (button2State != lastButton2State) {
    // if the state has changed, increment the counter
    if (button2State == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
      button2PushCounter++;
      //lcd.setCursor(0, 1);
      Serial.println("button 2 on");
      Serial.print("number of button pushes:  ");
      Serial.println(button2PushCounter);
    } else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state,
  //for next time through the loop
  lastButton2State = button2State;


  // turns on the LED every four button pushes by
  // checking the modulo of the button push counter.
  // the modulo function gives you the remainder of
  // the division of two numbers:
  if (button2PushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  }
  
  void disp(){
  
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis()/1000);
  }

