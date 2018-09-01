#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include "converterlib.h"

#define BINARY_SUPPORT
/* ON-OFF BINARY CONVERTER */
#define OCTAL_SUPPORT
/* ON-OFF OCTAL CONVERTER */
#define HEX_SUPPORT
/* ON-OFF HEX CONVERTER */
#define sizeofarray(x) ( sizeof(x) / sizeof(*(x)))
/* COUNT SIZE OF ARRAY */


//#undef BINARY_SUPPORT
//#undef OCTAL_SUPPORT
//#undef HEX_SUPPORT



int main()
{
    time_t start = time(0);
	uint16_t base = 0;
	uint16_t mode = 0;
	system("cls");// CMD CLS
	printf("\t\t<#####CONVERTER DECIMAL TO BINARY, OCTAL, HEX NOTATIONS AND VICE VERSA#####>\t\t\n");
	do {
		printf("Write base of notation: ");
		scanf("%hu", &base);
	} while (1 >= base && 16 < base );
    do {
        printf("Write mode of program (0 - DEC to N notation; 1 - N notation to DEC): ");
        scanf("%hu", &mode);
    } while (mode < 0);

#ifdef BINARY_SUPPORT
	if (base == 2)
	{
		binary_convert(mode);// in func implemented print
        time_t finish = time(0);
        printf("\nTime of program = %ld\n", finish - start);
		system("pause");
		return 0;//maybe runtime program or no...
	}
#endif

#ifdef OCTAL_SUPPORT
	if (base == 8)
	{
		octal_convert(mode);// in func implemented print
        time_t finish = time(0);
        printf("\nTime of program = %ld\n", finish - start);
		system("pause");
		return 0;//maybe runtime program or no...
	}
#endif

#ifdef HEX_SUPPORT
	if (base == 16)
	{
		hex_convert(mode);// in func implemented print
        time_t finish = time(0);
        printf("\nTime of program = %ld\n", finish - start);
		system("pause");
		return 0;//maybe runtime program or no...
	}
#endif
	printf("No support %u notation now\n", base);
	system("pause");
	return 0;
}

