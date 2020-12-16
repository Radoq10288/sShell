/* File:			read-str.h
 *
 * Author:			Radoq10288
 *
 * Description:		Implementation of getline() function of
 *					POSIX C Library.
 *
 * Credits:			Credits to "Tutorial - Write a Shell in C
 *					Stephen Brennan • 16 January 2015"
 *					for read_string().
 *
 * Date created:	11-11-2020-2:57-PM
 */


#ifndef _READSTR_H_
#define _READSTR_H_

/* Description:	Reads string from stdin. This function scan the
 *				string until newline character is encountered.
 *
 * Parameter:
 *
 * Return:		Returns NULL terminated string.
 */
char *read_string(void);

#endif // _READSTR_H_


