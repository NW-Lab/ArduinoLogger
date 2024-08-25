#define TimeSpan 10000
#define ADRes 10
#define ADVOLT 5
#define ADMAX 1023; //for 10bit
bool enableA0=false;
bool enableA1=false;
bool enableA2=false;
bool enableA3=false;
bool enableA4=false;
bool enableA5=false;
bool enableD2=false;
bool enableD3=false;
bool enableCurrent=false;
float DATAtoV(int data){
  return (float)(ADVOLT*data)/ADMAX;
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  analogReadResolution(ADRes);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT_PULLUP); //SELECT D2
  pinMode(5,INPUT_PULLUP); //SELECT D3
  pinMode(6,INPUT_PULLUP); //SELECT A5
  pinMode(7,INPUT_PULLUP); //SELECT A4
  pinMode(8,INPUT_PULLUP); //SELECT A3
  pinMode(9,INPUT_PULLUP); //SELECT A2
  pinMode(10,INPUT_PULLUP); //SELECT A1
  pinMode(11,INPUT_PULLUP); //SELECT A0
  pinMode(12,INPUT_PULLUP); //SELECT Current
  pinMode(13,OUTPUT);//L
  if(digitalRead(12))enableA0=true;
  if(digitalRead(11))enableA1=true;
  if(digitalRead(10))enableA2=true;
  if(digitalRead(9))enableA3=true;
  if(digitalRead(8))enableA4=true;
  if(digitalRead(7))enableA5=true;
  if(digitalRead(6))enableD3=true;
  if(digitalRead(5))enableD2=true;

  Serial.print("mills,count,");
  if(enableA0)Serial.print("A0_Low,A0_High,");
  if(enableA1)Serial.print("A1_Low,A1_High,");
  if(enableA2)Serial.print("A2_Low,A2_High,");
  if(enableA3)Serial.print("A3_Low,A3_High,");
  if(enableA4)Serial.print("A4_Low,A4_High,");
  if(enableA5)Serial.print("A5_Low,A5_High,");
  if(enableD2)Serial.print("D2_Low,D2_High,");
  if(enableD3)Serial.print("D3_Low,D3_High");
  Serial.println("");
}

void loop() {
  static uint16_t count=0; 
  static int A0_High=0,A0_Low=ADMAX;
  static int A1_High=0,A1_Low=ADMAX;
  static int A2_High=0,A2_Low=ADMAX;
  static int A3_High=0,A3_Low=ADMAX;
  static int A4_High=0,A4_Low=ADMAX;
  static int A5_High=0,A5_Low=ADMAX;
  static bool D2_High=false,D2_Low=false;
  static bool D3_High=false,D3_Low=false;
  unsigned long m=millis()+TimeSpan;
  if(millis()>m){
    Serial.print(m);
    m=m+TimeSpan;
    Serial.print(",");
    Serial.print(count);
    count=0;
    Serial.print(",");
    if(enableA0){
      Serial.print(A0_Low);
      Serial.print(",");
      Serial.print(A0_High);
      Serial.print(",");
      A0_Low=32000;
      A0_High=0;
    }
    if(enableA0){
      Serial.print(A0_Low);
      Serial.print(",");
      Serial.print(A0_High);
      Serial.print(",");
      A0_Low=32000;
      A0_High=0;
    }
    if(enableA1){
      Serial.print(A1_Low);
      Serial.print(",");
      Serial.print(A1_High);
      Serial.print(",");
      A1_Low=32000;
      A1_High=0;
    }
    if(enableA2){
      Serial.print(A2_Low);
      Serial.print(",");
      Serial.print(A2_High);
      Serial.print(",");
      A2_Low=32000;
      A2_High=0;
    }
    if(enableA3){
      Serial.print(A3_Low);
      Serial.print(",");
      Serial.print(A3_High);
      Serial.print(",");
      A3_Low=32000;
      A3_High=0;
    }
    if(enableA4){
      Serial.print(A4_Low);
      Serial.print(",");
      Serial.print(A4_High);
      Serial.print(",");
      A4_Low=32000;
      A4_High=0;
    }
    if(enableA5){
      Serial.print(A5_Low);
      Serial.print(",");
      Serial.print(A5_High);
      Serial.print(",");
      A5_Low=32000;
      A5_High=0;
    }
    if(enableD2){
      if(D2_Low)Serial.print("1,");
      else Serial.print("0,");
      if(D2_High)Serial.print("1,");
      else Serial.print("0,");
      D2_High=false;
      D2_Low=false;
    }
    if(enableD3){
      if(D3_Low)Serial.print("1,");
      else Serial.print("0,");
      if(D3_High)Serial.print("1,");
      else Serial.print("0,");
      D3_High=false;
      D3_Low=false;
    }
    Serial.println("");
  }
// Data Read
  if(enableA0){
    int val=analogRead(A0);
    if(val>A0_High)A0_High=val;
    if(val<A0_Low)A0_Low=val;
  }
  if(enableA1){
    int val=analogRead(A1);
    if(val>A1_High)A1_High=val;
    if(val<A1_Low)A1_Low=val;
  }
  if(enableA2){
    int val=analogRead(A2);
    if(val>A2_High)A2_High=val;
    if(val<A2_Low)A2_Low=val;
  }
  if(enableA3){
    int val=analogRead(A3);
    if(val>A3_High)A3_High=val;
    if(val<A3_Low)A3_Low=val;
  }
  if(enableA4){
    int val=analogRead(A4);
    if(val>A4_High)A4_High=val;
    if(val<A4_Low)A4_Low=val;
  }
  if(enableA5){
    int val=analogRead(A5);
    if(val>A5_High)A0_High=val;
    if(val<A5_Low)A0_Low=val;
  }
  if(enableD2){
    if(digitalRead(2))D2_High=true;
    else D2_Low=true;
  }
  if(enableD3){
    if(digitalRead(3))D3_High=true;
    else D3_Low=true;
  }
  count++;
}