/* <-------PRINT NEED TO BE IMPLEMENTED IN CONVERTERS, MAYBE SCAN TOO :) -------> */
void binary_convert(uint16_t mode)//long long int format specifier = %lli
{
	signed int binary_digit[64] = {0};//qword = length 0-64 = 64
	signed int digit;
	int32_t i = 0;
	printf("MAX SUPPORTED DIGIT :( %d\n", INT_MAX);
	if (!mode)
	{
		do {
			printf("Write decimal digit: ");
			scanf("%d", &digit);
		} while (checker(&digit));//checker of int;
		while (digit > 0)
		{
			binary_digit[i++] = digit % 2;
			digit >>= 1; // equal digit /=2
		}
		i = sizeofarray(binary_digit) - 1;
		while (i >= 0)
		{
			printf("%d", binary_digit[i]);
			if (i % 4 == 0)
			{
				printf(" ");
			}
			i--;
		}
	}
	else
	{
		do {
			printf("Write binary digit: ");
			scanf("%d", &digit);
		} while (checker(&digit));//checker of int
		uint32_t temp = mystrlen(myitoa(digit, 10) );
		while (i  < temp)
		{
			binary_digit[0] += digit % 10 * (pow( (double)2, (double)i ));
			digit /= 10;
			i++;
		}
		printf("RESULT = %d\n", binary_digit[0]);
	}
}
void octal_convert(uint16_t mode)
{
	signed int octal_digit[64] = {0};//qword = length 0-64 = 64
	signed int digit;
	int32_t i = 0;
	printf("MAX SUPPORTED DIGIT :( %d\n", INT_MAX);
	if (!mode)
	{
		do {
			printf("Write decimal digit: ");
			scanf("%d", &digit);
		} while (checker(&digit));//checker of int;
		while (digit > 0)
		{
			octal_digit[i++] = digit % 8;
			digit >>= 3; // equal digit /= 8
		}
		i = sizeofarray(octal_digit) - 1;
		while (i >= 0)
		{
			printf("%d", octal_digit[i--]);
		}
	}
	else
	{
		do {
			printf("Write octal digit: ");
			scanf("%d", &digit);
		} while (checker(&digit));//checker of int
		uint32_t temp = mystrlen(myitoa(digit, 10) );
		while (i  < temp)
		{
			octal_digit[0] += digit % 10 * (pow( (double)8, (double)i ));
			digit /= 10;
			i++;
		}
		printf("RESULT = %d\n", octal_digit[0]);
	}
}
void hex_convert(uint16_t mode)
{
	signed int hex_bits[64] = {0};//qword = length 0-64 = 64
	signed int digit;
	int32_t i = 0;
	struct hexadecimal_digit
	{
		uint8_t num;
		char ch;
	} hexadecimal_digits[] =
	{
		{0, '0'},
		{1, '1'},
		{2, '2'},
		{3, '3'},
		{4, '4'},
		{5, '5'},
		{6, '6'},
		{7, '7'},
		{8, '8'},
		{9, '9'},
		{10, 'A'},
		{11, 'B'},
		{12, 'C'},
		{13, 'D'},
		{14, 'E'},
		{15, 'F'}
	};
	printf("MAX SUPPORTED DIGIT :( %d\n", INT_MAX);
	if (!mode)// if mode == 0
	{
		do {
			printf("Write decimal digit: ");
			scanf("%d", &digit);
		} while (checker(&digit));//checker of int;
		while (digit > 0)
		{
			hex_bits[i++] = digit % 16;
			digit >>= 4;// equal digit /= 16
		}
		i = sizeofarray(hex_bits) - 1;
		while (i >= 0)
		{
			printf("%c", (hexadecimal_digits[hex_bits[i]].num == hex_bits[i]) ? hexadecimal_digits[hex_bits[i]].ch : '0');
			i--;
		}
	}
	else
	{
		do {
			printf("Write hexadecimal digit: ");
		} while (!scanf("%x", &digit));//checker of int
		char * hex_string = "";
		uint32_t temp = mystrlen(myitoa(digit, 10) ) - 1; // -1 due to NULL_STRING in mystrlen mb :)
		mystrcpy(myitoa(digit, 10), hex_string);
		while (i  < temp)
		{
			printf("hex_string[%d] - 55 = %d\n", i, hex_string[i] - 55);
			printf("hex_string[%d] = %c\n", i, hex_string[i]);
			printf("RES = %d\n", hex_bits[0]);
            (hexadecimal_digits[(hex_string[i]) - 55].ch == hex_string[i]) ? hex_bits[0] += hexadecimal_digits[hex_string[i] - 55].num * (pow( (double)16, (double)i )) : printf("Not appropriate symbol"); // 'A' - 55 = 10 10== 'A' in hex
            i++;
		}
		printf("RESULT = %d\n", hex_bits[0]);
	}
}

void mystrcpy(char * src, char * destination)
{
    for (; (*destination++ = *src++);)
        ;
}

int checker(int *ptr)// 1 if not digit, 0 if digit
{
	return (itoa_checker(*ptr, 10) == 0) ? 1 : 0;
}
//length of string
unsigned int mystrlen(char *string_pointer)
{
	unsigned int length = 0;
	while (*string_pointer++)
		length++;
	return length;
}
// Convert integer to alpha and check like isdigit()
int itoa_checker(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;
	for(; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return (buf[i+1] >= '0' && buf[i+1] <= '9' ) ? 1 : 0;	
}
/* Convert integer to string*/
char * myitoa(int val, int base)
{
	
	
	static char buf[32] = {0};
	
	int i = 30;
	
	for(; val && i ; --i, val /= base)
	
		buf[i] = "0123456789abcdef"[val % base];
	
	return &buf[i+1];
}
