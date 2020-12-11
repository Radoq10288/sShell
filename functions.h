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


/* File:			functions.h
 *
 * Author:			Radoq10288
 *
 * Date created:	12-09-2020-8:25-PM
 */


#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

/* Description:	Reads string from stdin. This function scan the
 *				string until newline character is encountered.
 *
 * Parameter:
 *
 * Return:		Returns NULL terminated string.
 */
char *read_string(void);


/* Description:	Split a string delimited by character into individual
 *				words.
 *
 * Parameter:	string - string composed of multiple words
 *						 delimited by space.
 *				delimeter - character that separates each word in a
 *							string.
 *
 * Return:		Returns an array of individual words that compose
 *				*string*.
 */
char **parse_string(char *string, char *delimeter);


/* Description:	Executes string of command.
 *
 * Parameter:	*command_string - the string of command with its
 *								  corresponding arguments.
 *
 * Return:		Returns 1, if it successfully executes command.
 *				Return -1, if it fails to execute the command or it
 *				doesn't support the command specified. Return 0, if
 *				'exit' command is executed.
 */
int exec_command(char *command_string);

#endif // _FUNCTIONS_H_


