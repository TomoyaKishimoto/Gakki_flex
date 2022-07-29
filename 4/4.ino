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
	flexVal = map(analogRead( flexPin ), 650, 950, 0, 100); // アナログピン0番から曲がり具合を読み取る
	Serial.println(flexVal);                   // シリアルモニタに曲がり具合を表示

	if(flexVal < 15){                         // 曲げが15より小さい場合
        tone(speakerPin, 262, melodyTime);    // ドの音を鳴らす
    }

    else if(flexVal >= 15 && flexVal < 30){  // 曲げが15より大きく、30より小さい場合
        tone(speakerPin, 294, melodyTime);   // レの音を鳴らす
    }

    else if(flexVal >= 30 && flexVal < 45){  // 曲げが30より大きく、45より小さい場合
        tone(speakerPin, 330, melodyTime);   // ミの音を鳴らす
    }

    else if(flexVal >= 45 && flexVal < 60){  // 曲げが45より大きく、60より小さい場合
        tone(speakerPin, 349, melodyTime);   // ファの音を鳴らす
    }

    else if(flexVal >= 60 && flexVal < 75){  // 曲げが60より大きく、75より小さい場合
        tone(speakerPin, 392, melodyTime);   // ソの音を鳴らす
    }

    else if(flexVal >= 75 && flexVal < 90){  // 曲げが75より大きく、90より小さい場合
        tone(speakerPin, 440, melodyTime);   // ラの音を鳴らす
    }

    else{                                    // それ以外の場合
        tone(speakerPin, 494, melodyTime);   // シの音を鳴らす
    }

	delay( melodyTime );
}