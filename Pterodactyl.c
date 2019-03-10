#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  ,               sensorLEDtoVCC)
#pragma config(Sensor, I2C_1,  Swings,         sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor, port9,           wings,         tmotorVex393_MC29, openLoop, encoderPort, I2C_1)

int iWingTop = 397;
int iWingDown = -10;
int iWingPower = 105;

int iWingTime = 1000;
int iPistonTime = 1500;

task piston(){
	while(true){
		turnLEDOn(dgtl1);
		wait1Msec(iPistonTime);
		turnLEDOff(dgtl1);
		wait1Msec(iPistonTime);
	}
}

task flapWing(){

	while(true){
		while(SensorValue[Swings] < iWingTop){
			motor[wings] = 60;
		}
		turnLEDOn(dgtl1);
		while(SensorValue[Swings] > iWingDown){
			motor[wings] = -15;
		}
		turnLEDOff(dgtl1);
		motor[wings] = 0;

	}

	/*while(true){
		while( SensorValue[Swings] < iWingTop){
			motor[wings] = iWingPower;
		}
		while( SensorValue[Swings] > iWingDown){
			motor[wings] = -iWingPower;
		}
	}*/
}
task main()
{
	SensorValue[Swings] = 0;
	startTask(flapWing);
	//startTask(piston);
	while(true){
		wait1Msec(10);
	}
}
