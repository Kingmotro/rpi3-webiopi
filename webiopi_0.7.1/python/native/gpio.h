/*
Copyright (c) 2012 Ben Croston / 2012-2013 Eric PTAK

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#define SETUP_OK          0
#define SETUP_DEVMEM_FAIL 1
#define SETUP_MALLOC_FAIL 2
#define SETUP_MMAP_FAIL   3
#define SETUP_CPUINFO_FAIL 4
#define SETUP_NOT_RPI_FAIL 5

#define GPIO_COUNT 54

#define IN		0
#define OUT		1
#define ALT5	2
#define ALT4	3
#define ALT0	4
#define ALT1	5
#define ALT2	6
#define ALT3	7
#define PWM		8

#define LOW		0
#define HIGH	1

#define PUD_OFF  0
#define PUD_DOWN 1
#define PUD_UP   2

#define RATIO 1
#define ANGLE 2

//thor
#define BCM2708_PERI_BASE_DEFAULT   0x20000000
#define BCM2709_PERI_BASE_DEFAULT   0x3f000000
//thor
#define PAGE_SIZE  (4*1024)
#define BLOCK_SIZE (4*1024)

struct pulse {
	int type;
	float value;
	float freq;
};

int setup(void);
int get_function(int gpio);
void set_function(int gpio, int function, int pud);
int input(int gpio);
void output(int gpio, int value);
void outputSequence(int gpio, int period, char* sequence);
struct pulse* getPulse(int gpio);
void pulseMilli(int gpio, int up, int down);
void pulseMilliRatio(int gpio, int width, float ratio);
void pulseMicro(int gpio, int up, int down);
void pulseMicroRatio(int gpio, int width, float ratio);
void pulseAngle(int gpio, float angle);
void pulseRatio(int gpio, float ratio);
void enablePWM(int gpio);
void disablePWM(int gpio);
int isPWMEnabled(int gpio);

// thor
void setFrequency(int gpio, float freq);
float getFrequency(int gpio);

// thor
void set_pullupdn(int gpio, int pud);
int number_of_cores(void);

void cleanup(void);

