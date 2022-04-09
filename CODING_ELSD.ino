#include<LiquidCrystal.h>
int ir1=2,ir2=4,ir3=3,ir4=5,ir5=6,ir6=7,ledpin1=11,ledpin2=8,relay1=50,relay2=51,acpin1=13,acpin2=10;
int count=0,flag1=0,flag2=0,flag3=0,flag4=0,i;
float temp1,temp2,val1,val2;
int temppin1=A0,temppin2=A1,ldrpin1=A2,ldrpin2=A4;

  
  const int rs=28,en=29,d4=30,d5=31,d6=32,d7=33;
  LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
  
void IN()
{
 
  count++;
  lcd.setCursor(4,0);
  lcd.print(count);
  Serial.println(count);
  delay(2000); 
}


void OUT()
{
  
  count--;
  lcd.setCursor(4,0);
  lcd.print(count);
  Serial.println(count);
  delay(2000);
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(ir3,INPUT);
  pinMode(ir4,INPUT);
  pinMode(ir5,INPUT);
  pinMode(ir6,INPUT);
  pinMode(ledpin1,OUTPUT);
  pinMode(ledpin2,OUTPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(acpin1,OUTPUT);
  pinMode(acpin2,OUTPUT);
  pinMode(temppin1,INPUT);
  pinMode(temppin2,INPUT);
  pinMode(ldrpin1,INPUT);
  pinMode(ldrpin2,INPUT);
  lcd.print("No:");
  lcd.setCursor(4,0);
  lcd.print(count);
  lcd.setCursor(6,0);
  lcd.print("TEMP1");
  lcd.setCursor(1,1);
  lcd.print("TEMP2");
 
}
void loop()
{
 
   if(digitalRead(ir1)&&flag2==0)
   {
      flag1 = 1;
   }
   if(flag1==1&&digitalRead(ir3))
   {
    IN();
    flag1 = 0;
   }
   if(digitalRead(ir3) &&flag1==0)
   {
    flag2 = 1;
   }
   if(flag2==1 && digitalRead(ir1))
   {
    OUT();
    flag2 = 0;
   }


    if(digitalRead(ir2) && flag3==0)
   {
      flag3 = 1;
   }
   if(flag3==1 && digitalRead(ir4))
   {
    IN();
    flag3 = 0;
   }
   if(digitalRead(ir4)&&flag3==0)
   {
    flag4 = 1;
   }
   if(flag4 == 1 && digitalRead(ir2))
   {
    OUT();
    flag4=0;
   }
  
  if(count>0)
  {
    int ldrstatus1,ldrstatus2;
    
      if(digitalRead(ir5))
      {
        ldrstatus1=analogRead(ldrpin1);
        if(ldrstatus1<=307)
        {
          analogWrite(ledpin1,255 - (ldrstatus1)/4);
        }
        else
        {
          digitalWrite(ledpin1,LOW);
        }
        val1=analogRead(temppin1);
        temp1=temppin1/2.048;
        Serial.println(temp1);
        if(temp1<5)
        {
          digitalWrite(acpin1,LOW);
          digitalWrite(relay1,HIGH);
        }
        else if(temp1<25)
        {
          digitalWrite(acpin1,LOW);
          digitalWrite(relay1,HIGH);
        }
        else
        {
          digitalWrite(acpin1,HIGH);
          digitalWrite(relay1,LOW);
        }
      }
       else
       {
          digitalWrite(ledpin1,LOW);
          digitalWrite(acpin1,LOW);
          digitalWrite(relay1,HIGH);
       }


      if(digitalRead(ir6))
      {
        ldrstatus2=analogRead(ldrpin2);
        if(ldrstatus2<=307)
        {
          analogWrite(ledpin2,255-(ldrstatus2)/4);
        }
        else
        {
          digitalWrite(ledpin2,LOW);
        }
        val2=analogRead(temppin2);
        temp2=temppin2/2.048;
        Serial.println(temp2);
        if(temp2<5)
        {
          digitalWrite(acpin2,LOW);
          digitalWrite(relay2,HIGH);
        }
        else if(temp2<25)
        {
          digitalWrite(acpin2,LOW);
          digitalWrite(relay2,HIGH);
        }
        else
        {
          digitalWrite(acpin2,HIGH);
          digitalWrite(relay2,LOW);
        }
      }
       else
       {
          digitalWrite(ledpin2,LOW);
          digitalWrite(acpin2,LOW);
          digitalWrite(relay2,HIGH);
       }
    }
    
     lcd.setCursor(12,0);
     lcd.print(temp1);
     lcd.setCursor(7,1);
     lcd.print(temp2);
  }


