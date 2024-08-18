#include <stdio.h>
#include <string.h>
void pdcheck(char string[])
{
	int len = strlen(string);
	int i;
	for (i = 0; i < (len / 2); i++)
	{
		if (string[i] != string[len - 1 - i])
		{
			break;
		}
	}
	if (i == (len/2))
	{
		printf("The string is a palindrome");
	}
	else
	{
		printf("The string is not a palindrome");
	}
}
int main()
{
	char str[100];
	printf("Enter the string : \n");
	gets(str);
	pdcheck(str);
}
