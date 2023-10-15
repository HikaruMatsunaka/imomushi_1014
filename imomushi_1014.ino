
#include <VarSpeedServo.h> 

VarSpeedServo servo13;
VarSpeedServo servo12;
VarSpeedServo servo11;
VarSpeedServo servo10;


const int ledPin = 5; // LEDのピン番号
int cds = 0;


void setup() {
  servo13.attach(13);
  servo12.attach(12);
  servo11.attach(11);
  servo10.attach(10);

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); 
}

void loop() {

  cds = analogRead(0);
  Serial.print("analog:");  // シリアルモニタにアナログ値を表示
  Serial.println(cds);
  delay(100);

  if (cds <= 500) {
    // Cdsセルの値が500以下の時に実行するコード
    moveServosAndLED();
  } else {
    // 500より大きい時に実行するコード (現在はブランク)
    // ここに別のコードを追加できます
    servo13.write(180, 30, false);
    servo12.write(0, 30, false);

    rotateServos();
  }
}
  

void moveServosAndLED() {
  // サーボを動かしつつLEDの明るさを変える
  for(int x = 0; x <= 120; x += 5) {
    servo13.write(x, 30, false);
      servo12.write(180 - x, 30, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加
    analogWrite(ledPin, pwmValue);
    delay(60);
  }
  for(int x = 120; x <= 140; x += 5) {
    servo13.write(x, 15, false);
        servo12.write(180 - x, 15, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(120);
  }
  for(int x = 140; x <= 160; x += 5) {
    servo13.write(x, 10, false);
        servo12.write(180 - x, 10, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(180);
  }
  for(int x = 160; x <= 180; x += 5) {
    servo13.write(x, 5, false);
        servo12.write(180 - x, 5, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(320);
  }

  // 反対方向
  for(int x = 180; x >= 60; x -= 5) {
    servo13.write(x, 30, false);
        servo12.write(180 - x, 30, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(60);
  }
  for(int x = 60; x >= 40; x -= 5) {
    servo13.write(x, 15, false);
        servo12.write(180 - x, 15, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(120);
  }
  for(int x = 40; x >= 20; x -= 5) {
    servo13.write(x, 10, false);
        servo12.write(180 - x, 10, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(180);
  }
  for(int x = 20; x >= 0; x -= 5) {
    servo13.write(x, 5, false);
        servo12.write(180 - x, 5, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(320);
  }
}
  
void rotateServos() {
  // サーボを動かしつつLEDの明るさを変える
  for(int x = 0; x <= 120; x += 5) {
    servo11.write(x, 30, false);
      servo10.write(x, 30, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加
    analogWrite(ledPin, pwmValue);
    delay(60);
  }
  for(int x = 120; x <= 140; x += 5) {
    servo11.write(x, 15, false);
        servo10.write(x, 15, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(120);
  }
  for(int x = 140; x <= 160; x += 5) {
    servo11.write(x, 10, false);
        servo10.write(x, 10, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(180);
  }
  for(int x = 160; x <= 180; x += 5) {
    servo11.write(x, 5, false);
        servo10.write(x, 5, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(320);
  }

  // 反対方向
  for(int x = 180; x >= 60; x -= 5) {
    servo11.write(x, 30, false);
        servo10.write(x, 30, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(60);
  }
  for(int x = 60; x >= 40; x -= 5) {
    servo11.write(x, 15, false);
        servo10.write(x, 15, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(120);
  }
  for(int x = 40; x >= 20; x -= 5) {
    servo11.write(x, 10, false);
        servo10.write(x, 10, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(180);
  }
  for(int x = 20; x >= 0; x -= 5) {
    servo11.write(x, 5, false);
        servo10.write(x, 5, false);
    int pwmValue = 255L - (255L * x) / 180L;
    // Serial.print("pwmValue: ");
    // Serial.println(pwmValue);  // この行を追加
    // Serial.print("x: ");
    // Serial.println(x);  // この行を追加

    analogWrite(ledPin, pwmValue);
    delay(320);
  }
}
  

