#include<SoftwareSerial.h>
SoftwareSerial bt(4,5);

#define in1 13
#define in2 12
#define in3 9
#define in4 8
#define enA 7
#define enB 6

int v;
int sensorKiri = 2;
int sensorKanan = 3;
int hitam = 0;
int putih = 1;
int motorSpeedA = 0;
int motorSpeedB = 0;

void setup(){
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(sensorKiri,INPUT);
  pinMode(sensorKanan,INPUT);

  bt.begin(9600);

}

void maju() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100);
}

void belokKanan() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
}

void belokKiri() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(100);
}

void berhenti() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  delay(100);
}

void mundur() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(100);
}

void loop(){
   int sensorL_Kena = digitalRead(sensorKiri);
  int sensorR_Kena = digitalRead(sensorKanan);
    motorSpeedA = 150;
  motorSpeedB = 150;
  analogWrite(enA, motorSpeedA);
  analogWrite(enB, motorSpeedB);

  if (bt.available()) {
    v = bt.read();
    bt.println(v);

    if(v == 'F'){
      maju();
    }
     if(v == 'L'){
      belokKiri();
    }
    if(v == 'R'){
      belokKanan();
    }
    if(v == 'B'){
      mundur();
    }
  }else{
    if ((sensorL_Kena == hitam) && (sensorR_Kena==hitam)) {
      berhenti();
    }
    if ((sensorL_Kena == hitam) && (sensorR_Kena==putih)) {
      belokKiri();
    }
    if ((sensorL_Kena == putih) && (sensorR_Kena==hitam)) {
      belokKanan();
    }
    if ((sensorL_Kena == putih) && (sensorR_Kena==putih)) {
      maju();
    }
  }
}