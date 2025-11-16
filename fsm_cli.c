

#include <stdio.h>
#include <string.h>
#include "fsm.h"


int actionfcn(struct fsm_list *fsm, float arg){
    
    int ans = 0;
    
    int a = ((*fsm).action * arg);
    
    int b = 3;
    
    ans = a % b;

    return ans;
    
}


int state_add_action(struct fsm_list *array[], char NewName[], int (*af)(struct fsm_list*, float)){

    int actf = 0;

    int i = 0;

    while((*array[i]).name[0] != '\0'){

        if(strncmp((*array[i]).name, NewName, 20) == 0){

            (*array[i]).fptr = &actionfcn;

            return 0;

        }

        i = i + 1;
    }

    return -1;

}

int state_add_link(struct fsm_list *array[], char NewName[], char NextName[], int index){

    int i = 0;

    while((*array[i]).name[0] != '\0'){

        if(strncmp((*array[i]).name, NewName, 64) == 0){

            (*array[i]).link[index] = &(*state_find(array, NextName));

            return 0;

        }

        i = i + 1;
    }


    return -1;
}



int main(){

    struct fsm_list *ptr[128];

	char toggle[] = "on";

	fsm_init(ptr);

	while(strncmp(toggle, "on", 10) == 0){

	    char choice [10];

		printf("\nPress input an option: ");

		printf("\nPress 'a' to add: ");

		printf("\nPress 'f' to find: ");

		printf("\nPress 'r' to remove: ");

		printf("\nPress 'l' to link: ");

		printf("\nPress 'y' to process: ");

		printf("\nPress 'p' to print: ");

		printf("\nPress 'q' to quit: ");

		scanf("%s", &choice);


		if(strncmp(choice, "a", 10) == 0){

			char Newname[64];

			int Newaction;

			printf("Please input name of new state: \n");

			scanf("%s", &Newname);

			printf("Please input action for new state: \n");

			scanf("%d", &Newaction);

			state_add(ptr, Newname, Newaction);

			state_add_action(ptr, Newname, actionfcn);
		}

		else if(strncmp(choice, "f", 10) == 0){

			char Newname[64];

			printf("Please input name of state to find: \n");

			scanf("%s", &Newname);

			if(state_find(ptr,Newname) != NULL){

				printf("%d\n", (*state_find(ptr,Newname)).action);
			}

			if(state_find(ptr, Newname) == NULL){

				printf("State not found\n");

			}
		}

	    else if (strncmp(choice, "r", 10) == 0){

			char Newname[64];

			printf("Please input name of state to remove: \n");

			scanf("%s", &Newname);

			if(state_remove(ptr, Newname) != -1){

				printf("success\n");

			}

			else{

				printf("fail\n");

			}
		}

		else if (strncmp(choice, "l", 10) == 0){

		    char Newname1[64];

		    printf("Please input name of state one to link: \n");

		    scanf("%s", &Newname1);

		    char Newname2[64];

		    printf("Please input name of state two to link: \n");

		    scanf("%s", &Newname2);

		    int index = 0;

		    printf("Please input index postion: \n");

		    scanf("%d", &index);


		    if((state_find(ptr, Newname1) == NULL) || (state_find(ptr, Newname2) == NULL)){

		        printf("fail\n");

		    }

		    else{

		        state_add_link(ptr,Newname1, Newname2,index);

		        printf("success\n");

		    }



		}
		else if(strncmp(choice, "y", 10) == 0){

			float argument;

			printf("Please input 'arg' value: \n");

			scanf("%f", &argument);

			printf("%f", fsm_process(ptr, argument));
		}
		else if(strncmp(choice, "p", 10) == 0){

			fsm_print(ptr);
		}

		else if(strncmp(choice, "q", 10) == 0){

			printf("Goodbye!\n");

			toggle[0] = '\0';

			break;

		}
		else{

			printf("Incorrect input selection...\n");
			printf("Try again. \n");
		}




	}




    return 0;
}

