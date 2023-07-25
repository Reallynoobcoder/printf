#include "main.h"

/**
 * _putchar - Write a character to the standard output.
 *
 * Write the character 'c' to the standard output (file descriptor 1).
 *
 * @c: The character to be written.
 *
 * Return: On success, returns 1. On error, returns -1 and sets errno.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
