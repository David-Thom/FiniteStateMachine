

#include <stdio.h>
#include <string.h>
#include "fsm.h"



struct fsm_list *state_find(struct fsm_list *array[], char NewName[]){
    
    int i = 0;
    
    while((*array[i]).name[0] != '\0'){
        
        if(strncmp((*array[i]).name, NewName, 64) == 0){

            return &(*array[i]);
        }
        
        i = i + 1;
    }

	return NULL;
}

void fsm_print(struct fsm_list *array[]){

	int i = 0;

	while((*array[i]).name[0] != '\0'){

		printf("%s ---> %d || %s, %s, %s\n\n", (*array[i]).name,(*array[i]).action ,(*array[i]->link[0]).name,(*array[i]->link[1]).name,(*array[i]->link[2]).name);

		i = i + 1;
	}
}
