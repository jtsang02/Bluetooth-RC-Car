int M_A1 = 2; //motor a = +; in1
int M_A2 = 3; //motor a = -; in2
int S_A = 10;  //speed motor a; enA

int M_B1 = 4; //motor b = -; in3
int M_B2 = 5; //motor b = +; in4
int S_B = 9;  //speed motor b; enB
char val;

void setup(){
  
  pinMode(M_B1, OUTPUT);
  pinMode(M_B2, OUTPUT);
  pinMode(M_A1, OUTPUT);
  pinMode(M_A2, OUTPUT);
  pinMode(S_B, OUTPUT);
  pinMode(S_A, OUTPUT);
  
  analogWrite(S_A, 150);
  analogWrite(S_B, 150); 

  Serial.begin(9600);
}

void loop(){  
  
  while (Serial.available() > 0){
    val = Serial.read();
    Serial.println(val);
  }

  if (val == 'F') // Forward
    fwd();
    
  else if (val == 'B') // Backward
    reverse();
      
  else if (val == 'L') //Left
    spinL();
    
  else if (val == 'R') //Right
    spinR(); 
      
  else if(val == 'G') //Forward Left
    left();
    
  else if(val == 'I') //Forward Right
    right();
    
  else if(val == 'H') //Backward Left
    reverseL();
             
  else if(val == 'J') //Backward Right
    reverseR();
    
  else if (val == 'S') //Stop
    Stop();
    
}
//---------------------------------------------------//
void fwd(){
  analogWrite(S_A, 150);
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW); 
  delay(20); 
}

void reverse(){
  analogWrite(S_A, 150);
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH); 
  delay(20); 
}

void left(){
  analogWrite(S_A, 200); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void right(){
  analogWrite(S_B, 200);
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void fwdL(){ //need more power
  analogWrite(S_A, 150); 
  analogWrite(S_B, 100); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void fwdR(){ //need more power
  analogWrite(S_B, 100);
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void spinL(){
  analogWrite(S_A, 150); 
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
  delay(20);
}

void spinR(){
  analogWrite(S_B, 150);
  analogWrite(S_B, 150); 
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void reverseL(){
  analogWrite(S_B, 200); 
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
  delay(20);
}

void reverseR(){
  analogWrite(S_A, 200);
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
  delay(20);
}

void Stop(){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
  delay(20);
}