#include <PS2X_lib.h>  //for v1.6

#define PS2_DAT      14  //13  //14    
#define PS2_CMD      15  //11  //15
#define PS2_SEL      16  //10  //16
#define PS2_CLK      17  //12  //17
#include <Servo.h>

//#define pressures   true
#define pressures   false
//#define rumble      true
#define rumble      false

PS2X ps2x; // create PS2 Controller Class

Servo myservo;

int tutup = 180;
int buka = 0;
int empty = 127;
int error = 0;
byte type = 0;
byte vibrate = 0;

//PIN MOTOR
int M1A = 2;  
int M1B = 3;  
int M2A = 4;  
int M2B = 5;  
int M3A = 7;
int M3B = 6; 
int M4A = 8;
int M4B = 9; 

//PWM: kecepatan motor
int pwm = 150;

void setup(){
  myservo.attach(26);
  Serial.begin(9600);
  
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);

  pinMode(M3A, OUTPUT);
  pinMode(M3B, OUTPUT);

  pinMode(M4A, OUTPUT);
  pinMode(M4B, OUTPUT);

  preparejoystick();
  delay(300);  //added delay to give wireless ps2 module some time to startup, before configuring it
}

void loop() {  
  joystick(); 
   
//  maju(); delay(2000); 
//  berhenti(); delay(500);
//  mundur();delay(2000);
//  berhenti(); delay(500);
//  rotasikiri();delay(2000);
//  berhenti(); delay(500);
//  rotasikanan();delay(2000);
//  berhenti(); delay(500);
}
