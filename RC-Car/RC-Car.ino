#include <SoftwareSerial.h>

#define motor1Pin1 3
#define motor1Pin2 5
#define motor2Pin1 9
#define motor2Pin2 11
#define blueRightLed 7
#define blueLeftLed 6
#define redRightLed 10
#define redLeftLed 12

int buzzer_pin = 4;

int maxSpeed = 255;
int midSpeed = 125;
int minSpeed = 0;
int tempo = 400;
char command = 'N';


SoftwareSerial BTSerial (A1, A0);

void setup()
{
    pinMode(motor2Pin1,OUTPUT);
    pinMode(motor1Pin2,OUTPUT);
    pinMode(motor2Pin1,OUTPUT);
    pinMode(motor2Pin2,OUTPUT);
    pinMode(blueRightLed, OUTPUT);
    pinMode(blueLeftLed, OUTPUT);
    pinMode(buzzer_pin, OUTPUT);

    Serial.println("test");
    Serial.begin(9600);
    BTSerial.begin(9600);

}

void loop()
{

    if (BTSerial.available())
    {
        char reader = BTSerial.read();
        if (reader != '\n')
            command = reader;
        Serial.println(command);
    }
    switch (command)
    {
    case 'W':
        Serial.println("HELLO");
        forward();
        blueLedOn();
        break;

    case 'S':
        backward();
        blueLedOn();
        redLedOn();
        break;

    case 'D':
        left();
        blueLedOnRight();
        break;

    case 'd':
        leftSlow(maxSpeed);
        blueLedOn();
        break;

    case 'A':
        right();
        blueLedOnLeft();
        break;

    case 'a':
        rightSlow(maxSpeed);
        blueLedOn();
        break;


    case 'G':
        gasGasGas();
        blueLedOn();
        break ;

    case 'H':
        song();
        blueLedOn();
        break;

    default:
        staph();
        blueLedOff();
        redLedOn();
        break;
    }
}

void forward()
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
}

void backward()
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
}

void left()
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
}

void leftSlow(int DCspeed)
{
    analogWrite(motor1Pin1, midSpeed);
    analogWrite(motor1Pin2, minSpeed);
    analogWrite(motor2Pin1, DCspeed);
    analogWrite(motor2Pin2, minSpeed);
}

void right()
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

void rightSlow(int DCspeed)
{
    analogWrite(motor1Pin1, DCspeed);
    analogWrite(motor1Pin2, minSpeed);
    analogWrite(motor2Pin1, midSpeed);
    analogWrite(motor2Pin2, minSpeed);
}

void gasGasGas()
{
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
}

void staph()
{
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

void blueLedOn()
{
    digitalWrite(blueLeftLed, HIGH);
    digitalWrite(blueRightLed, HIGH);

}

void blueLedOff()
{
    digitalWrite(blueLeftLed, LOW);
    digitalWrite(blueRightLed, LOW);
}

void redLedOn()
{
    digitalWrite(redLeftLed, HIGH);
    digitalWrite(redRightLed, HIGH);
}

void blueLedOnLeft()
{
    digitalWrite(blueLeftLed, HIGH);
    digitalWrite(blueRightLed, LOW);
}

void blueLedOnRight()
{
    digitalWrite(blueLeftLed, LOW);
    digitalWrite(blueRightLed, HIGH);
}

void redLedOff()
{
    digitalWrite(redLeftLed, LOW);
    digitalWrite(redRightLed, LOW);
}

struct MusicStruct
{
    int B = 617;
} Music;

struct LengthStruct
{
  float one = 1.0;

} Length;

void setTone(int pin, int note, int duration)
{
    tone(pin, note, duration);
    noTone(pin);
}

void song()
{
    setTone(buzzer_pin, Music.B, tempo * Length.one);

}
