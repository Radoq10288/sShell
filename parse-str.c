/* File:			parse-str.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of parse-str.h
 *
 * Date created:	11-11-2020-2:57-PM
 */


#include "parse-str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Global variable

// Used by sShell_split_string()
char **parsed_string;


// Frees memory block allocated by malloc()
void free_mem(void){
	parsed_string = NULL;
	free(parsed_string);
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

		ps_index++;
		
		if(ps_index >= ps_buffer_size){
			ps_buffer_size += ps_buffer_size;
			parsed_string = realloc(parsed_string, ps_buffer_size);

			if(!parsed_string){
				printf("Error: Reallocation failed!\n\n");
				exit(EXIT_FAILURE);
			}

		}

	}

	// Set null to the end of the string to terminate it
	parsed_string[ps_index] = NULL;

	/* Free allocated block of memory for *parsed_string* after
	 * its value is returned.
	 */
	atexit(free_mem);

	return parsed_string;

}


