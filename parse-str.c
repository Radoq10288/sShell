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
void free_mem_ps(void){
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
	atexit(free_mem_ps);

	return parsed_string;

}


