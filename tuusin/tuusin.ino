int val; //読み取り値の変数を用意

void setup(){
  Serial.begin(9600);
}
void loop(){
  //アナログ入力０番ピンの値を読み取り(0~1023)
  //4で割った値を変数valに入れる(0~255)
  val=analogRead(0)/4;
  //シリアルでvalを送信
  Serial.write(val);
  //1秒間に20回ループ(0.05sec)とする
  delay(50);
}
