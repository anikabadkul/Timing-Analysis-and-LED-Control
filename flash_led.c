#include <stdio.h>
#include <unistd.h>
int main(){
    printf("\n LED Flash Start \n");
    FILE *LEDHandle = NULL;
// directory path to the 4th led's brighness file
    const char *LEDBrightness="/sys/class/leds/beaglebone:green:usr3/brightness";
// flash the led 10 times
    for(int i=0; i<10; i++){
// Open the file
// Read/Write only if the file pointer is not NULL
// Always check for this condition to avoid Segmentation fault
        if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
// Turn the led on
            fwrite("1", sizeof(char), 1, LEDHandle);
            fclose(LEDHandle);
// Close the led file
        }
// sleep for 10^6 microsecond or 1 second
        usleep(1000000);
// Open the file and check for the same condition as above
        if((LEDHandle = fopen(LEDBrightness, "r+")) != NULL){
            fwrite("0", sizeof(char), 1, LEDHandle);
// Close the led file
            fclose(LEDHandle);
// sleep again for 10^6 microsecond or 1 second
// Turn the led off
        }
        usleep(1000000);

    }

    printf("\n LED Flash End \n");
}