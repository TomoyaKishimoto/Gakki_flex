int analogPin = A0;
int melo = 500;
int pin = 2;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
	float flex_val = analogRead( analogPin );
	Serial.println(flex_val);
	if(flex_val < 710)
    {
        tone(pin,262,melo); //ド
    }
    else if(flex_val > 700 && flex_val < 750)
    {
        tone(pin,294,melo); //レ
    }
    else if(flex_val > 750 && flex_val < 800)
    {
        tone(pin,330,melo); //ミ
    }
    else if(flex_val > 800 && flex_val < 850)
    {
        tone(pin,349,melo); //ファ
    }
    else
    {
        tone(pin,392,melo); //ソ
    }
	delay( melo );
}