int count=0;
bool reverse=false;
byte segments = 0b00000001;
bool sr = false;
long lastm = 0;
int ain=A0;

void setup()
{
  DDRD=0b11111111;
  pinMode(ain,INPUT);
}
void loop()
{
  if (analogRead(0) >= 1000)
  {
    if (millis() - lastm >= ab(analogRead(A1)))
    {
    PORTD = segments;
    lastm = millis();
    if (count >= 7)
    {
     reverse = true;
    }
    if (count <= 0)
    {
      reverse = false;
    }
    if (reverse == false)
    {
      segments = segments << 1;
      count++;
    }
    else
    {
      segments = segments >> 1;
      count--;
    }
  }
  
  }
}
float ab(float in)
{
  if (in < 0) return in * -1;
  else return in;
}
