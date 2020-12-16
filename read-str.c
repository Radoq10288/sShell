/* File:			read-str.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of read-str.h
 *
 * Date created:	11-11-2020-2:57-PM
 */


#include "read-str.h"
#include <stdio.h>
#include <stdlib.h>


char *command_string;


// Frees memory block allocated by malloc()
void free_mem_rs(void){
	command_string = NULL;
	free(command_string);
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
	atexit(free_mem_rs);

	return command_string;

}


