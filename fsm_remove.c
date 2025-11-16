
#include <stdio.h>
#include <string.h>
#include "fsm.h"

int state_remove (struct fsm_list *array[], char NewName[]){

    struct fsm_list cpy[128];

    int i = 0;

    int j = 0;
    
    while((*array[i]).name[0] != '\0'){
	    
	    if(strncmp((*array[i]).name, NewName, 64) != 0){ 
	        
	        strcpy(cpy[j].name, (*array[i]).name);
	        
	        cpy[j].action = (*array[i]).action;
	        
	        cpy[j].fptr = (*array[i]).fptr;
	        
	        cpy[j].next_ptr = (*array[i]).next_ptr;
	        
	        printf("name: %s\n",cpy[j].name);
	        
	        printf("action: %d\n",cpy[j].action);
	        
	        *(cpy[j].link + 0) = &(*array[i]->link[0]);
	        
	        *(cpy[j].link + 1) = &(*array[i]->link[1]);
	        
	        *(cpy[j].link + 2) = &(*array[i]->link[2]);
	        
	        j = j + 1;
	    }
	    
	    i = i + 1;

	}

    	(*array[i-1]).name[0] = '\0';

	(*array[i-1]).action = 0;

	(*array[i-1]).next_ptr = NULL;

	(*array[i-1]).fptr = NULL;

	int k = 0;

	while(cpy[k].name[0] != '\0'){

	   (array[k]) = &cpy[k];
		k = k + 1;
	}

	return 0;

}
