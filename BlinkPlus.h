#ifndef BlinkPlus_h
#define BlinkPlus_h
/*
  BlinkPlus.h - Library for using the LED to convey system health
  Created by Kieran T. Wood, November 10, 2021.
  Released into the public domain.
*/

#include "Arduino.h"

class BlinkPlus
{
  public:
    BlinkPlus(uint8_t ledPin);
	BlinkPlus(uint8_t ledPin,uint32_t norm_interval,uint32_t err_inteval);
	
    void init(void);
	
    void update(void);
	
    void setError(bool err);
	
  private:
	bool _errState = false;
	uint8_t _ledPin;
	uint32_t _normIntval;
	uint32_t _errIntval;
	uint32_t _curIntval;
	unsigned long _lastBlink_t = 0;

};

#endif
//eof