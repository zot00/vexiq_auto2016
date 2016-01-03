#pragma config(Motor,  motor1,          Rlifter,       tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor2,          Ltmotor,       tmotorVexIQ, PIDControl, reversed, encoder)
#pragma config(Motor,  motor6,          Rmotor,        tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor7,          Llifter,       tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor8,          Rtmotor,       tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor12,         Lmotor,        tmotorVexIQ, PIDControl, reversed, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void botForward(float distance)

{

	/**

	* TODO: Use GYRO

	*/

	const int speed = 75;

	/* every 45 degrees is approximately 1 inch */

	setMotorSpeed(Lmotor,speed);
	setMotorSpeed(Ltmotor,speed);
	setMotorSpeed(Rmotor,speed);
	setMotorSpeed(Rtmotor,speed);
	waitUntilMotorStop(Lmotor);
	waitUntilMotorStop(Ltmotor);
	waitUntilMotorStop(Rmotor);
	waitUntilMotorStop(Rtmotor);
}
void goRight(int ms)
{
	int speed = 129;
	int speedRight = speed;
	int speedLeft = -speed;
	setMotorSpeed(Lmotor,speedLeft);
	setMotorSpeed(Rmotor,speedRight);
	setMotorSpeed(Ltmotor,speedLeft);
	setMotorSpeed(Rtmotor,speedRight);
	delay(ms);
}
void goLeft(int ms)
{
	int speed = 129;
	int speedRight = -speed;
	int speedLeft = speed;
	setMotorSpeed(Lmotor,speedLeft);
	setMotorSpeed(Rmotor,speedRight);
	setMotorSpeed(Ltmotor,speedLeft);
	setMotorSpeed(Rtmotor,speedRight);
	delay(ms);
}
void goForward(int ms)
{
	int speed = 129;
	int speedRight = speed;
	int speedLeft = speed;
	setMotorSpeed(Lmotor,speedLeft);
	setMotorSpeed(Rmotor,speedRight);
	setMotorSpeed(Ltmotor,speedLeft);
	setMotorSpeed(Rtmotor,speedRight);
	delay(ms);
}
void goBackward(int ms)
{
	int speed = 129;
	int speedRight = -speed;
	int speedLeft = -speed;
	setMotorSpeed(Lmotor,speedLeft);
	setMotorSpeed(Rmotor,speedRight);
	setMotorSpeed(Ltmotor,speedLeft);
	setMotorSpeed(Rtmotor,speedRight);
	delay(ms);
}
void lift(int LDEG, int LSPD)
{
	//moves to a variable degrees at a variable speed
	setMotorTarget(Llifter, LDEG, LSPD);
	setMotorTarget(Rlifter, LDEG, LSPD);
	waitUntilMotorStop(Llifter);
	waitUntilMotorStop(Rlifter);
}
void botDump()

{

	lift(-1300, -129);

	setMotorSpeed(Lmotor, 0);

	setMotorSpeed(Rmotor, 0);

	setMotorSpeed(Ltmotor, 0);

	setMotorSpeed(Rtmotor, 0);

	delay(500);

	lift(0, 129);

}


void anthony()
{
	goRight(630);
	goForward(3000);
	goBackward(1500);
	goLeft(900);
	goForward(3000);
	goBackward(100);
	lift(-500, 129);
	goLeft(530);
	goBackward(1300);
	goLeft(430);
	goBackward(800);
	goBackward(0);
	botDump();
	resetMotorEncoder(Llifter);
	resetMotorEncoder(Rlifter);
}
void michael()
{
	goForward(500);
	goLeft(150);
	goForward(4200);
	goBackward(1500);
	goRight(1100);
	goForward(3500);
	goBackward(100);
	lift(-500, 129);
	goRight(530);
	goBackward(1300);
	goRight(430);
	goBackward(800);
	goBackward(0);
	botDump();
	resetMotorEncoder(Llifter);
	resetMotorEncoder(Rlifter);
}

task main()
{
	anthony();
	michael();
}










/*resetMotorEncoder(Llifter);
resetMotorEncoder(Rlifter);
setMotorTarget(Llifter,-1150,-129);
setMotorTarget(Rlifter,-1150,-129);
waitUntilMotorStop(Llifter);
waitUntilMotorStop(Rlifter);
sleep(250);

setMotorTarget(Llifter,0,129);
setMotorTarget(Rlifter,0,129);
waitUntilMotorStop(Llifter);
waitUntilMotorStop(Rlifter);
sleep(250);
}
//dump
/*resetMotorEncoder(Llifter);
resetMotorEncoder(Rlifter);
setMotorTarget(Llifter,-1150,-129);
setMotorTarget(Rlifter,-1150,-129);
waitUntilMotorStop(Llifter);
waitUntilMotorStop(Rlifter);
sleep(250);
//return
setMotorTarget(Llifter,0,129);
setMotorTarget(Rlifter,0,129);
waitUntilMotorStop(Llifter);
waitUntilMotorStop(Rlifter);
sleep(250);*/


/*setMotorSpeed(Lmotor,129);
setMotorSpeed(Rmotor,129);
setMotorSpeed(Ltmotor,129);
setMotorSpeed(Rtmotor,129);
sleep(1200);

setMotorSpeed(Lmotor,129);
setMotorSpeed(Rmotor,-129);
setMotorSpeed(Ltmotor,129);
setMotorSpeed(Rtmotor,-129);
sleep(400);

setMotorSpeed(Lmotor,-129);
setMotorSpeed(Rmotor,-129);
setMotorSpeed(Ltmotor,-129);
setMotorSpeed(Rtmotor,-129);
sleep(2400);

setMotorSpeed(Llifter,129);
setMotorSpeed(Rlifter,129);
sleep(1500);

setMotorSpeed(Lmotor,0);
setMotorSpeed(Rmotor,0);
setMotorSpeed(Ltmotor,0);
setMotorSpeed(Rtmotor,0);
sleep(60000);
}*/

/*resetMotorEncoder(name of motor);

setMotorTarget(name of motor, degrees, power);

waitUntilMotorStop(name of motor);

example:
//dump
resetMotorEncoder(Llifter);
resetMotorEncoder(Rlifter);
setMotorTarget(Llifter,-1150,-129);
setMotorTarget(Rlifter,-1150,-129);
waitUntilMotorStop(Llifter);
waitUntilMotorStop(Rlifter);
sleep(250);
//return
setMotorTarget(Llifter,0,129);
setMotorTarget(Rlifter,0,129);
waitUntilMotorStop(Llifter);
waitUntilMotorStop(Rlifter);
sleep(250)
}*/
