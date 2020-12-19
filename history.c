/* File:			history.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of history.h
 *
 * Date created:	12-11-2020-9:36-PM
 */


#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct history{
	char *history_string;
	struct history *next_history;
}history;


typedef struct history history_list;


history_list *chl;


void add_new_history(char *command_string){
	history_list *new_chl = malloc(sizeof(history_list)),
				 *old_chl = chl;

	if(old_chl == NULL){
		new_chl->history_string = malloc(sizeof(char) * (strlen(command_string) + 1));
		strcpy(new_chl->history_string, command_string);
		new_chl->next_history = NULL;
	}else{
		new_chl->history_string = malloc(sizeof(char) * (strlen(command_string) + 1));
		strcpy(new_chl->history_string, command_string);
		new_chl->next_history = old_chl;
	}

	chl = new_chl;
}


void clear_history(void){
	int history_count;

	history_count = get_history_count();
	while(history_count != 0){
        if(history_count == 1){
            chl = NULL;
            break;
		}
		delete_last_history();
		history_count = get_history_count();
	}
}


void delete_last_history(void){
	history_list *to_delete_history,
				 *updated_history;

	to_delete_history = chl;

	while(to_delete_history->next_history != NULL){
		updated_history = to_delete_history;
		to_delete_history = to_delete_history->next_history;
	}

	updated_history->next_history = NULL;
	to_delete_history = NULL;
	free(to_delete_history);
}


void free_history(void){
	clear_history();
	free(chl);
}


int get_history_count(void){
	int history_count = 0;

	history_list *count_hl = chl;

	while(count_hl != NULL){
		count_hl = count_hl->next_history;
		history_count++;
	}

	return history_count;
}


char *get_history_item(int history_index){
	char *copy_of_history_item = NULL;
	history_list *get_hli = chl;

	if(get_hli != NULL){

		int hl_index = 1;
		while(get_hli != NULL){
			if(hl_index == history_index){
				copy_of_history_item = get_hli->history_string;
				break;
			}
			get_hli = get_hli->next_history;
			hl_index++;
		}

	}

	return copy_of_history_item;
}


void init_history(void){
	chl = malloc(sizeof(history_list));
	chl = NULL;
}


void print_history_item(int history_index){
	printf("History item in index [%i]\n", history_index);

	history_list *print_hli = chl;

	int hl_index = 1;
	while(print_hli != NULL){
		if(hl_index == history_index){
			printf("> %s\n\n", print_hli->history_string);
			break;
		}
		print_hli = print_hli->next_history;
		hl_index++;
	}

	if(print_hli == NULL){
		printf("Error: Index specified is out of range!\n\n");
	}
}


void print_history_list(void){
	printf("History list:\n");

	history_list *print_hl = chl;

	short history_index = 1;
	while(print_hl != NULL){
		printf("[%d]\t%s\n", history_index, print_hl->history_string);
		print_hl = print_hl->next_history;
		history_index++;
	}

	printf("\n");
}


