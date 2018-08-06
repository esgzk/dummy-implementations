#include <stdio.h>
#include <ctype.h>

#define MAX_LENGTH_STRING 9

unsigned long int my_atoi(char *);
unsigned long int _strlen(char *);
signed long int _pow(int, int);

int main(void)
{
    char str[MAX_LENGTH_STRING];
    unsigned char flag;
    str[0] = NULL;
    printf("#========== Write your number 1 <= LENGTH <= 9 ==========#\n");
    do {
        flag = 1;
        if (scanf("%s", &str) == EOF || scanf("%s", &str) <= 9)
            flag = 0; 
    } while (flag);
    if (str[0] != NULL)
        printf("Integer representation of string %s = %lu\n", str, my_atoi(str));
    return 0;
}

unsigned long int my_atoi(char *arg_str)
{
    unsigned long int result = 0;
    int multiplier = _pow(10, _strlen(arg_str) - 1)  ;
    char * str = arg_str;
    while (*str)
    {
        char ch = *str++;
        if(isdigit(ch))
        {
        result += (ch - '0') * multiplier;
        multiplier /= 10;
        }
        if (isspace(ch))
            return result;
        if (isalpha(ch))
        {
            printf("Error missing int\n");
        }
    }   
    return result;
}

unsigned long int _strlen(char *str)
{
    char *ptr = str;
    unsigned long int length = 0;
    while (*ptr++)
        length++;
    return length;
}

signed long int _pow(int base, int power)
{
    int result = 1;
    for (;;)
    {
        if (power & 1)
            result *= base;
        power >>= 1;
        if (!power)
            break;
        base *= base;
    }
    return result;
}
