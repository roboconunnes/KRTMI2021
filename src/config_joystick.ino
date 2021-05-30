void preparejoystick(){
  error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);
  
  if(error == 0){Serial.println("Kontrol Joystick Siap Digunakan");}
  else if(error == 1){ Serial.println("No controller found, check wiring, see readme.txt to enable debug.");}
  else if(error == 2){Serial.println("Controller found but not accepting commands. see readme.txt to enable debug.");}
  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
    Serial.print(ps2x.Analog(1), HEX);

    type = ps2x.readType();
    switch(type){
      case 0:
      Serial.println("Unknown Controller type");
      break;
      case 1:
      Serial.println("DualShock Controller Found");
      break;
      case 2:
      Serial.println("GuitarHero Controller Found");
      break;
     }
}


void joystick(){
  if(error == 1) //skip loop if no controller found
    return; 
  
  if(type == 2){ //Guitar Hero Controller
    ps2x.read_gamepad();          //read controller 
   
    if(ps2x.ButtonPressed(GREEN_FRET))
      Serial.println("Green Fret Pressed");
    if(ps2x.ButtonPressed(RED_FRET))
      Serial.println("Red Fret Pressed");
    if(ps2x.ButtonPressed(YELLOW_FRET))
      Serial.println("Yellow Fret Pressed");
    if(ps2x.ButtonPressed(BLUE_FRET))
      Serial.println("Blue Fret Pressed");
    if(ps2x.ButtonPressed(ORANGE_FRET))
      Serial.println("Orange Fret Pressed"); 

    if(ps2x.ButtonPressed(STAR_POWER))
      Serial.println("Star Power Command");
    
    if(ps2x.Button(UP_STRUM))          //will be TRUE as long as button is pressed
      Serial.println("Up Strum");
    if(ps2x.Button(DOWN_STRUM))
      Serial.println("DOWN Strum");
 
    if(ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");
    
    if(ps2x.Button(ORANGE_FRET)) {     // print stick value IF TRUE
      Serial.print("Wammy Bar Position:");
      Serial.println(ps2x.Analog(WHAMMY_BAR), DEC); 
    } 
  }
  else { //DualShock Controller
    ps2x.read_gamepad(false, vibrate); //read controller and set large motor to spin at 'vibrate' speed

    if(ps2x.Button(PSB_START)){empty = 127; delay(100);} //jika menggunakan joystick kabel
    if(ps2x.Button(PSB_SELECT)){empty = 123; delay(100);} // jika menggunakan joystick wireless
    
    if(ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
      Serial.println("Start is being held");
    if(ps2x.Button(PSB_SELECT))
      Serial.println("Select is being held");      

    if(ps2x.ButtonPressed(PSB_PAD_UP)) {
      maju();
    }

    if(ps2x.ButtonReleased(PSB_PAD_UP)) {
      berhenti();
    }

    if(ps2x.ButtonPressed(PSB_PAD_RIGHT)){
      geserkanan();
    }
    if(ps2x.ButtonReleased(PSB_PAD_RIGHT)) {
      berhenti();
    }
    if(ps2x.ButtonPressed(PSB_PAD_LEFT)){
      geserkiri();
    }
    if(ps2x.ButtonReleased(PSB_PAD_LEFT)) {
      berhenti();
    }
    if(ps2x.ButtonPressed(PSB_PAD_DOWN)){
     mundur();
    }   
    if(ps2x.ButtonReleased(PSB_PAD_DOWN)) {
      berhenti();
    }

    vibrate = ps2x.Analog(PSAB_CROSS);  //this will set the large motor vibrate speed based on how hard you press the blue (X) button
    if (ps2x.NewButtonState()) {        //will be TRUE if any button changes state (on to off, or off to on)
      if(ps2x.Button(PSB_L3))
        Serial.println("L3 pressed");
      if(ps2x.Button(PSB_R3))
        Serial.println("R3 pressed");
      if(ps2x.Button(PSB_L2))
        Serial.println("L2 pressed");
      if(ps2x.Button(PSB_R1)){
        rotasikanan();}
      if(ps2x.ButtonReleased(PSB_R1)) {
        berhenti();}
      if(ps2x.Button(PSB_L1)){
        rotasikiri();}
      if(ps2x.ButtonReleased(PSB_L1)) {
        berhenti();}
        if(ps2x.Button(PSB_R2)){
        pwm = pwm+10;}
      if(ps2x.Button(PSB_L2)){
        pwm = pwm-10;}
      if(ps2x.Button(PSB_TRIANGLE))
        Serial.println("Triangle pressed");        
    }

    if(ps2x.ButtonPressed(PSB_CIRCLE)){
      myservo.write(buka); delay(1000);
      Serial.println("Circle just pressed");
    }               
      
    if(ps2x.ButtonPressed(PSB_CROSS)){             //will be TRUE if button was JUST pressed OR released
      myservo.write(tutup); delay(1000);
      Serial.println("X just changed");
    }
    if(ps2x.ButtonReleased(PSB_SQUARE))              //will be TRUE if button was JUST released
      Serial.println("Square just released");     

    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) { //print stick values if either is TRUE
      Serial.print("Stick Values:");
      Serial.print(ps2x.Analog(PSS_LY), DEC); //Left stick, Y axis. Other options: LX, RY, RX  
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_LX), DEC); 
      Serial.print(",");
      Serial.print(ps2x.Analog(PSS_RY), DEC); 
      Serial.print(",");
      Serial.println(ps2x.Analog(PSS_RX), DEC); 
    }
    if(ps2x.Analog(PSS_LY) == empty && ps2x.Analog(PSS_LX) == empty && ps2x.Button(PSB_L1) == 0 && ps2x.Button(PSB_R1) == 0){
      berhenti();
    }
    if(ps2x.Analog(PSS_LY) < 80 && ps2x.Analog(PSS_LX) == empty){
      maju();
    }
    if(ps2x.Analog(PSS_LY) < 80 && ps2x.Analog(PSS_LX) > 160){
      serongkananmaju();
    }
    if(ps2x.Analog(PSS_LY) == empty && ps2x.Analog(PSS_LX) > 160){
      geserkanan();
    }
    if(ps2x.Analog(PSS_LY) > 160 && ps2x.Analog(PSS_LX) > 160){
      serongkirimundur();
    }
    if(ps2x.Analog(PSS_LY) > 160 && ps2x.Analog(PSS_LX) == empty){
      mundur();
    }
    if(ps2x.Analog(PSS_LY) > 160 && ps2x.Analog(PSS_LX)< 100){
      serongkananmundur();
    }
    if(ps2x.Analog(PSS_LY) == empty && ps2x.Analog(PSS_LX) < 100){
      geserkiri();
    }
    if(ps2x.Analog(PSS_LY) < 100 && ps2x.Analog(PSS_LX) < 100){
      serongkirimaju();
    }
  }
  delay(50);
}
