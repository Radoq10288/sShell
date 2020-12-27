/* File:			builtin-cmd.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of builtin-cmd.h
 *
 * Date created:	12-16-2020-3:12-PM
 */


#include "builtin-cmd.h"
#include "change-directory.h"
#include "ctype.h"
#include "exec-cmd.h"
#include "history.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int change_directory(char *cd_arguments){
	int cd_status;

	if(strcmp(cd_arguments, "cd") == 0){
		cd_status = print_cur_dir();

	}else if(strcmp(cd_arguments, "..") == 0){
		cd_status = change_dir_to_parent();

	}else{

		cd_status = change_dir_to(cd_arguments);

		if(cd_status == -1){
			printf("\'%s\' directory or root directory does not exist.\n\n",
					cd_arguments);
		}

	}

	return cd_status;
}


int exit_shell(void){
	printf("Logout\n\n");
	return 0;
}


int history(char *hs_argument_1, char *hs_argument_2){
	int history_index = 0, hs_status;

	if(isdigit(*hs_argument_1) && strcmp(hs_argument_2, "-e") == 0){

		char *hs_command_copy;

		history_index = atoi(hs_argument_1);
		hs_command_copy = get_history_item(history_index);

		if(hs_command_copy != NULL){
            hs_status = exec_command(hs_command_copy);

		}else{
			printf("Command from index %i is not available!\n\n", history_index);
            hs_status = -1;

		}

	}else if(isdigit(*hs_argument_1)){
		history_index = atoi(hs_argument_1);
		print_history_item(history_index);
		hs_status = 1;

	}else if(strcmp(hs_argument_1, "-c") == 0){
		clear_history();
		printf("History cleared!\n\n");
		hs_status = 1;

	}else{
		hs_status = -1;

	}

	return hs_status;
}


