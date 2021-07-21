#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define red 10
#define yellow 9 
#define green 8 
#define DS 12
#define CK 13
#define OUT 11



String Number[] = {"00000011","10011111","00100101","00001101","10011001","01001001","01000001","00011111","00000001","00001001"};

void Xuat(int D) {
  digitalWrite(DS,D);
  digitalWrite(CK,1);
  delay(0);
  digitalWrite(CK,0);
  delay(0);

}

int NumD1 = 5; // chữ số hàng đơn vị
int NumD2 = 1; // chữ số hàng chục

void setup()
{
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
}

void Do()
{
  NumD1 = 5;
  NumD2 = 1;
  while (NumD2 >= 0)
  {
    for (int i = 7; i>=0;i--)
      Xuat((String(Number[NumD1][i])).toInt());
    for (int i = 7; i>=0;i--)
    {
      Xuat((String(Number[NumD2][i])).toInt());
    }
  
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    lcd.begin(16,2);
    lcd.setCursor(4,0);
    lcd.print("RED LIGHT");
    lcd.setCursor(5,1);
    lcd.print("STOP !!!");
    
    NumD1--;
    delay(950);
    if (NumD1 <0) 
    {
      NumD1 = 9;
    }
    
    if (NumD1 == 9) NumD2--;
  }
  
}

void Xanh()
{
  NumD1 = 2;
  NumD2 = 2;
  while (NumD2 >= 0)
  {
    for (int i = 7; i>=0;i--)
     Xuat((String(Number[NumD1][i])).toInt());
    for (int i = 7; i>=0;i--)
    {
      Xuat((String(Number[NumD2][i])).toInt());
    }
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
    lcd.begin(16,2);
    lcd.setCursor(3,0);
    lcd.print("GREEN LIGHT");
    lcd.setCursor(4,1);
    lcd.print("GO AHEAD");
    
    NumD1--;
    delay(950);
    if (NumD1 <0) 
    {
      NumD1 = 9;
    }
    
    if (NumD1 == 9) NumD2--;
  }
}

void Vang()
{
  NumD1 = 5;
  NumD2 = 0;
  while (NumD2 >= 0)
  {
    for (int i = 7; i>=0;i--)
     Xuat((String(Number[NumD1][i])).toInt());
    for (int i = 7; i>=0;i--)
    {
      Xuat((String(Number[NumD2][i])).toInt());
    }
    digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    digitalWrite(green,LOW);
    lcd.begin(16,2);
    lcd.setCursor(2,0);
    lcd.print("YELLOW LIGHT");
    lcd.setCursor(3,1);
    lcd.print("SLOW DOWN");
    
    NumD1--;
    delay(950);
    if (NumD1 <0) 
    {
      NumD1 = 9;
    }
    
    if (NumD1 == 9) NumD2--;
  }
}

void loop() {
  
  Do();
  Xanh();
  Vang();

  digitalWrite(OUT,1);
  delay(0);
  digitalWrite(OUT,0);
  delay(0);
  
}
