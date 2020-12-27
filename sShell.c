/* sShell - simple shell.
 * Copyright (C) 2020  Radoq10288
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * For any questions regarding this program, you drop an email
 * @ Raffy10288@yahoo.com.ph.
 */


/* File:			sShell.c
 *
 * Author:			Radoq10288
 *
 * Description:		sShell (simple Shell): a simple project to teach
 *					myself on how to build a shell.
 *
 * Credits:			Credits to "Tutorial - Write a Shell in C
 *					Stephen Brennan • 16 January 2015".
 *					For the Shell loop.
 *
 * Date created:	11-14-2020-9:12-PM
 */


#include "exec-cmd.h"
#include "history.h"
#include "read-str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

	// Initialize
	init_history();

	// sShell notice
	printf("sShell (simple-Shell) version 0.1.0, Copyright (C) 2020 Radoq10288\n"
			"sShell comes with ABSOLUTELY NO WARRANTY.\n"
			"This is free software, and you are welcome to redistribute it\n"
			"under certain conditions.\n\n\n");

	// Load config files, if any.

	// Shell loop.
	char *command_string,
         *command_string_copy;
	int sShell_status = -1, cs_size = 0, history_count;

	while(sShell_status != 0){

		sShell_status = -1;

		printf("sShell>");
		command_string = read_string();

        cs_size = strlen(command_string);
        command_string_copy = malloc(sizeof(char) * cs_size);
        strcpy(command_string_copy, command_string);

		if(command_string != NULL){

            sShell_status = exec_command(command_string);
			add_new_history(command_string_copy);

			history_count = get_history_count();
			if(history_count > 10){

				while(history_count > 10){
					delete_last_history();
					history_count = get_history_count();
				}

			}

			if(strcmp(command_string_copy, "history") == 0){ print_history_list(); }

		}

		command_string = NULL;
		command_string_copy = NULL;
		free(command_string_copy);

	}

	// Perform any shutdown/cleanup.
	free_history();
	free(command_string);

	return 0;
}


