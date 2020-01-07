#include <Drive/Drive.h>

Drive::Drive()
{
    motora = AFMS.getMotor(1);
    motorb = AFMS.getMotor(2);
    motorc = AFMS.getMotor(3);
    motord = AFMS.getMotor(4);

    
}

void Drive::StartAllMotors()
{
    motora->setSpeed(0);
    motorb->setSpeed(0);
    motorc->setSpeed(0);
    motord->setSpeed(0);

    motora->run(RELEASE);
    motorb->run(RELEASE);
    motorc->run(RELEASE);
    motord->run(RELEASE);
}

void Drive::RotateClockwise(int _speed)
{
    Motor(2,_speed,*motora);
    Motor(1,_speed,*motorb);
    Motor(2,_speed,*motorc);
    Motor(1,_speed ,*motord);
}

void Drive::RotateCounterClockwise(int _speed)
{
    Motor(1,_speed,*motora);
    Motor(2,_speed,*motorb);
    Motor(1,_speed,*motorc);
    Motor(2,_speed ,*motord);
}



void Drive::Motor(int _dir,int _speed, Adafruit_DCMotor _motor)
{
    _motor.run(_dir);
    _motor.setSpeed(_speed);
}

void Drive::Stop()
{
    motora->setSpeed(0);
    motorb->setSpeed(0);
    motorc->setSpeed(0);
    motord->setSpeed(0);
}