#ifndef HEATER_H_
#define HEATER_H_
#include<string>
using std::string;

namespace ZLS {


class HEATER {
private:
	int gpio, thermistorCount;
	string name;

public:
	HEATER(string name, int gpio, int thermistorCount) //constructor will export the pin
	
	
	virtual int getAvgTemp(float temp1, float temp2)
	
	virtual int getNumber() { return number; }

	// General Input and Output Settings
	virtual int setDirection(GPIO_DIRECTION);
	virtual GPIO_DIRECTION getDirection();
	virtual int setValue(GPIO_VALUE);
	virtual int toggleOutput();
	virtual GPIO_VALUE getValue();
	virtual int setActiveLow(bool isLow=true);  //low=1, high=0
	virtual int setActiveHigh(); //default
	//software debounce input (ms) - default 0
	virtual void setDebounceTime(int time) { this->debounceTime = time; }

	// Advanced OUTPUT: Faster write by keeping the stream alive (~20X)


	virtual ~HEATER();  //destructor will unexport the pin

private:
	int write(string path, string filename, string value);
	int write(string path, string filename, int value);
	string read(string path, string filename);
	int exportGPIO();
	int unexportGPIO();
	ofstream stream;
	pthread_t thread;
	CallbackType callbackFunction;
	bool threadRunning;
	int togglePeriod;  //default 100ms
	int toggleNumber;  //default -1 (infinite)

};


} /* namespace ZLS */

#endif /* HEATER_H_ */