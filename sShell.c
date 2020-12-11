/* sShell (simple-Shell) - a personal project to teach myself to build a
 *						   shell.
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


#include "functions.h"
#include <stdio.h>
#include <string.h>


int main(){

	// sShell notice
	//system("cls");
	printf("sShell (simple-Shell) version 0.1.0, Copyright (C) 2020 Radoq10288\n"
			"sShell comes with ABSOLUTELY NO WARRANTY.\n"
			"This is free software, and you are welcome to redistribute it\n"
			"under certain conditions.\n\n\n");

	// Load config files, if any.

	// Shell loop.
	char *command_string = NULL;
	int sShell_status = -1;

	while(sShell_status != 0){

		sShell_status = -1;

		printf("sShell>");
		command_string = read_string();
		if(strcmp(command_string, "") != 0){
			sShell_status = exec_command(command_string);
		}
		
		command_string = NULL;

	}

	// Perform any shutdown/cleanup.

	return 0;
}


