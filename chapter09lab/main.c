#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int test_strcpy();
int test_strlen();
int str_swap(char* str1, char* str2, int size);
int test_string();

int main()
{
	// printf("Hello World!\n");

	// test_strlen();
	// test_strcpy();
	test_string();

	return 0;
}

#define SIZE 128
int test_string()
{
	char in_str[SIZE] = "";
	char out_str[SIZE] = "";
	char* pContext = NULL;

	printf("Enter a string: ");
	// gets_s(in_str, sizeof(in_str));
	// fgets(in_str, sizeof(in_str), stdin); // stdin -- Keyboard file
	//파일에서 읽기:

	FILE* mycontact = fopen("C:/Users/user/Downloads/mycontact.txt", "r");
	if (mycontact == NULL)
	{
		printf("Fail to open file\n");
		return -1;
	}

	while (fgets(in_str, sizeof(in_str), mycontact) != NULL)
	{
		// (in_str, sizeof(in_str), stdin); // stdin -- keyboard file
		puts(in_str);

		char* pToken = strtok_s(in_str, "|,", &pContext);
		if (pToken != NULL) puts(pToken);

		pToken = strtok_s(NULL, "|,", &pContext);
		if (pToken != NULL) puts(pToken);

		pToken = strtok_s(NULL, "|,", &pContext);
		if (pToken != NULL) puts(pToken);
	}
	
	fclose(mycontact);

	return 0;
}

#define STR_SIZE 128
int test_strcpy()
{
	char str1[STR_SIZE] = "";
	char str2[STR_SIZE] = "";

	printf("두 문자열 입력: ");
	scanf_s("%s %s", str1, STR_SIZE, str2, STR_SIZE);
	// printf("%s %s 가 입력되었습니다.", str1, str2);

	str_swap(str1, str2, STR_SIZE);
	printf("%s %s 가 교환되었나요?", str1, str2);

	return 0;
}
// 교환된 두 문자열 길이의 합 반환
int str_swap(char *str1, char *str2, int size)
{
	int result = 0;
	if (size <= 0 || str1 == NULL || str2 == NULL)
	{
		return 0;
	}

	char* temp = NULL;
	// void * malloc(int size);
	temp = (char*)malloc(sizeof(char) * size);
	// temp[0] = 'A';
	// char temp[size];

	if (temp == NULL)
	{
		return 0;
	}

	/*
	strncpy(temp, str1, size);
	strncpy(str1, str2, size);
	strncpy(str2, temp, size);
	*/

	strcpy_s(temp, size, str1);
	strcpy_s(str1, size, str2);
	strcpy_s(str2, size, temp);

	result = strlen(str1) + strlen(str2);

	free(temp);

	return result;
}

int test_strlen()
{
	char str1[] = "hello";
	char name[] = "김길동";

	size_t len = strlen(str1);

	//printf("%s 의 길이: %d\n", str1, strlen(str1));
	printf("%s 의 길이: %d\n", str1, len);

	len = strlen("안녕하세요");

	//printf("%s 의 길이: %d\n", name, strlen(name));
	printf("%s 의 길이: %d\n", "안녕하세요", len);

	len = strlen("");

	printf("%s 의 길이: %d\n", "", len);

	return 0;
}