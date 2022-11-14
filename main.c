//build with "gcc -o main main.c ~/bcm2835-1.71/src/bcm2835.c -lm"

#include <bcm2835.h>
#include <stdio.h>
#include <math.h>

// Runs on RPi pin 11 (which is GPIO pin 17)
// Time scaled stepper accel for high torque applications
#define PIN RPI_GPIO_P1_12

void main(){

    if (!bcm2835_init())
      return;

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    // Blink
    while (1){
        int time_total = 1000; //1000 ms of total startup time 
        int step_time = 1;
        int step_val;

        while (1){
            step_val = 20*sin(0.01*step_time)+21;

            printf("Step val: %d",step_val);
            printf("\n");
                
            // Turn it on
            bcm2835_gpio_write(PIN, HIGH);
            
            // wait a bit
            bcm2835_delayMicroseconds(step_val);
            
            // turn it off
            bcm2835_gpio_write(PIN, LOW);
            
            // wait a bit
            bcm2835_delayMicroseconds(step_val);
            

            step_time = step_time + step_val;

        }
    }
    bcm2835_close();
    return;
}
