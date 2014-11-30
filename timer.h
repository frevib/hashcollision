#ifndef __HR_TIME_H
#define __HR_TIME_H

/**
 * this stopwatch code is borrowed from 
 * http://allmybrain.com/2008/06/10/timing-cc-code-on-linux/
 */

#include <sys/time.h>

typedef struct {
	timeval start;
	timeval stop;
} stopWatch;

class CStopWatch {

private:
	stopWatch timer;
public:
	CStopWatch() {};
	void startTimer( );
	void stopTimer( );
	double getElapsedTime();
};

#endif
