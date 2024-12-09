## آزمایش 1-7:
### چرخش آرمیچر به صورت ساعتگرد و پادساعتگرد  
### هدف:
#### آشنایی با موتور درایور و تنظیم آن برای آرمیچر
---
## ابزار:

|ردیف|نام|تعداد|
|----|----|----|
|1|سیم|8|
|2|آرمیچر|1|
|3|موتور درایور|1|
|4|منبع تغذیه 12 ولتی|1|
|5|ریزپردازنده|1|
---
### شرح آزمایش:
#### با کمک و تنظیم پایه های موتوردرایور می توان چرخش آرمیچر را تنظیم کرد، به این صورت که دو پایه out 1,2 موتور درایور را به دو پایه آرمیچر وصل کرده و پایه 12v را به منبع تغذیه،
#### و پایه GND را هم به زمین منبع تغذیه و هم زمین برد آردوینو متصل می کنیم،سه پایه ی دیگر هم طبق کد به پایه های 8،9،10 برد آردوینو وصل میکنیم.
---
### شماتیک و تصویر مدار:
![](/media/shemaarmicher.jpg)
![](/media/armature.jpg)
---
### کد برنامه:
```cpp
int val = 0;
void setup() {
  pinMode(8 , OUTPUT);
  pinMode(9 , OUTPUT);
  pinMode(10 , OUTPUT);
}

void loop() {
  val = analogRead(A0);

  int MAP = map(val, 0, 1024.0, 0, 256);

  //full speed forward
  digitalWrite(8 , HIGH);
  digitalWrite(9 , LOW);
  digitalWrite(10 , HIGH);
  delay(1000);

  //full speed backward
  digitalWrite(8 , LOW);
  digitalWrite(9 , HIGH);
  digitalWrite(10 , HIGH);
  delay(1000);

  //0_100 forward
  for (MAP = 0; MAP < 256; MAP++)
  {
    digitalWrite(8 , HIGH);
    digitalWrite(9 , LOW);
    analogWrite(10 , MAP);
  }
  for (MAP = 0; MAP < 256; MAP++)
  {
    //0_100 backward
    digitalWrite(8 , LOW);
    digitalWrite(9 , HIGH);
    analogWrite(10 , MAP);
  }

}```

