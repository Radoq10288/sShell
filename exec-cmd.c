/* Files:			exec-cmd.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of exec-cmd.h
 *
 * Date created:	12-09-2020-8:32-PM
 */


#include "builtin-cmd.h"
#include "exec-cmd.h"
#include "parse-str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int exec_command(char *command_string){
	int ec_status;

	char **parsed_command_arguments;
	parsed_command_arguments = parse_string(command_string, " ");

	if(strcmp(parsed_command_arguments[0], "cd") == 0){

		if(parsed_command_arguments[1] == NULL){
			ec_status = change_directory(parsed_command_arguments[0]);
		}else{
			ec_status = change_directory(parsed_command_arguments[1]);
		}

	}else if(strcmp(parsed_command_arguments[0], "history") == 0){

		if(parsed_command_arguments[1] == NULL){
			ec_status = history(parsed_command_arguments[0], "");
		}else if(parsed_command_arguments[2] == NULL){
			ec_status = history(parsed_command_arguments[1], "");
		}else if(parsed_command_arguments[3] == NULL){
			ec_status = history(parsed_command_arguments[1], parsed_command_arguments[2]);
		}else{
			ec_status = -1;
		}

	}else if(strcmp(parsed_command_arguments[0], "exit") == 0){
		ec_status = exit_shell();

	}else{
		printf("\'%s\' is not recognized as sshell command.\n\n", parsed_command_arguments[0]);
		ec_status = -1;

	}

	return ec_status;
}


