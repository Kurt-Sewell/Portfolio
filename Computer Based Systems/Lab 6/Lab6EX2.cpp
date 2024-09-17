#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;
bool state = 0;
bool max_hit = 0;
int speed;

// g++ -std=c++14 Lab6EX2.cpp -o Lab6EX2 -lwiringPi

void press_button1(){
    usleep(200*1000);
    if (!digitalRead(1)){ return;}
    if(state == 0){
        state = 1;
        cout << state << endl;
    }
    else{
        state = 0;
        cout << state << endl;
    }
}

void press_button2(){
    usleep(200*1000);
    if (!digitalRead(4)){ return;}
    if(max_hit == 0){
        speed += 256;
        cout << speed << endl;
        if(speed >= 1024){
            max_hit = 1;
        }    
    }

    else{
        speed -= 256;
        cout << speed << endl;
        if(speed <= 0){
            max_hit = 0;
        }
    }
}

int main(void){
    
    wiringPiSetup();

    /* 1. set mode for the pins, the pin mode of the PWM pin should be PWM_OUTPUT */
    int button1 = 1;
    int button2 = 4;
    int out1 = 2;
    int out2 = 3;
    int motor = 26;

    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(motor, PWM_OUTPUT);

    digitalWrite(out1, 0);
    digitalWrite(out2, 0);

    pwmWrite(motor, 0);

    /* 2. use pulling or interrupt to control the motor.*/

    wiringPiISR(button1, INT_EDGE_RISING, &press_button1);
    wiringPiISR(button2, INT_EDGE_RISING, &press_button2);

    while(true){
        if(state == 0){
            digitalWrite(out1, 0);
            digitalWrite(out2, 0);
        }

        else if(state == 1){
            digitalWrite(out1, 1);
            digitalWrite(out2, 0);
        }
        
        pwmWrite(motor, speed);
   
    }



    return 0;
}

