#include <stdio.h>
#include <math.h>

void get_time(int time){ 
int hour = (time/60)/60;
int mins =  (time/60) - hour*60;
int sec = time - hour*60*60 - mins*60; 


printf ("%.2d: %.2d: %.2d\n",hour, mins ,sec);
}

float taxi_fare(int weekday, int start_time, int duration, int distance) {

int day = weekday;
int time = start_time * 60;
int init_dist = 0;
int fare = 340;
int dist_counter 


while (init_dist < distance ){ 

    time += 6;
    if (time>=86400){ 
        time = time%86400;
        if (weekday < 7){
        weekday++;
        } else if(weekday = 7) { 
        weekday = 1;
        }
    }
    init_dist += 50;
    if (init_dist >= 1000 && init_dist <= 10000){
        if (init_dist )
    }
}
get_time(time); 
printf("%d\n", init_dist);

return 0.0;
}

int main(void) {

    double fare = taxi_fare(1, 17*60 + 59, 6, 1000);
    printf("The taxi fare is: $%.3f", fare);
    return 0;
}