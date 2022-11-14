// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $

//build with "gcc -o blink blink.c -l bcm2835 -lm"

#include <bcm2835.h>
#include <stdio.h>
#include <math.h>

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_12

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init())
      return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    // Blink
    while (1)
    {

    int step_time = 1;
    int step_val;

    while (1)
    {
    step_val = 20*sin(0.01*step_time)+21;

    printf("Step val: %d",step_val);
    printf("\n");
        
	// Turn it on
	bcm2835_gpio_write(PIN, HIGH);
	
	// wait a bit
	bcm2835_delay(step_val);
	
	// turn it off
	bcm2835_gpio_write(PIN, LOW);
	
	// wait a bit
	bcm2835_delay(step_val);
    

    step_time = step_time + step_val;
    }
    }
    bcm2835_close();
    return 0;
}

