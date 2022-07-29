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
	flexVal = analogRead( flexPin );           // アナログピン0番から曲がり具合を読み取る
	Serial.println(flexVal);                   // シリアルモニタに曲がり具合を表示

	if(flexVal < 700){                         // 曲げが700より小さい場合
        tone(speakerPin, 262, melodyTime);     // ドの音を鳴らす
    }

    else if(flexVal >= 700 && flexVal < 750){  // 曲げが700より大きく、750より小さい場合
        tone(speakerPin, 294, melodyTime);     // レの音を鳴らす
    }

    else if(flexVal >= 750 && flexVal < 800){  // 曲げが750より大きく、800より小さい場合
        tone(speakerPin, 330, melodyTime);     // ミの音を鳴らす
    }

    else if(flexVal >= 800 && flexVal < 850){  // 曲げが800より大きく、850より小さい場合
        tone(speakerPin, 349, melodyTime);     // ファの音を鳴らす
    }

    else{                                      // それ以外の場合
        tone(speakerPin, 392, melodyTime);     // ソの音を鳴らす
    }

	delay( melodyTime );
}