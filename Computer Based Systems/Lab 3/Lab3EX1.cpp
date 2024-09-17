//In this exercise, you will be measuring the analog voltage
//emitted by the potentiometer and displaying that value
//on the terminal screen.

//Because the Raspberry Pi lacks an internal ADC, we will use
//the Adafruit ADS1015 12 Bit ADC.

//The ADS1015 communicates with the Raspberry Pi through
//I2C communication protocol.

//Complete the given function and use it to measure the
//voltage emitted by the potentiometer.

//Reference the lab supplement ads1015.pdf and I2CProtocol.pdf
//for more details on the Adafruit ADS1015 12 Bit converter
//and I2C protocol.

// single-end, 0-6.144V

//Use g++ -std=c++11 -o Lab3EX1 Lab3EX1.cpp -lwiringPi

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;



int adcVal();
int adc;
void stop(int);

int main(){
	//Initialize the wiringPi Library.
	wiringPiSetup();
	// pinMode(8, INPUT);
	// pinMode(9, INPUT);

		signal(SIGINT, stop);

	while(true){
		//Read value from ADC
		double mdv = adcVal();

		//Print value to screen.
		cout << "The Analog input voltage is " << mdv << endl;

		//Convert data to milliVolts.
		double adv = (mdv / 2047) * 6144;

		cout << "The Actual Analog input voltage is " << adv << "mV" << endl;
		
		


		//Slow the script speed down to gain better measurements.
		usleep(100000);
	}
}

//This function is used to read data from ADC1015
int adcVal(){

	uint16_t low, high, value;
	// Refer to the supplemental documents to find the parameters.
	adc = wiringPiI2CSetup(0x48 /*Address of ADS1015(HEX), e.g. 0x99 */);
	wiringPiI2CWriteReg16(adc, 0x01 /*Configuration Register(HEX), e.g. 0x99*/, 0xC5C1);
	usleep(1000);
    uint16_t data = wiringPiI2CReadReg16(adc, 0x00 /*Conversion Register(HEX), e.g. 0x99*/);


    low = (data & 0xFF00) >> 8;
    high = (data & 0x00FF) << 8;
    value = (high | low)>>4;
	return value;
}


void stop(int sig){exit(1);}