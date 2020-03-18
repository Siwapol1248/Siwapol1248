#define LED0 9
#define LED1 8
#define INT 3

int toggle=1;
int c1=0;

void setup()
{
  pinMode(LED0,OUTPUT);
  pinMode(LED1,OUTPUT);
  pinMode(INT,INPUT);
  attachInterrupt(digitalPinToInterrupt(INT),
                  ISR_Callback, RISING);
}

void loop()
{
  if(c1==0){
  digitalWrite(LED0,HIGH);
    delay(500);
  digitalWrite(LED0,LOW);
    delay(500);
  }
  if(c1==1){
  digitalWrite(LED0,HIGH);
    delay(1000);
  digitalWrite(LED0,LOW);
    delay(1000);
  }
  if(c1==2){
  digitalWrite(LED0,HIGH);
    delay(1500);
  digitalWrite(LED0,LOW);
    delay(1500);
  }
  
}

void ISR_Callback()
{
  c1++;
  if(c1>2){
    c1=0;
  }
}
