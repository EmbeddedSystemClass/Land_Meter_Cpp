#include<iostream>
#include<unistd.h> //for usleep
#include"GPIO.h"
using namespace exploringBB;
using namespace std;


//https://stackoverflow.com/questions/50204329/pwm-chip-to-pin-mapping-on-beaglebone-black-v4-14/50204330#50204330




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
   
   
   
  
   
   
// OUTPUTS   

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
   
   
   
    LONG_FAULT.setDirection(INPUT);         
    Heartbeat.setDirection(INPUT);             
    ARRESTMENT_FAULT.setDirection(INPUT);     
    SHAFT_FAULT.setDirection(INPUT);          
    CROSS_FAULT.setDirection(INPUT);  
    
    
    
    Heartbeat.setEdgeType(RISING);
    cout << "GPIO(48) has value: " << Heartbeat.getValue() << endl;
	Heartbeat.setDebounceTime(200);
	Heartbeat.waitForEdge(&callbackFunction);
	Heartbeat.toggleOutput(100);
    cout << "Poll Started: Press the button:" << endl;
    usleep(10000000);
    cout << "Finished sleeping for 10 seconds" << endl;
    
    
    
    
    
    
    
    
    return(0);
    
}