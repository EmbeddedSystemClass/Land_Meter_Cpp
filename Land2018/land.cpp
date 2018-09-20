/* A Simple GPIO application
* Written by Derek Molloy for the book "Exploring BeagleBone: Tools and 
* Techniques for Building with Embedded Linux" by John Wiley & Sons, 2014
* ISBN 9781118935125. Please see the file README.md in the repository root 
* directory for copyright and GNU GPLv3 license information.            */

#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
#include"PWM.h" 

using namespace exploringBB;
using namespace std;

/*
pwmchip1 pwm0:0   ECAP0     P9_42   Heartbeat
pwmchip1 pwm1:0   EHRPWM0A  P9_22
pwmchip1 pwm1:1   EHRPWM0B  P9_21
pwm3:0   pwm3:0   EHRPWM1A  P9_14   PWM1A
pwm3:1   pwm3:0   EHRPWM1B  P9_16   PWM1B  Cannot use.
pwm5:0
pwm5:1
pwm6:0   pwm6:0   EHRPWM2A  P8_19   PWM2A
pwm6:1   pwm6:0   EHRPWM2B  P8_13   PWM2B

*/



int callbackFunction(int var){
	cout << "BBB Button Pressed!" << var << endl;
	return var;
}


int callbackLongFault(int var){
	cout << "Long Button Pressed!" << var << endl;
	return var;
}

int callbackCrossFault(int var){
	cout << "Cross Button Pressed!" << var << endl;
	return var;
}

int callbacShaftFault(int var){
	cout << "Shaft Button Pressed!" << var << endl;
	return var;
}

int callbackArrestmentFault(int var){
	cout << "Arrestment Button Pressed!" << var << endl;
	return var;
}

int callbackHeartBeat(int var){
	cout << "Heart Beat Button Pressed!" << var << endl;
	return var;
}









