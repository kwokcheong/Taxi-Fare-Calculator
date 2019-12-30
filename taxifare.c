/* Incremental coding
1. Compute out basic fare for 400 & 350, find Fare.
2. Add in distance and stop when exceed 10km for both.
3. Add in time start and time end. Increment the time based on speed.
4. Add in the surcharge (based on time) presume all daily
5. Add in the monday - fri. */

#include <stdio.h>

double taxi_fare(int weekday, int start_time, int duration, int distance) {
double fare =0.0;
int dist1, i, j;
double time = (double) start_time;
double surcharge = 1.0;


//Starting the time...
printf ("\nStarting time: %.2f", time );


//Initiate First 1km $3.40
if ( 0 <= time && time <= 359){ 
        fare = 3.4 * 1.5 ;
    } else if ( 360 <= time && time <= 539 ) { 
        if ( weekday >= 1 && weekday <= 5){
        fare = 3.4 * 1.25;
        } else { 
            fare = 3.4;
        }
    } else if ( 1080 <= time && time <= 1439) { 
        fare = 3.4 * 1.25;
    } else { 
        fare = 3.4;
    }
    printf ("\nStarting fare= %f", fare);
dist1 = distance - 1000;
time =time + (20 * (double) duration/60.0);
printf ("\nAfter 1km: Remaining %d m", dist1);

//1. 400m thereafter or less $0.22
//2. Adding in time, 50m per (input)sec
if (dist1 > 0 ){
for ( i=1; i<=25; i = i + 1 ){
    dist1 = dist1 - 400;
    //update time in mins

    if ( 0 <= time && time < 360){ 
        surcharge = 1.5;
    } else if ( 360 <= time && time <= 539 ) { 
        if ( weekday >= 1 && weekday <= 5){
        surcharge = 1.25;
        }
    } else if ( 1080 <= time && time <= 1439) { 
        surcharge = 1.25;
    } else { 
        surcharge = 1.00;
    }
    time = time + (8.0*((double)duration/60.0));
    printf ("\n Time is %.2f", time);
    printf("\n Surcharge is %.2f", surcharge);
    fare = fare + (0.22 * surcharge);
    if (dist1 < 0 ){ 
        break; 
    }
}

//350m thereafter or less $0.22
if (dist1 > 0) {
for (j=1; j<=29; j = j+1 ){ 
    dist1 = dist1 - 350;
    if ( 0.0 <= time && time < 360.0){ 
        surcharge = 1.5;
    } else if ( 360.0 <= time && time <= 539.0 ) { 
        if ( weekday >= 1 && weekday <= 5){
        surcharge = 1.25;
        }
    } else if ( 1080.0 <= time && time <= 1439.0) { 
        surcharge = 1.25;
    } else { 
        surcharge = 1.00;
    }
    time = time + (7.0*((double)duration/60.0));
    fare = fare + (0.22 * surcharge);
    if (dist1 < 0){ 
        break;
    }
}
}
}



return fare;
}

int main(void) {
    double fare;
    fare = taxi_fare(1, 17*60 + 59, 6, 1000);
    printf("\nThe taxi fare is: $%.3f", fare);
    return 0;
}