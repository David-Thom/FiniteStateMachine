
#include <stdio.h>
#include <string.h>
#include "fsm.h"

int state_add(struct fsm_list *array[], char NewName[], int NewAction){
    
    int i = 0;
    
    while((*array[i]).name[0] != '\0'){
        
        i = i + 1;
    }
    
    
    if(i > 128){
        
        return -1;
    }
        
    strcpy((*array[i]).name, NewName);
    
    (*array[i]).action = NewAction;
    
    (*array[i]).fptr = NULL;
    
    (*array[i]).next_ptr = &(*array[i+1]).action;
     
     
		
}

