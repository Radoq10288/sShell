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
 * Parameter:		String of absolute directory path delimited by
 *					backslash or directoryname.
 *
 * Return:			Return 1 if command is executed succesfully. Else
 *					if it fails, return -1.
 */
int change_directory(char *cd_arguments);


/* Descripition:	Command to exit sShell.
 *
 * Parameter:
 *
 * Return:			Return 0 to indicate sShell exit normally.
 */
int exit_shell(void);


/* Descripition:	Display list of history, specific command history,
 *					clear history list, and execute specific previous
 *					sShell command.
 *					Note: sShell history retains history of 10
 *					previously used sShell command.
 *
 * Parameter:		The following are arguments for sShell_history():
 *					"history" = display history list of previously
 *								used sShell commands.
 *					"-c" = clears the current history.
 *					"N" = where 'N' is a number, display the prior
 *						   N-th command starting with the last one.
 *					"N -e" = executes the prior N-th command.
 *
 * Return:			Return 1 if command is executed succesfully> Else
 *					return -1.
 */
int history(char *hs_argument_1, char *hs_argument_2);

#endif // _BUILTINCOMMANDS_H_


