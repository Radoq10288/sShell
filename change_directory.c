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


/* File:			change_directory.h
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of change_directory.h
 *
 * Date created:	12-09-2020-10:43-PM
 */


#include "change_directory.h"
#include "functions.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


/* Description:	Function to set directory location of the current
 *				process.
 *
 * Parameter:	dir_name - Directory name or the absolute directory
 *						   path.
 *
 * Return:		Function returns 1, if it succeed to change to the
 *				specified directory. Else, it returns negative value.
 */
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

		// If switching to a new directory on the current directory.
		char *new_current_directory = NULL;
		new_current_directory = current_directory;
		strcat(new_current_directory, "\\");
		strcat(new_current_directory, dir_string);
		cdt_status = SetCurrentDirectory(new_current_directory);

	}

	// Change cdt_status value to negative value.
	if(cdt_status == 0){
		cdt_status = -1;
	}

	return cdt_status;
}


/* Description:	Function to move back to previous or to parent
 *				directory from the current directory.
 *
 * Parameter:
 *
 * Return:		Return the following values:
 *				- negative value, if it fails to move back to to
 *				  previous or to parent directory from the current
 *				  directory.
 *				- non-negative value, if function succeed to move
 *				  back to previous or to parent directory from the
 *				  current directory.
 */
int change_dir_to_parent(void){
	// change_dir_to_parent() status.
	int mofd_status;

	// To determine required string size.
	DWORD string_size;
	string_size = GetCurrentDirectory(0, NULL);

	// Get the current directory
	TCHAR current_directory[string_size];

	if(!GetCurrentDirectory(string_size, current_directory)){
		mofd_status = -1;
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
			mofd_status = -1;
		}else{
			mofd_status = 1;
		}
	
	}

	return mofd_status;
}


/* Description:		A windows only function to display the current
 *					directory.
 *
 * Parameter:
 *
 * Return value:	Returns the following values:
 *					- negative value, if it fails to display the
 *					  current directory.
 *					- non-negative value, that indicates the length
 *					  of the current directory string, if current
 *					  directory is printed successfully.
 */
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


int change_directory(char *cd_arguments){
	int cd_status;

	short string_length;
	string_length = strlen(cd_arguments);

	char cd_arguments_array[string_length];
	strcpy(cd_arguments_array, cd_arguments);

	char **parsed_command_string;
	parsed_command_string = parse_string(cd_arguments_array, " ");

	if(strcmp(parsed_command_string[0], "cd") == 0 && parsed_command_string[1] == NULL){
		cd_status = print_cur_dir();

	}else if(strcmp(parsed_command_string[1], "..") == 0 && parsed_command_string[2] == NULL){
		cd_status = change_dir_to_parent();

	}else{

		cd_status = change_dir_to(parsed_command_string[1]);

		if(cd_status == -1){
			printf("\'%s\' directory or root directory does not exist.\n\n",
					parsed_command_string[1]);
		}

	}

	return cd_status;
}


