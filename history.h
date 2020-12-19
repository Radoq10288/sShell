/* File:			history.h
 *
 * Author:			Radoq10288
 *
 * Description:		Collection of functions to manipulate history of
 *					used commands in sShell.
 *
 * Credits:			Credits to a job posting in freelancer.com with
 *					the title "System programming with C and unix"
 *					for the creation of this collection of functions.
 *
 * Date created:	12-11-2020-9:36-PM
 */


#ifndef _HISTORY_H_
#define _HISTORY_H_


/* Description:	Adds new data in front of the linked-list.
 *
 * Parameter:	command_string
 *					- string of a shell command.
 *
 * Return:
 */
void add_new_history(char *command_string);


/* Description:	Clears history list.
 *
 * Parameter:
 *
 * Return:
 */
void clear_history(void);


/* Description:	Delete the last history in history list.
 *
 * Parameter:
 *
 * Return:
 */
void delete_last_history(void);


/* Description:
 *
 * Parameter:
 *
 * Return:
 */
void free_history(void);


/* Description:	To count the number of command used by user that is
 *				currently available in the history.
 *
 * Parameter:
 *
 * Return:		Returns the current count of command(s) entered by
 *				user.
 */
int get_history_count(void);


/* Description:
 *
 * Parameter:
 *
 * Return:
 */
char *get_history_item(int history_index);


/* Description:
 *
 * Parameter:
 *
 * Return:
 */
void init_history(void);


/* Description:
 *
 * Parameter:
 *
 * Return:
 */
void print_history_item(int history_index);


/* Description:	Prints the current command(s) list entered by the
 *				user of shell. Sorted from the latest to the first
 *				command used by user.
 *
 * Parameter:
 *
 * Return:
 */
void print_history_list(void);

#endif // _HISTORY_H_


