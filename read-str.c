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

		if(character != '\n'){
            command_string[character_index] = character;
		}else{
		    command_string[character_index] = '\0';
		}
		character_index++;

		// When rs_buffer_size exceeds, it should be reallocated.
		if(character_index >= rs_buffer_size){
            rs_buffer_size += rs_buffer_size;
            command_string = realloc(command_string, rs_buffer_size);

            if(!command_string){
                printf("Error: Reallocation failed!\n\n");
                exit(EXIT_FAILURE);
            }

		}

	}while(character != '\n');

	// Set NULL to terminate the string
	command_string[character_index] = '\0';

	/* Free allocated block of memory to *command_string* after its value
	 * is returned.
	 */
	atexit(free_mem_rs);

	return command_string;

}


