/* File:			builtin-cmd.h
 *
 * Author:			Radoq10288
 *
 * Description:		Contains functions to execute specific sShell
 *					commands.
 *
 * Date created:	12-16-2020-3:12-PM
 */


#ifndef _BUILTINCMD_H_
#define _BUILTINCMD_H_

/* Descripition:	Changes or display the current directory.
 *
 * Parameter:		String of absolute directory path or directory
 *					name. In case of absolute directory path, 
 *
 * Return:
 */
int change_directory(char *cd_arguments);


/* Descripition:	Specific command to exit sShell.
 *
 * Parameter: 
 *
 * Return:			Return 0 to indicate sShell exit normally.
 */
int exit_shell(void);

#endif // _BUILTINCOMMANDS_H_


