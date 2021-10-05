#include "virtual_sensorp1.h"
#include <stdlib.h>
#include <stdio.h>

float random_value(float min,float max){
    float scale=rand()/(float) RAND_MAX;
    return min + scale*(max-min);
}
float read_temperature(){
    return random_value(0,35);
}