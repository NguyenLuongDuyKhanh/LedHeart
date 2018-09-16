#define latchPin 4
#define clockPin 3
#define dataPin 0
#define music 2

bool buff[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup() 
{     
  
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(music, INPUT);
  TCCR0B |=  _BV(CS02)  ; 
}

int timer = 150;

void _delay(word time = 1) 
{ 
  for (word i = 1; i<=time;i++) 
  {
    delayMicroseconds(timer);
  }
}



void push()
{ 
   digitalWrite(latchPin, LOW);
  for(int i=0;i<32;i++)
  {
    digitalWrite(clockPin,LOW);
    digitalWrite(dataPin,buff[i]);
    digitalWrite(clockPin,HIGH);
  }
   digitalWrite(latchPin, HIGH);
}

void loop() 
{ 
  //Ex1();
  //Ex2();
  //Ex3(); //chuaxong
  Ex4();
}

void Ex1()
{
for(int i=0;i<32;i++)
  {
    buff[i]=0;
  }
  push();
  delay(100);
  for(int i=0;i<32;i++)
  {
    buff[i]=1;
  }
  push();
  delay(100);
}

void Ex2()
{
for(int i=0;i<32;i++)
  {
    buff[i]=0;
  }
  push();
  delay(10);
  for(int i=0;i<32;i++)
  {
    buff[i]=1;
  }
  push();
  delay(10);
}

void Ex3()
{
  for(int z=0;z<32;z++)
  {
      for(int i=0;i<10;i++)
      {
        for(int j=0;j<32;j++)
        {
          if(j<i)
          {
            buff[j-10+z]=0;
          }
          else
          {
            buff[j-10+z]=1;
          }
        }
        push();
      }
      delay(10);
  }
}

void Ex4()
{
  for(int i=0;i<32;i++)
  {
    if(i%2==0)
    buff[i]=0;
    else
    buff[i]=1;
  }
  push();
  
  //delay(1);
}

