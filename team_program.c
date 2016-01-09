#pragma config(Sensor, port9,   L_LED,  sensorVexIQ_LED)
#pragma config(Sensor, port10,  R_LED,  sensorVexIQ_LED)
#pragma config(Sensor, port11,  GYRO,   sensorVexIQ_Gyro)
#pragma config(Motor,  motor1,  R_LIFT, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor2,  L_TMOT, tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,  R_MOT,  tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,  L_LIFT, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor8,  R_TMOT, tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor12, L_MOT,  tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//float startingGyro;

static void goRight(const int ms)
{
	const int speed = 129;
	const int speedRight = speed;
	const int speedLeft = -speed;
	setMotorSpeed(L_MOT,speedLeft);
	setMotorSpeed(R_MOT,speedRight);
	setMotorSpeed(L_TMOT,speedLeft);
	setMotorSpeed(R_TMOT,speedRight);
	delay(ms);
}
static void goLeft(const int ms)
{
	const int speed = 129;
	const int speedRight = -speed;
	const int speedLeft = speed;
	setMotorSpeed(L_MOT,speedLeft);
	setMotorSpeed(R_MOT,speedRight);
	setMotorSpeed(L_TMOT,speedLeft);
	setMotorSpeed(R_TMOT,speedRight);
	delay(ms);
}
static void goForward(const int ms)
{
	const int speed = 129;
	const int speedRight = speed;
	const int speedLeft = speed;
	setMotorSpeed(L_MOT, speedLeft);
	setMotorSpeed(R_MOT, speedRight);
	setMotorSpeed(L_TMOT, speedLeft);
	setMotorSpeed(R_TMOT, speedRight);
	delay(ms);
}
static void goBackward(const int ms)
{
	const int speed = 129;
	const int speedRight = -speed;
	const int speedLeft = -speed;
	setMotorSpeed(L_MOT, speedLeft);
	setMotorSpeed(R_MOT, speedRight);
	setMotorSpeed(L_TMOT, speedLeft);
	setMotorSpeed(R_TMOT, speedRight);
	delay(ms);
}
static void goScoopwait(void)
{
	waitUntilMotorStop(L_LIFT);
	waitUntilMotorStop(R_LIFT);
}
static void goScoopUp(const int deg)
{
	const int speed = -129;
	setMotorTarget(L_LIFT, -deg, speed);
	setMotorTarget(R_LIFT, -deg, speed);
}
static void goScoopDown(const int deg)
{
	const int speed = 129;
	setMotorTarget(L_LIFT, -deg, speed);
	setMotorTarget(R_LIFT, -deg, speed);
}
static void goDump(void)
{
	goScoopUp(1200);
	goScoopwait();
	delay(1300);
	goScoopDown(0);
	delay(500);
}
static void goStop(void)
{
	setMotorSpeed(L_MOT, 0);
	setMotorSpeed(R_MOT, 0);
	setMotorSpeed(L_TMOT, 0);
	setMotorSpeed(R_TMOT, 0);
}


static void anthony()
{
	goRight(630);
	goForward(2500);
	goBackward(1500);
	goLeft(1000);
	goForward(3600);
	goScoopUp(500);
	goBackward(450);
	goStop();
	goScoopwait();
	goLeft(470);
	goBackward(1200);
	goLeft(460);
	goBackward(600);
	goStop();
	delay(5000);
	goDump();
}
static void michael()
{
	goForward(400);
	goLeft(125);
	goForward(4500);
	goBackward(1500);
	goRight(1100);
	goForward(3500);
	goScoopUp(500);
	goBackward(450);
	goStop();
	goScoopwait();
	goRight(470);
	goBackward(1200);
	goRight(460);
	goBackward(650);
	goStop();
	goDump();
	goScoopDown(0);
}

task main()
{
	anthony();
	michael();
}
