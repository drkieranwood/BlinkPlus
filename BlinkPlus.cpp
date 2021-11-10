#include "BlinkPlus.h"


//Default timings
BlinkPlus::BlinkPlus(uint8_t ledPin) : _ledPin(ledPin)
{
	this->_normIntval = 2000;
	this->_errIntval = 250;

}


//Constructor with timings settings
BlinkPlus::BlinkPlus(uint8_t ledPin,uint32_t norm_interval,uint32_t err_inteval) : _ledPin(ledPin)
{
	if (norm_interval<200) {
		this->_normIntval = 200;
	}
	else {
		this->_normIntval = norm_interval;
	}
	
	if (err_inteval<200) {
		this->_errIntval = 200;
	}
	else {
		this->_errIntval = err_inteval;
	}
}


//Init. the blink timers and set the LED on
void BlinkPlus::init(void)
{
	pinMode(this->_ledPin,OUTPUT);
	digitalWrite(this->_ledPin, HIGH);
	this->_lastBlink_t = millis();
	this->_curIntval = this->_normIntval;
}


//Set the current timing of the blink depending on the error state
void BlinkPlus::setError(bool err)
{
	if (err) {
		this->_curIntval = this->_errIntval;
	}
	else {
		this->_curIntval = this->_normIntval;
	}
}


//Depending on the error state, check if the LED should be on or off.
void BlinkPlus::update(void)
{
	//Check if the blink interval has elapsed.
	if ((millis() - this->_lastBlink_t) > _curIntval) {
		this->_lastBlink_t = millis();
		digitalWrite(this->_ledPin, HIGH);
	}
	
	//Turn off the LED after a short pulse.
	if ((millis() - this->_lastBlink_t) > 150) {
		digitalWrite(this->_ledPin, LOW);
	}
}
//eof