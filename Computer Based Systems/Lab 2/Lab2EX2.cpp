//In this exercise, you will make an LED counter which will
//Count in binary from 0 to 15, or from 0000 to 1111.

//Use the digital I/O pins on the Raspberry Pi to send
//power to the LED. Complete the circuit as listed in
//the lab document.

//Thoroughly comment your code and demonstrate to the lab inststructor.


//Use g++ -std=c++11 -o Lab2_2 Lab2EX2.cpp -lwiringPi

#include <iostream>
#include <unistd.h>
#include <wiringPi.h>
#include <signal.h>
#include <stdlib.h>
using namespace std;

void stop(int);

int main(){
	//Initialize the wiringPi library.
	signal(SIGINT, stop);
	wiringPiSetup();

	//Set digital pins to output.
	//Use pinMode(PIN, MODE);
	pinMode(1, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);

	//Create each sequence and count from 0 to 15.
	//Use digitalWrite(PIN, Value);
	digitalWrite(1 ,HIGH); //turns off all LEDs
	digitalWrite(4 ,HIGH);
	digitalWrite(5 ,HIGH);
	digitalWrite(6 ,HIGH);

	for(int i = 0; i < 16; i++){//counts from 0 to 16
		cout << i << "\n";

		if(i % 2 == 1){ //checks if number is odd
			digitalWrite(1, LOW);
		}
		else{digitalWrite(1, HIGH);}

		if((i / 2) % 2 == 1){ // if i / 2 mod 2 is odd for 2, 6, 10, 14
			digitalWrite(4, LOW);
		}

		if(i == 4){
			digitalWrite(5, LOW);
			digitalWrite(4, HIGH);	
		}

		if(i == 8){digitalWrite(6, LOW); digitalWrite(5, HIGH); digitalWrite(4, HIGH);} // 8 resets all other digits as the 4th bit turns on

		if(i == 12){
			digitalWrite(5, LOW);
			digitalWrite(4, HIGH);	
		}

		usleep(1000000); //Create a 1 second delay after each sequence.
	}


	
	//Use usleep(us) for the delay.
}

void stop(int sig){exit(1);}
