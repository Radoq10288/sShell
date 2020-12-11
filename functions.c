/* 
 * 
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


/* File:			functions.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of functions.h
 *
 * Credits:			Credits to "Tutorial - Write a Shell in C
 *					Stephen Brennan • 16 January 2015".
 *					Where the following functions read_string(),
 *					parse_string(), and exec_command() is based on.
 *
 * Date created:	12-09-2020-8:25-PM
 */


#include "change_directory.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Global Variables

// Used by read_string() function
char *command_string;
// Used by parse_string() function
char **parsed_string;


// Frees memory block allocated by malloc()
void free_mem(void){
	command_string = NULL;
	parsed_string = NULL;

	free(command_string);
	free(parsed_string);
}


char *read_string(void){

	char character;
	int character_index = 0,
		rs_buffer_size = 1024;

	// Allocate memory block of 1024
	command_string = malloc(sizeof(char) * rs_buffer_size);

	/* Count how many character is entered.
	 *
	 * Get each character from stdin and stored each character to
	 * *command_string.
	 */
	character_index = 0;
	do{
		character = getchar();

		/* TODO: 11-11-2020-3:20-PM ---------------------------------
		 * This function can handle length of string up to
		 * cs_buffer_size.
		 *
		 * To address this limitation, in future revision of this
		 * function, command_string should be reallocated when
		 * needed to avoid error.
		 * ----------------------------------------------------------
		 */

		if(character != '\n'){
            command_string[character_index] = character;
		}else{
		    command_string[character_index] = '\0';
		}
		character_index++;
	}while(character != '\n');

	// Set NULL to terminate the string
	command_string[character_index] = '\0';

	/* Free allocated block of memory to *command_string* after its value
	 * is returned.
	 */
	atexit(free_mem);

	return command_string;

}


char **parse_string(char *string, char *delimeter){

	char *ps_part;
	int ps_buffer_size = 64;
	short ps_index = 0;

	// Allocate memory block of 64
	parsed_string = malloc(sizeof(char) * ps_buffer_size);

	// Tokenize the string delimited by space
	ps_part = strtok(string, delimeter);
	while(ps_part != NULL){
		parsed_string[ps_index] = ps_part;
		ps_part = strtok(NULL, delimeter);

		/* TODO: 11-11-2020-10:03-PM --------------------------------
		 * *parsed_string* can handle up to *ps_buffer_size*
		 *
		 * To overcome this limitation and any error,
		 * parsed_string should be reallocated if initial
		 * allocated size is reached.
		 */

		ps_index++;
	}

	// Set null to the end of the string to terminate it
	parsed_string[ps_index] = NULL;

	/* Free allocated block of memory for *parsed_string* after
	 * its value is returned.
	 */
	atexit(free_mem);

	return parsed_string;

}


int exec_command(char *command_string){
	int ec_status;

	char **parsed_command_arguments;
	parsed_command_arguments = parse_string(command_string, " ");

	if(strcmp(parsed_command_arguments[0], "cd") == 0){
		
		char joined_arguments[1024];
		short word_index = 0;
		joined_arguments[0] = '\0';
		while(parsed_command_arguments[word_index] != '\0'){
			strcat(joined_arguments, parsed_command_arguments[word_index]);
			strcat(joined_arguments, " ");
			word_index++;
		}

		ec_status = change_directory(joined_arguments);

	}else if(strcmp(parsed_command_arguments[0], "exit") == 0){
		printf("Logout\n\n");
		ec_status = 0;

	}else{
		printf("\'%s\' is not recognized as sshell command.\n\n", parsed_command_arguments[0]);
		ec_status = -1;

	}

	return ec_status;
}


