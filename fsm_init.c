 

#include <stdio.h>
#include <string.h>
#include "fsm.h"



void fsm_init(struct fsm_list *array[]){

	struct fsm_list s[128];

	for(int i = 0; i<128; i++){

		*(array + i) = &s[i];
	}

	for(int i = 0; i<128; i++){

		(*array[i]).name[0] = '\0';

	 	(*array[i]).action = 0;

		if(i + 1 != 128){

			(*array[i]).next_ptr = &(*array[i+1]).action;

		}

		if(i + 1 == 128){

			(*array[i]).next_ptr = NULL;

		}


	}



}
