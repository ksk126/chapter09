#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str1[21];
	char str2[21];

	printf("ют╥б: ");
	scanf("%s %s", str1, str2);
	
	char temp[21];

	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	printf("%s %s", str1, str2);

	return 0;
}