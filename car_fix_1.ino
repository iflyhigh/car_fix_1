/* 
 * VW P2015 08213 G336 sensor error electronic-only fix using Attiny 85 & Arduino
 * (c)2015 Scott Tiger i at iflyhigh dot ru
 */

#define THRESHOLD_MIN 24    // minimal allowed voltage 5.0/256*24 = 0.469V
#define THRESHOLD_MAX 230   // maximal allowed voltage 5.0/256*235 = 4.589V

#define IN_PIN 3            // IC pin 2 - signal input
#define OUT_PIN 1           // IC pin 6 - signal output
//#define LED_PIN 4           // IC pin 3 - LED

void setup()
{
  pinMode(IN_PIN, INPUT);
  pinMode(OUT_PIN, OUTPUT);
  //pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int out_val = 0;
  int in_val = (analogRead(IN_PIN)/4);
  if (in_val < THRESHOLD_MIN) 
  { 
    out_val = THRESHOLD_MIN; 
    //digitalWrite(LED_PIN, HIGH);
  }
  else if (in_val > THRESHOLD_MAX) 
  { 
    out_val = THRESHOLD_MAX; 
    //digitalWrite(LED_PIN, HIGH);
  }
  else 
  { 
    out_val = in_val; 
    //digitalWrite(LED_PIN, LOW);    
  }
  analogWrite(OUT_PIN, out_val);
}
