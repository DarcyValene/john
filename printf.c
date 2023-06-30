#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - Prints a single character
 * @ch: Character to print
 *
 * Return: Number of characters printed (always 1)
 */
int print_char(char ch)
{
	write(1, &ch, 1);
	return (1);
}

/**
 * print_string - Prints a string
 * @str: String to print
 *
 * Return: Number of characters printed
 */
int print_string(char *str)
{
	int printed_chars = 0;

	if (!str)
		str = "(null)";

	while (*str)
	{
		write(1, str, 1);
		str++;
		printed_chars++;
	}

	return (printed_chars);
}

/**
 * _printf - Prints output according to a format
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char *str;
	char ch;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					printed_chars += print_char(ch);
					break;
				case 's':
					str = va_arg(args, char *);
					printed_chars += print_string(str);
					break;
				case '%':
					printed_chars += print_char('%');
					break;
				default:
					printed_chars += print_char('%');
					printed_chars += print_char(*format);
					break;
			}
		}
		else
		{
			printed_chars += print_char(*format);
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}

