/* File:			change_directory.h
 *
 * Author:			Radoq10288
 *
 * Description:		Contains windows only functions to change or
 *					display current directory of the current process.
 *
 * Date created:	12-09-2020-10:24-PM
 */


#ifndef _CHANGE_DIRECTORY_H_
#define _CHANGE_DIRECTORY_H_

/* Description:	Function to set directory location of the current
 *				process.
 *
 * Parameter:	dir_name - Directory name or the absolute directory
 *						   path.
 *
 * Return:		Function returns 1, if it succeed to change to the
 *				specified directory. Else, it returns -1.
 */
int change_dir_to(char *dir_string);


/* Description:	Function to move back to previous or to parent
 *				directory from the current directory.
 *
 * Parameter:
 *
 * Return:		Return 1, if function succeed to move back to
 *				previous or to parent directory from the current
 *				directory. Else, return -1.
 */
int change_dir_to_parent(void);


/* Description:		Function to display the current directory.
 *					(Windows only)
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
int print_cur_dir(void);

#endif // _CHANGE_DIRECTORY_H_


