byte led[]={7,6,5,4,3,2,1,0};
byte n;
int i;
void setup()
{
    n = 7;

     for(i = 0; i <= n; i++)
     {
      pinMode(led[i],OUTPUT);
      digitalWrite(led[i],LOW);
     }
  
}

void loop()
{
  for(i = 0; i <= n; i++)
  {
    digitalWrite(led[i], HIGH);
    delay(500);
  }
  alloff();

  for(i; i >= 0; i--)
  {
    digitalWrite(led[i], HIGH);
    delay(500);
  }
  alloff();
  
}

void alloff()
{
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], LOW);
  digitalWrite(led[5], LOW);
  digitalWrite(led[6], LOW);
  digitalWrite(led[7], LOW);
}

