int flexPin = A0;  // 曲げセンサー(flex sensor)をアナログピン0番に接続
float flexVal = 0; // 曲げセンサーが計測する曲がり具合
void setup()
{
    Serial.begin(9600);
}

void loop()
{
	flexVal = analogRead( flexPin ); // アナログピン0番から曲がり具合を読み取る
	Serial.println(flexVal);         // シリアルモニタに曲がり具合を表示

	delay( 500 ); // 音の長さだけ待つ
}
