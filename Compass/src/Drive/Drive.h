#include <Adafruit_MotorShield.h>

class Drive
{
    private:

    
    Adafruit_DCMotor *motora;
    Adafruit_DCMotor *motorb;
    Adafruit_DCMotor *motorc;
    Adafruit_DCMotor *motord;
    void Motor(int _dir,int _speed,Adafruit_DCMotor _motor);

    public:
    Adafruit_MotorShield AFMS = Adafruit_MotorShield();
    Drive(/* args */);
    void StartAllMotors();
    void RotateClockwise(int _speed);
    
    void RotateCounterClockwise(int _speed);

    void Stop();
};


