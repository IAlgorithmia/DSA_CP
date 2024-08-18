#include <stdio.h>
#include <string.h>
int main()
{
	printf("Enter the entire string : \n");
	char string[500];
	gets(string);
	printf("Enter the substring to search for : \n");
	char substring[100];
	gets(substring);
	int length = strlen(string);
	int sublength = strlen(substring);
	int start = 0, check = 0;
	int ahead, m;
	for (start = 0; (start + sublength - 1) < length; start++)
	{
		check = 0;
		for (ahead = 0; ahead < sublength; ahead++)
		{
			if (string[start + ahead] == substring[ahead])
			{
				check++;
			}
		}
		if (check == sublength)
	    {
		    printf("The substring is present in the given string.");
			printf("The starting index is : %d\n", start);
			m = check;
			break;
	    }
	}
	if (m != sublength)
	{
		printf("The substring is not present in the given string");
	}
}
