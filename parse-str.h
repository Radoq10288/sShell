/* File:			parse-str.h
 *
 * Author:			Radoq10288
 *
 * Date created:	11-11-2020-2:57-PM
 */


#ifndef _PS_H_
#define _PS_H_

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

#endif // _PS_H_


