/*
Name: <Thompson, Diekololaoluwa>
NSID: <scb597>
Student Number: <11351837>
Course: CMPT214 -<02> 2025
*/


#include <stdio.h>
#include <string.h>
#include "fsm.h"

float fsm_process(struct fsm_list *array[], float arg){
     
    int index = 0;
    
    int i = 0;
    
    int boo = 0;
    
    while((*array[i]).name[0] != '\0'){
        
        if((*array[i]).fptr != NULL){
           
            boo = 1;
            
            break;
        }
        
        i = i + 1;

    }

    if(boo == 1){

        index = (*array[i]).fptr(&(*array[i]), arg);

        printf("index: %d\n", index);

    }

    else if(boo == 0){

       return arg;

    }

    while(((2 >= index) && (0 <= index)) && ((*array[i]).link[index]) != NULL){

       int top = 0;

       int bottom = 0;

       top = (*array[i]).action * arg;

       bottom = index + 1;

       arg = top / bottom;

       index = (*array[i]).fptr(&(*array[i]), arg);

       if(arg == 0){

        return arg;

       }

       
    }
    
    return arg;
}
	
    


