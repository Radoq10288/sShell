/* File:			builtin-cmd.h
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of builtin-cmd.h
 *
 * Date created:	12-16-2020-3:12-PM
 */


#include "builtin-cmd.h"
#include "change-directory.h"
#include "parse-str.h"
#include <stdio.h>
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


