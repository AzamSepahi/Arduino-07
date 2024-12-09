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

}
