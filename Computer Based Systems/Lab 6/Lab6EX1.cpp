#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;
bool state = 1;

// g++ -std=c++14 Lab6EX1.cpp -o Lab6EX1 -lwiringPi

void press_button(){
    usleep(200*1000);
    if (!digitalRead(1)) return;
    if(state == 1)
    {
        state = 0;
    }
    else
    {
        state = 1;
    }

    cout << state << endl;
}

int main(void){
    
    wiringPiSetup();
    

    /* 1. set mode for the pins, the pin mode of the PWM pin should be PWM_OUTPUT */
    int button = 1;
    int out1 = 2;
    int out2 = 3;
    int motor = 26;
    
    pinMode(button, INPUT);
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(motor, PWM_OUTPUT);


	/* 2. write HIGH or LOW to the two I/O pins to control the initial rotation direction */
    digitalWrite(out1, 1);
    digitalWrite(out2, 0);

    
    /* 3. use function pwmWrite to control the initial motor speed. Refer to document pwm.pdf for more information. */

    pwmWrite(motor, 1024);

    /* 4. use pulling or interrupt to control the direction toggling.*/

    wiringPiISR(button, INT_EDGE_RISING, &press_button);


    //tips:	run the code using sudo ./Lab6EX1
    while(true){

    if(state == 0){
        digitalWrite(out1, 1);
        digitalWrite(out2, 0);
    }

    else if(state == 1){
        digitalWrite(out1, 0);
        digitalWrite(out2, 1);
    }
    
    }
    return 0;
}

