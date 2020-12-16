/* Files:			exec-cmd.h
 *
 * Author:			Radoq10288
 *
 * Date created:	12-09-2020-8:32-PM
 */


#ifndef _EXECCMD_H_
#define _EXECCMD_H_

/* Description:	Executes string of command.
 *
 * Parameter:	*command_string - the string of command with its
 *								  corresponding arguments.
 *
 * Return:		Returns the following values:
 *				-  1 = if it successfully executes command.
 *				- -1 = if it fails to execute the command or it
 *					   doesn't support the command specified.
 *				-  0 = indicates 'exit' command is executed.
 */
int exec_command(char *command_string);

#endif // _EXECCMD_H_


