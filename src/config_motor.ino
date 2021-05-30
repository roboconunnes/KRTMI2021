void berhenti(){
  analogWrite(M1A, 0);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, 0);
  analogWrite(M3A, 0);
  analogWrite(M3B, 0);
  analogWrite(M4A, 0);
  analogWrite(M4B, 0);
  Serial.println("BERHENTI");
}

void maju(){
  analogWrite(M1A, pwm); //analogWrite(pin yang dituju, nilai)
  analogWrite(M1B, 0);
  analogWrite(M2A, pwm);
  analogWrite(M2B, 0);
  analogWrite(M3A, pwm);
  analogWrite(M3B, 0);
  analogWrite(M4A, pwm);
  analogWrite(M4B, 0);
  Serial.println("MAJU");
}

void mundur(){
  analogWrite(M1A, 0);
  analogWrite(M1B, pwm);
  analogWrite(M2A, 0);
  analogWrite(M2B, pwm);
  analogWrite(M3A, 0);
  analogWrite(M3B, pwm);
  analogWrite(M4A, 0);
  analogWrite(M4B, pwm);
  Serial.println("MUNDUR");
}

void geserkiri(){ 
  analogWrite(M1A, pwm);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, pwm);
  analogWrite(M3A, pwm);
  analogWrite(M3B, 0);
  analogWrite(M4A, 0);
  analogWrite(M4B, pwm);
  Serial.println("GESER KIRI");
}

void geserkanan(){
  analogWrite(M1A, 0);
  analogWrite(M1B, pwm);
  analogWrite(M2A, pwm);
  analogWrite(M2B, 0);
  analogWrite(M3A, 0);
  analogWrite(M3B, pwm);
  analogWrite(M4A, pwm);
  analogWrite(M4B, 0);
  Serial.println("GESER KANAN");
}

void rotasikiri(){     //KETIKA ROBOT MELAKUKAN ROTASI KANAN MAKA M2A(MAJU) DAN M2B(MUNDUR) BERNILAI TRUE
  analogWrite(M1A, pwm);
  analogWrite(M1B, 0);
  analogWrite(M2A, pwm);  
  analogWrite(M2B, 0);
  analogWrite(M3A, 0);
  analogWrite(M3B, pwm);
  analogWrite(M4A, 0);
  analogWrite(M4B, pwm);
  Serial.println("ROTASI KIRI");
}

void rotasikanan(){    //KETIKA ROBOT MELAKUKAN ROTASI KANAN MAKA M1A(MAJU) DAN M1B(MUNDUR) BERNILAI TRUE
  analogWrite(M1A, 0);  
  analogWrite(M1B, pwm);
  analogWrite(M2A, 0);
  analogWrite(M2B, pwm);
  analogWrite(M3A, pwm);
  analogWrite(M3B, 0);
  analogWrite(M4A, pwm);
  analogWrite(M4B, 0);
  Serial.println("ROTASI KANAN");
}

void corneringMajuKanan(){//KETIKA ROBOT MELAKUKAN CORNERING MAJU KANAN MAKA M2A BERNILAI TRUE, karena bergerak ke sisi kanan maka sisi kiri yang bernilai true(M2) && maju bernilai true(A)
  analogWrite(M1A, 0);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0); 
  analogWrite(M2B, 0);
  analogWrite(M3A, pwm);
  analogWrite(M3B, 0);
  analogWrite(M4A, pwm);
  analogWrite(M4B, 0);
  Serial.println("CORNERING MAJU KANAN");
}

void corneringMajuKiri(){
  analogWrite(M1A, pwm);
  analogWrite(M1B, 0);
  analogWrite(M2A, pwm);
  analogWrite(M2B, 0);
  analogWrite(M3A, 0);
  analogWrite(M3B, 0);
  analogWrite(M4A, 0);
  analogWrite(M4B, 0);
  Serial.println("CORNERING MAJU KIRI");
}

void corneringMundurKanan(){
  analogWrite(M1A, 0);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, 0);
  analogWrite(M3A, 0);
  analogWrite(M3B, pwm);
  analogWrite(M4A, 0);
  analogWrite(M4B, pwm);
  Serial.println("CORNERING MUNDUR KANAN");
}

void corneringMundurKiri(){
  analogWrite(M1A, 0);
  analogWrite(M1B, pwm);
  analogWrite(M2A, 0);
  analogWrite(M2B, pwm);
  analogWrite(M3A, 0);
  analogWrite(M3B, 0);
  analogWrite(M4A, 0);
  analogWrite(M4B, 0);
  Serial.println("CORNERING MUNDUR KIRI");
}

void serongkirimaju(){
  analogWrite(M1A, pwm);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, 0);
  analogWrite(M3A, pwm);
  analogWrite(M3B, 0);
  analogWrite(M4A, 0);
  analogWrite(M4B, 0);
  Serial.println(" ");
}

void serongkananmaju(){
  analogWrite(M1A, 0);
  analogWrite(M1B, 0);
  analogWrite(M2A, pwm);
  analogWrite(M2B, 0);
  analogWrite(M3A, 0);
  analogWrite(M3B, 0);
  analogWrite(M4A, pwm);
  analogWrite(M4B, 0);
  Serial.println(" ");
}

void serongkirimundur(){
  analogWrite(M1A, 0);
  analogWrite(M1B, pwm);
  analogWrite(M2A, 0);
  analogWrite(M2B, 0);
  analogWrite(M3A, 0);
  analogWrite(M3B, pwm);
  analogWrite(M4A, 0);
  analogWrite(M4B, 0);
  Serial.println(" ");
}

void serongkananmundur(){
  analogWrite(M1A, 0);
  analogWrite(M1B, 0);
  analogWrite(M2A, 0);
  analogWrite(M2B, pwm);
  analogWrite(M3A, 0);
  analogWrite(M3B, 0);
  analogWrite(M4A, 0);
  analogWrite(M4B, pwm);
  Serial.println(" ");
}