#include <ESP8266WiFi.h>
#include <Keypad.h>
#include <ESP8266HTTPClient.h>
#include "AnotherIFTTTWebhook.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {D0, D1, D2, D3}; 
byte colPins[COLS] = {D4, D5, D6, D7}; 

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int ledPin = D8;
const char* ssid="Joshua";
const char* password = "Cacajo33";
#define IFTTT_Key "lqIz3vWs8R4XWIyOmZlSRLjrHXMvdDjZ-bmXYYRAIVw"
#define IFTTT_Event "chores"
void setup() {
  
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);

  Serial.begin(9600);
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }

  digitalWrite( ledPin , HIGH);
  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

}
void loop(){
  char key = keypad.getKey();
    // just print the pressed key
   if (key){
    Serial.println(key);
  } 
  
  // this checkes if 4 is pressed, then do something. Here  we print the text but you can control something.
  if (key =='1'){
    Serial.println("Key 1 is pressed");
    send_webhook(IFTTT_Event,IFTTT_Key,"TAKE OUT THE TRASH","value 2","value 3"); 
  }

    if (key =='2'){
    Serial.println("Key 2 is pressed");
    send_webhook(IFTTT_Event,IFTTT_Key,"TAKE OUT THE TRASH BINS","value 2","value 3"); 
  }

    if (key =='3'){
    Serial.println("Key 3 is pressed");
    send_webhook(IFTTT_Event,IFTTT_Key,"PUT WATER ON","value 2","value 3"); 
  }

    if (key =='4'){
    Serial.println("Key 4 is pressed");
    send_webhook(IFTTT_Event,IFTTT_Key,"REFILL THE WATERS","value 2","value 3"); 
  }

    if (key =='5'){
    Serial.println("Key 5 is pressed");
    send_webhook(IFTTT_Event,IFTTT_Key,"DELIVER FOOD TO PAPA","value 2","value 3"); 
  }

  if (key =='6'){
    Serial.println("Key 6 is pressed");
    send_webhook(IFTTT_Event,IFTTT_Key,"JOSH TAKE OFF YOUR HEADPHONES","value 2","value 3"); 
  }

  if (key =='7'){
    Serial.println("Key 7 is pressed");
    send_webhook(IFTTT_Event,IFTTT_Key,"TAKE OUT THE STUFF FROM THE CAR","value 2","value 3"); 
  }
  
}
