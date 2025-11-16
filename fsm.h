

#ifndef FSM_H
#define FSM_H




struct fsm_list{

	char name[64];

	int action;

	int *next_ptr;

	int(*fptr)(struct fsm_list*, float);

	struct fsm_list *link[3];

};

void fsm_init(struct fsm_list *array[]);

int state_add(struct fsm_list *array[], char NewName[], int NewAction);

int state_remove(struct fsm_list *array[], char NewName []);

float fsm_process(struct fsm_list *array[], float arg);

struct fsm_list * state_find(struct fsm_list *array[], char NewName[]);

void fsm_print(struct fsm_list *array[]);

int actionfcn(struct fsm_list *fsm, float arg);

int state_add_link(struct fsm_list *array[], char NewName[], char NextName[], int index);

int state_add_action(struct fsm_list *array[], char NewName[], int (*af)(struct fsm_list*, float));

int state_add_link(struct fsm_list *array[], char NewName[], char NextName[], int index);




#endif
