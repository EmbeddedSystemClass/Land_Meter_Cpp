/*
 * heater.cpp  Created on: 17 September 2018
 * Copyright (c) 2018 Jack Walker

 */

#include "heater.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

using namespace std;
// change exploringBB to ZLS
namespace exploringBB {
    
    
// SHOULD I MAKE HEATER A CLASS OR A FUNCTION?
// FOR SIMPLICITY I WILL START WITH A CLASS FOR VARIABLE STORAGE AND BASIC CALCULATIONS
// THEN JUST SET A HEATER_ON VARIABLE AND SETUP ERROR HANDLING
    
    
    
HEATER::HEATER(string name, int gpio, int thermistorCount) {
	this->name = name;
	this->divider = 1.0;
	this->offset=0.0;
	this->setpointHigh = 50; //deg C
	this->setpointLow = 50;  // deg C
	this->temperature1 = 0.0;
    this->temperature2 = 0.0;
    this->heaterStatus = 0;
    if(this->thermistorCount > 0 && this->thermistorCount < 3){
        this->thermistorCount = thermistorCount;
    }
    else{
        perror("HEATER: Invalid thermistor count.  Set to 1");
        this->thermistorCount = 1;
    }
	this->path = GPIO_PATH + this->name + "/";

}


float HEATER::getAvgTemp(float temp1, float temp2){
    float avgTemp = (temp1 + temp2) / 2.0;
    return (avgTemp);
}

int HEATER::updateStatus(){
    if(this->thermistorCount == 1){
        if(this->temperature1 < this->setpointHigh){
            this->heaterStatus = 1;
        }
        else{
            this->heaterStatus = 0;
        }
    }
    else{
        if(return this->getAvgTemp() < this->setpointHigh){
            this->heaterStatus = 1;
        }
        else{
            this->heaterStatus = 0;
        }
    }
}

HEATER::~HEATER() {}

} /* namespace exploringBB */    