int main(){
   
   
   
   
        string Meter                            =     "Land";
        string Hardware_revision                =     "1.0";         
        string Software_revision                =     "1.5";       
        string Calibration_version              =     "calibrated";  
        string Customer                         =     "Orangelamp";  
    
        int pwm_freq                            =     125;       
        int sense_freq                          =     10000;     
        float adc_offset                        =     0.0044678;   
        float zh_offset                         =     0.0;         
        float lid_thermistor_offset             =     0.0;         
        float p12v_offset                       =     0.0;         
        float p5v_offset                        =     0.0;         
        float p3p3v_offset                      =     0.0;         
        float battery_thermistor_offset         =     0.0;         
        float batt_v_offset                     =     0.0;         
        float beam_offset                       =     0.0;         
        float m5v_offset                        =     0.0;         
        float zp_offset                         =     0.0;         
        float gearbox_thermistor_offset         =     0.0;         
        float conning_tower_thermistor_offset   =     0.0;         
        float arrestment_thermistor_offset      =     0.0;         
        float meter_thermistor_1_offset         =     0.0;         
        float meter_thermistor_2_offset         =     0.0;            
        float adc_divider                       =     0.0044678;   
        float zh_divider                        =     0.0;         
        float lid_thermistor_divider            =     0.0;         
        float p12v_divider                      =     0.0;         
        float p5v_divider                       =     0.0;         
        float p3p3v_divider                     =     0.0;         
        float battery_thermistor_divider        =     0.0;         
        float batt_v_divider                    =     0.0;         
        float beam_divider                      =     0.0;         
        float m5v_divider                       =     0.0;         
        float zp_divider                        =     0.0;         
        float gearbox_thermistor_divider        =     0.0;         
        float conning_tower_thermistor_divider  =     0.0;         
        float arrestment_thermistor_divider     =     0.0;         
        float meter_thermistor_1_divider        =     0.0;         
        float meter_thermistor_2_divider        =     0.0;         
        float beam10                            =     0.0;         
        float beam50                            =     2.5;         
        float beam90                            =     5.0;         
        float p5vTarget                         =     5.0;        
        float p5vError                          =     0.2;        
        float p3p3vTarget                       =     3.3;        
        float p3p3vError                        =     0.2;        
        float p12vTarget                        =     12.0;       
        float p12vError                         =     0.2;        
        float batteryTarget                     =     12.0;       
        float batteryError                      =     2.0;        
        float zh_Target                         =     36.0;       
        float zh_Error                          =     0.5;        
        float zpTarget                          =     24.0;       
        float zpError                           =     0.01;           
   
   
   
// Setup GPIO etc.  
// OUTPUTS   
   // GPIO outGPIO(37);//, inGPIO(115), 
   GPIO systemPowerEnable(37);            //P8_22
   GPIO arrestmentHeaterFET(38);          //P8_3
   GPIO conningTowerFET(39);              //P8_4
   GPIO meterHeaterFET(34);               //P8_5
   GPIO gearboxHeaterFET(35);             //P8_6
   GPIO boardHeaterFET1(66);              //P8_7
   GPIO boardHeaterFET2(67);              //P8_8
   

   GPIO SHAFT_DIR(45);                    //P8_11
   GPIO SHAFT_PWM(44);                    //P8_12
   GPIO ARRESTMENT_DIR(27);               //P8_17
   GPIO ARRESTMENT_PWM(65);               //P8_18
   GPIO CROSS_DIR(8);                     //P8_35
   GPIO CROSS_PWM(80);                    //P8_36
   GPIO LONG_DIR(78);                     //P8_37
   GPIO LONG_PWM(79);                     //P8_38   
   
   GPIO FB_MUX_A0(32);                    //P8_25
   GPIO FB_MUX_A1(61);                    //P8_26


   GPIO thermistor_MUX_A0(10);            //P8_31
   GPIO thermistor_MUX_A1(11);            //P8_32
   GPIO thermistor_MUX_A2(9);             //P8_33
   GPIO Thermistor_MUX_A3(81);             //P8_34
   

   GPIO SPI0_CS0_MUX_A0(76);              //P8_39
   GPIO SPI0_CS0_MUX_A1(77);              //P8_40
   GPIO SPI0_CS0_MUX_A2(74);              //P8_41

   GPIO MUX_D0(26);                       //P8_14
   GPIO MUX_D1(47);                       //P8_15
   GPIO MUX_D2(46);                       //P8_16
   
   
// INPUTS
   GPIO LONG_FAULT(86);                   //P8_27
   GPIO Heartbeat(87);                    //P8_29
   GPIO ARRESTMENT_FAULT(89);             //P8_30
   GPIO SHAFT_FAULT(69);                  //P8_9
   GPIO CROSS_FAULT(68);                  //P8_210
   
   
   
   
// Set GPIO Direction 
   systemPowerEnable.setDirection(OUTPUT);
   arrestmentHeaterFET.setDirection(OUTPUT);
   conningTowerFET.setDirection(OUTPUT);     
   meterHeaterFET.setDirection(OUTPUT);      
   gearboxHeaterFET.setDirection(OUTPUT);  
   boardHeaterFET1.setDirection(OUTPUT);    
   boardHeaterFET2.setDirection(OUTPUT);  
   
   
   SHAFT_DIR.setDirection(OUTPUT);        
   SHAFT_PWM.setDirection(OUTPUT);        
   ARRESTMENT_DIR.setDirection(OUTPUT);      
   ARRESTMENT_PWM.setDirection(OUTPUT);      
   CROSS_DIR.setDirection(OUTPUT);          
   CROSS_PWM.setDirection(OUTPUT);          
   LONG_DIR.setDirection(OUTPUT);          
   LONG_PWM.setDirection(OUTPUT);            
   FB_MUX_A0.setDirection(OUTPUT);           
   FB_MUX_A1.setDirection(OUTPUT);           
   thermistor_MUX_A0.setDirection(OUTPUT);  
   thermistor_MUX_A1.setDirection(OUTPUT);  
   thermistor_MUX_A2.setDirection(OUTPUT);    
   Thermistor_MUX_A3.setDirection(OUTPUT);   
   SPI0_CS0_MUX_A0.setDirection(OUTPUT);    
   SPI0_CS0_MUX_A1.setDirection(OUTPUT);    
   SPI0_CS0_MUX_A2.setDirection(OUTPUT);    
   MUX_D0.setDirection(OUTPUT);              
   MUX_D1.setDirection(OUTPUT);              
   MUX_D2.setDirection(OUTPUT);              
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
// Read cal file.  Set offsets etc.

// Initialize GPIO

// Initialize SPI
// Initialize ADC

// Initialize Encoder


// Verify ADC checking BBB 5V


// Enable system voltages


// Verify system voltages and log


// Initialize heaters & start heat cycle
// Export PWM
   PWM heartBeat("0","0"); 
   PWM PWM1A("3", "0");
   PWM PWM2A("6", "0");
   PWM PWM2B("6", "1"); 
   usleep(10000000);    // allow time for file system to export files

// Initialize PWM

// Maybe set run later

   cout << "Initializing Heartbeat" << endl;
   PWM heartBeat("0","0"); 
   heartBeat.setFrequency(1);                // Set frequency in Hz
   heartBeat.setDutyCycle(50.0f);            // Set the duty cycle as a percentage
   heartBeat.setPolarity(PWM::ACTIVE_LOW);   // using active low PWM
   heartBeat.run();                          // start the PWM output
   
   
   cout << "Initializing PWM1A" << endl;
   PWM1A.setFrequency(125);
   PWM1A.setDutyCycle(50.0f);       
   PWM1A.setPolarity(PWM::ACTIVE_LOW);  
   PWM1A.run();                     
   

   cout << "Initializing PWM2A" << endl;
   PWM2A.setFrequency(65000);       
   PWM2A.setDutyCycle(50.0f);       
   PWM2A.setPolarity(PWM::ACTIVE_LOW);  
   PWM2A.run();                     
   
   cout << "Initializing PWM2B" << endl;
   PWM2B.setFrequency(65000);        
   PWM2B.setDutyCycle(50.0f);       
   PWM2B.setPolarity(PWM::ACTIVE_LOW);  
   PWM2B.run();  


















   // systemPowerEnable.setDirection(OUTPUT);
   // systemPowerEnable.setValue(HIGH);
   // Basic Output - Flash the LED 10 times, once per second
   // outGPIO.setDirection(OUTPUT);
   // for (int i=0; i<50; i++){
   //    outGPIO.setValue(HIGH);
   //    // systemPowerEnable.setValue(HIGH);
   //    usleep(50000); //micro-second sleep 0.5 seconds
   //    outGPIO.setValue(LOW);
   //    // systemPowerEnable.setValue(LOW);
   //    usleep(50000);
   // }
   // Basic Input example
   // inGPIO.setDirection(INPUT);
   // cout << "The value of the input is: "<< inGPIO.getValue() << endl;

   // // Fast write to GPIO 1 million times
   // outGPIO.streamOpen();
   // for (int i=0; i<1000000; i++){
   //    outGPIO.streamWrite(HIGH);
   //    outGPIO.streamWrite(LOW);
   // }
   // outGPIO.streamClose();

    int landRun = 0;
    while(landRun ){
        
    }






   return 0;
}
