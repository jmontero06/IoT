#include "virtual_sensor_p1.h"
#include <stdio.h>
#include <stdlib.h>

float random_value(float min,float max){
    float scale=rand()/(float) RAND_MAX;
    return min + scale*(max-min);
}

void adjust_temperature(float temp_min, float temp_max){

    float num=random_value(-20,50);
    if(num<temp_min){
        printf("ajustando la temperatura a lo minimo");
    }
    if(num>temp_max){
        printf("ajustando la temperatura a lo maximo");
    }
}