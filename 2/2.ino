int flexPin = A0;  // 曲げセンサー(flex sensor)をアナログピン0番に接続
float flexVal = 0; // 曲げセンサーが計測する曲がり具合
int melodyTime = 500; // 音が鳴る時間の長さ
int speakerPin = 2;  // スピーカーをデジタルピン2番に接続

void setup()
{
    Serial.begin(9600);
}

void loop()
{
	flexVal = analogRead( flexPin ); // アナログピン0番から曲がり具合を読み取る
	Serial.println(flexVal);         // シリアルモニタに曲がり具合を表示
    
	if(flexVal > 750){               // 曲げが750より大きい場合
        tone(speakerPin, 262, melodyTime); // 音を鳴らす
    }
    
	delay( melodyTime ); // 音の長さだけ待つ
}