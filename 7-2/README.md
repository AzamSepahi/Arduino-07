## آزمایش 2-7:
### دماسنج lm35
### هدف:
#### آشنایی با دماسنج lm35 و روشن و خاموش شدن LED با توجه به دمای آن 
---
## ابزار:

|ردیف|نام|تعداد|
|----|----|----|
|1|سیم|6|
|2|lm35|1|
|3|مقاومت|1|
|4|برد بورد|1|
|5|ریزپردازنده|1|
|6|LED|1|
---
### شرح آزمایش:
#### عملکرد سنسور را با توجه به روشن شدن LED مورد آزمایش قرار می دهیم،به این صورت که از سمت تخت سنسور پایه سمت راست را به 5v،
#### پایه وسط را به پایه A0،پایه سمت راست را به پایه زمین متصل میکنیم،با لمس کردن سنسور و منتقل کردن گرمای بدن خود مشاهده می کنیم که 
#### دما در سریال مانیتور دارد افزایش می یابد و سپس بعد از میزان مد نظر LED روشن می شود و با کاهش دما خاموش می شود.
---
### شماتیک و تصویر مدار :
![](/media/shemalm35.jpg)
![](/media/lm.jpg)

### عملکرد مدار:
![](/media/buzzergif.gif)
---

### کد برنامه :
```cpp
const int lm35Pin = A0;
int led = 9;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(lm35Pin);
  float voltage = sensorValue * (5.0 / 1024.0);
  float tempC = voltage * 100;
  Serial.print("temperature:");
  Serial.print(tempC);
  Serial.println("*C");
  delay(1000);
  if (tempC > 27)
  {
    Serial.println("cooler on!");
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }

}```
