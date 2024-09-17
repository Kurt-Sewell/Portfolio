// Lab 5, Exercise 2
// g++ -std=c++14 Lab5EX2.cpp -o Lab5EX2 -lwiringPi

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <string.h>
#include <chrono>
#include <ratio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
/* Complete the code: include the file lab_util.cpp  */
//#include "lab_util.cpp"
#include "lab_util.cpp"
using namespace std::chrono;
using namespace std;


/* Complete the code: Set button pin */
int BUTTON = 26;

high_resolution_clock::time_point hit_time; 

// State enum definition
enum State {
	STOPPED,
	RUNNING,
	RESET
};

// Global variables
State state;
high_resolution_clock::time_point begin_time;
unsigned int counter;

/* Complete the code, implement the timer */
void press_button() {
    double sleep_duration = 0.1;
    int reset_counter = 0;
    int counter_max = 4 / sleep_duration;

    if (state == STOPPED) {

        /* Complete the code */
        if (digitalRead(BUTTON)){
           
            state = RUNNING;
            begin_time = high_resolution_clock::now();
        }

    } else if (state == RUNNING) {
        /* Complete the code  */
        if(digitalRead(BUTTON)){
            
            counter++;

            hit_time = high_resolution_clock::now();

            string timestamp = formatTime(begin_time, hit_time);

            cout << counter << " : " << counter;

            if(counter == 1 || counter == 21){
               cout << "st place: ";
            }
        
            else if(counter == 2 || counter == 22){
                cout << "nd place: ";
            }

            else if(counter == 3 || counter == 23){
                cout << "rd place: ";
            }

            else{
                cout << "th place: ";
            }

            cout << " place: " << timestamp << endl;
        }

        while(digitalRead(BUTTON)){
            usleep(sleep_duration*1000*1000);
            reset_counter += 1;
            if(reset_counter >= counter_max){
                state = STOPPED;
                counter = 0;
                cout << "Reset" << endl;

                break;
            }
        }

    } 
}


int main(){

    // Set up WiringPi
    if (wiringPiSetup() == -1) exit (1);

    state = STOPPED;
    counter = 0;
    unsigned int button_time = 0;
    

    cout << "Holding for long time to reset" << endl;
    
    /* Complete the code to implement the timer  */
    pinMode(BUTTON, INPUT);
    
    wiringPiISR(BUTTON, INT_EDGE_RISING, &press_button);


    /*
    Tips:
    1) Set digital pins to input, Use pinMode(PIN, MODE)
    2) Use wiringPiISR() to get the interupt
    3) Read the state of pin: digitalRead(PIN)
    4) Use delay() to set a delay
    5) Define the state for the timer
    6) Use the formatTime() in lab_util.cpp
    */
   while(true){}

    return 0;
}