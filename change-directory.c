/* File:			change_directory.c
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of change-directory.h
 *
 * Date created:	12-09-2020-10:24-PM
 */


#include "change-directory.h"
#include "parse-str.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


int change_dir_to(char *dir_string){
	int cdt_status;

	// To determine required string size.
	DWORD cur_dir_size;
	cur_dir_size = GetCurrentDirectory(0, NULL);

	// Get the current directory.
	TCHAR current_directory[cur_dir_size];

	/* Change drive letter to uppercase when user provided small
	 * letter for character comparison purpose.
	 */
	char drive_letter = dir_string[0];
	if(islower(drive_letter)){
		drive_letter = toupper(drive_letter);
	}

	if(!GetCurrentDirectory(cur_dir_size, current_directory)){
        cdt_status = -1;

	}else if(strcmp(current_directory, dir_string) == 0){
		cdt_status = 1;

	}else if(current_directory[0] == drive_letter &&
			current_directory[1] == dir_string[1]){
		/* If changing absolute directory path in the same root
		 * directory.
		 */
		cdt_status = SetCurrentDirectory(dir_string);
	
	}else if(current_directory[0] != drive_letter &&
			current_directory[1] == dir_string[1]){
		// If changing root directory.
		cdt_status = SetCurrentDirectory(dir_string);

	}else{

		int dir_string_length = strlen(dir_string);

		// If switching to a new directory on the current directory.
		char *new_current_directory = malloc(sizeof(char) * dir_string_length + cur_dir_size + 1);
		strcpy(new_current_directory, current_directory);
		strcat(new_current_directory, "\\");
		strcat(new_current_directory, dir_string);
		cdt_status = SetCurrentDirectory(new_current_directory);

		new_current_directory = NULL;
		free(new_current_directory);

	}

	// Change cdt_status value to negative value.
	if(cdt_status == 0){
		cdt_status = -1;
	}

	return cdt_status;
}


int change_dir_to_parent(void){
	// change_dir_to_parent() status.
	int cdtp_status;

	// To determine required string size.
	DWORD string_size;
	string_size = GetCurrentDirectory(0, NULL);

	// Get the current directory
	TCHAR current_directory[string_size];

	if(!GetCurrentDirectory(string_size, current_directory)){
		cdtp_status = -1;
	}else{

		// Parse each directory name from current_directory.
		char **parsed_cur_dir_string;
		parsed_cur_dir_string = parse_string(current_directory, "\\");

		// Count how many directory including the drive letter.
		short num_of_dir = 0;
		while(parsed_cur_dir_string[num_of_dir] != NULL){
			num_of_dir++;
		}

		/* To remove a slash ('\') and the directory name from the
		 * right-most part of the string.
		 */
		num_of_dir = (num_of_dir * 2) - 2;

		TCHAR new_current_directory[num_of_dir];

		/* Reconstruct the directory path removing the current
		 * directory name.
		 */
		short dir_index = 0,
			  total_index = 0;
		new_current_directory[0] = '\0';

		while(total_index != num_of_dir){

			/* Every 'odd' number value of total_index, a slash
			 * ('\') character is added to the end of the
			 * new_current_directory.
			 * Every  'even' number value of total_index, a
			 * directory name is added to the end of the
			 * new_current_directory.
			 */
			if((total_index % 2) != 0){
				strcat(new_current_directory, "\\");
			}else{
				strcat(new_current_directory, parsed_cur_dir_string[dir_index]);
				dir_index++;
			}

			total_index++;
		}

		// Set end of directory path string to NULL.
		strcat(new_current_directory, "\0");

		// Set the new current directory.
		if(!SetCurrentDirectory(new_current_directory)){
			cdtp_status = -1;
		}else{
			cdtp_status = 1;
		}
	
	}

	return cdtp_status;
}


int print_cur_dir(void){
	// printf_cur_dir() status
	short print_status;

	// To determine required string size.
	DWORD string_size;
	string_size = GetCurrentDirectory(0, NULL);

	// Get the current directory
	TCHAR current_directory[string_size];
	print_status = GetCurrentDirectory(string_size, current_directory);

	if(print_status == 0){ print_status = -1; }

	// Display the current directory
	printf("> %s\n\n", current_directory);

	return print_status;
}


