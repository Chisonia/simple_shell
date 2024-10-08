#include "shell.h"

/**
 * _puts - a function which prints a string to stdout
 * @s: a string to print
 *
 * Return: the length of the string
 */
int _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * _printf - a function that produces output according to a format
 * @format: character string that directs the format of the output
 * Return: the number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...)
{	va_list args;
	char *s;
	char *str;
	int i = 0, count = 0, num;

	str = malloc(20 * sizeof(char));
	if (str == NULL)
		return (-1);
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{	case 'c':
					count += _putchar(va_arg(args, int));
					i += 2;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					count += _puts(s);
					i += 2;
					break;
				case 'i':
				case 'd':
					num = va_arg(args, int);
					_sprintf(str, "%d", num);
					count += _puts(str);
					i += 2;
					break;
				case '\0':
					return (-1);
				case '%':
					count += _putchar('%');
					i += 2;
					break;
				default:
					count += _putchar(format[i]);
					i++;
					break;
			} continue;
		}
		count += _putchar(format[i]);
		i++;
	}
	free(str);
	va_end(args);
	return (count);
}