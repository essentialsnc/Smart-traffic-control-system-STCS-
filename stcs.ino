int sensorA = 2;
int sensorB = 3;
int sensorC = 4;
int sensorD = 5;

int lightD = 10;
int lightA = 7;
int lightB = 8;
int lightC = 9;


int counterA = 0;
int counterD = 0;

void setup() {
  pinMode(sensorA, OUTPUT);
  pinMode(sensorB, OUTPUT);
  pinMode(sensorC, OUTPUT);
  pinMode(sensorD, OUTPUT);

}

void loop() {
  if( digitalRead(sensorA)||digitalRead(sensorB) || digitalRead(sensorC) || digitalRead(sensorD)){
    checkLights();
  }
  delay(2000);
}

void checkLights(){
  if( digitalRead(sensorA) || digitalRead(sensorC)){
      digitalWrite(lightA, HIGH);   
      digitalWrite(lightC, HIGH);
      digitalWrite(lightB, LOW);
      digitalWrite(lightD, LOW);
      counterA++;
            
  }

  else if( digitalRead(sensorB) || digitalRead(sensorD)){
      digitalWrite(lightB, HIGH);   
      digitalWrite(lightD, HIGH);
      digitalWrite(lightA, LOW);
      digitalWrite(lightC, LOW);
      counterD++;
  }

   if( digitalRead(sensorA)||digitalRead(sensorC) && digitalRead(sensorB) || digitalRead(sensorD)){

    if(counterA > 60000){
      digitalWrite(lightB, HIGH);   
      digitalWrite(lightD, HIGH);
      digitalWrite(lightA, LOW);
      digitalWrite(lightC, LOW);
      counterA = 0;
    }

    else if(counterD > 60000){
      digitalWrite(lightA, HIGH);   
      digitalWrite(lightC, HIGH);
      digitalWrite(lightB, LOW);
      digitalWrite(lightD, LOW);
      counterD = 0;
    }
    
    }
 

 
  
}
