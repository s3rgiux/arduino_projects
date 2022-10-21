int LOW_PHASE1 = 2;
int HIGH_PHASE1 = 3;

int LOW_PHASE2 = 4;
int HIGH_PHASE2 = 5;

int LOW_PHASE3 = 6;
int HIGH_PHASE3 = 7;

void allZero();

void step1();
void step2();
void step3();
void step4();
void step5();
void step6();
void step7();
void step8();
void step_phase(int number);

int stp = 1;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LOW_PHASE1, OUTPUT);
  pinMode(HIGH_PHASE1, OUTPUT);
  pinMode(LOW_PHASE2, OUTPUT);
  pinMode(HIGH_PHASE2, OUTPUT);
  pinMode(LOW_PHASE3, OUTPUT);
  pinMode(HIGH_PHASE3, OUTPUT);

  delay(1000);

  digitalWrite(LOW_PHASE1, LOW);
  digitalWrite(HIGH_PHASE1, LOW);
  digitalWrite(LOW_PHASE2, LOW);
  digitalWrite(HIGH_PHASE2, LOW);
  digitalWrite(LOW_PHASE3, LOW);
  digitalWrite(HIGH_PHASE3, LOW);
  
}

// the loop function runs over and over again forever
void loop() {
  step_phase(stp);
  delay(100);
  stp++;
}

void step_phase(int number){
  switch(number){
    case 1:
      step1();
    break;

    case 2:
      step2();
    break;
    
    case 3:
      step3();
    break;

    case 4:
      step4();
    break;

    case 5:
      step5();
    break;

    case 6:
      step6();
    break;
  }
}

void step1(){
  digitalWrite(LOW_PHASE1, LOW);
  digitalWrite(HIGH_PHASE1, HIGH);
  digitalWrite(LOW_PHASE2, HIGH);
  digitalWrite(HIGH_PHASE2, LOW);
  digitalWrite(LOW_PHASE3, LOW);
  digitalWrite(HIGH_PHASE3, LOW);
}


void step2(){
  digitalWrite(LOW_PHASE1, LOW);
  digitalWrite(HIGH_PHASE1, HIGH);
  digitalWrite(LOW_PHASE2, LOW);
  digitalWrite(HIGH_PHASE2, LOW);
  digitalWrite(LOW_PHASE3, HIGH);
  digitalWrite(HIGH_PHASE3, LOW);
}

void step3(){
  digitalWrite(LOW_PHASE1, LOW);
  digitalWrite(HIGH_PHASE1, LOW);
  digitalWrite(LOW_PHASE2, LOW);
  digitalWrite(HIGH_PHASE2, HIGH);
  digitalWrite(LOW_PHASE3, HIGH);
  digitalWrite(HIGH_PHASE3, LOW);
}


void step4(){
  digitalWrite(LOW_PHASE1, HIGH);
  digitalWrite(HIGH_PHASE1, LOW);
  digitalWrite(LOW_PHASE2, LOW);
  digitalWrite(HIGH_PHASE2, HIGH);
  digitalWrite(LOW_PHASE3, LOW);
  digitalWrite(HIGH_PHASE3, LOW);
}

void step5(){
  digitalWrite(LOW_PHASE1, HIGH);
  digitalWrite(HIGH_PHASE1, LOW);
  digitalWrite(LOW_PHASE2, LOW);
  digitalWrite(HIGH_PHASE2, LOW);
  digitalWrite(LOW_PHASE3, LOW);
  digitalWrite(HIGH_PHASE3, HIGH);
}

void step6(){
  digitalWrite(LOW_PHASE1, LOW);
  digitalWrite(HIGH_PHASE1, LOW);
  digitalWrite(LOW_PHASE2, HIGH);
  digitalWrite(HIGH_PHASE2, LOW);
  digitalWrite(LOW_PHASE3, LOW);
  digitalWrite(HIGH_PHASE3, HIGH);
}

void step7(){
  digitalWrite(LOW_PHASE1, LOW);
  digitalWrite(HIGH_PHASE1, HIGH);
  digitalWrite(LOW_PHASE2, HIGH);
  digitalWrite(HIGH_PHASE2, LOW);
  digitalWrite(LOW_PHASE3, LOW);
  digitalWrite(HIGH_PHASE3, LOW);
}

void allZero(){
  digitalWrite(LOW_PHASE1, LOW);
  digitalWrite(HIGH_PHASE1, LOW);
  digitalWrite(LOW_PHASE2, LOW);
  digitalWrite(HIGH_PHASE2, LOW);
  digitalWrite(LOW_PHASE3, LOW);
  digitalWrite(HIGH_PHASE3, LOW);
}
