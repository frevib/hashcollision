#include <stdio.h>
#include <limits.h>
#include <iostream>
#include "timer.h"

int max_array(int *intarr, int intarr_length);
int min_array(int *intarr, int intarr_length);
int exists_in_array(int intarr[], int number);
int hashme(char* morse);

// Take morse char* and return number
int hashme(char* morse) {
    int total = 0;
    
    // This is the algorithm!!
    for(int i=0 ; *morse; morse++, i++) {
        //total += ((*morse - '0') << i); // 0 collisions, max nr 7645
        //total += ((*morse - '0') * (i+2)); // 1 collision, max nr 83
        total += ((*morse - '0') * (i+2));
    }
    return total;
}

// The morse codes
int main() {
    
    char* arr[27] = {
        "10111",		//a
        "111010101",	//b
        "11101011101",	//c
        "1110101",		//d
        "1",			//e
        "101011101",	//f
        "111011101",	//g
        "1010101",		//h
        "101",			//i
        "1011101110111",//j
        "111010111",	//k
        "101110101",	//l
        "1110111",		//m
        "11101",		//n
        "11101110111",	//o
        "10111011101",	//p
        "1110111010111",//q
        "1011101",		//r
        "10101",		//s
        "111",			//t
        "1010111",		//u
        "101010111",	//v
        "101110111",	//w
        "11101010111",	//x
        "1110101110111",//y
        "11101110101"	//z
    };
    
    // Iterate all letters, 'iteration' amount of times:
    int iterations = 200000;
    
    CStopWatch guestimate;
    guestimate.startTimer();
    
    int i = 0;
    int intarr[27];
    for(int x=0;x < iterations; x++) {
        // Loop through the morse codes, the zero's and one's
        i = 0;
        while(i < 26) {
            intarr[i] = hashme(arr[i]);
            i++;
        }
    }
    
    guestimate.stopTimer();
    std::cout << "Time hashing: " << guestimate.getElapsedTime() << std::endl;
    
    //check for duplicates (collisions)
    int m = 0, n = 0;
    int p = 0, q = 0;
    int collisions = 0;
    int intarr_length = (int)(sizeof(intarr)/sizeof(intarr[0]));
    int collision_nr[20];
    int collision_char_nr[20];
    while(m < intarr_length) {
        while(n < intarr_length) {
            if(m == n) {
                n++;
            }
            else if(intarr[m] == intarr[n]) {
                collisions++;
                collision_nr[p++] = intarr[m];
                collision_char_nr[q++] = m;
                collision_char_nr[q++] = n;
                n++;
            }
            else {
                n++;
            }
        }
        m++;
        n = m;
    }
    collision_nr[++p] = '\0';
    collision_char_nr[q] = '\0';
    m = 0;
    
    printf("collissions: %d\n", collisions);
    
    printf("Collision nr's: ");
    for(int i=0;collision_nr[i]; i++) {
        printf("%d,", collision_nr[i]);
    }
    
    printf("\ncollision char nr's: ");
    for(int i=0;collision_char_nr[i]; i++) {
        printf("%c,", collision_char_nr[i]+96);
    }
    
    // Give minimum int of intarr
    int min = min_array(intarr, intarr_length);
    printf("\nmin number: %d\n", min);
    
    // Give maximum int of intarr
    int max = max_array(intarr, intarr_length);
    printf("max number: %d\n", max);
}

// Return minimum number of array
int min_array(int intarr[], int intarr_length) {
    int i, min=32000;
    for(i=0; i < intarr_length - 1; i++) {
        if(intarr[i] < min) {
            min = intarr[i];
        }
    }
    return min;
}

// Return maximum number of array
int max_array(int intarr[], int intarr_length) {
    int i, max=0;
    for(i=0; i < intarr_length - 1; i++) {
        if(intarr[i] > max) {
            max = intarr[i];
        }
    }
    return max;
}
