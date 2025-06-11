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
	//���Ͽ��� �б�:

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

	printf("�� ���ڿ� �Է�: ");
	scanf_s("%s %s", str1, STR_SIZE, str2, STR_SIZE);
	// printf("%s %s �� �ԷµǾ����ϴ�.", str1, str2);

	str_swap(str1, str2, STR_SIZE);
	printf("%s %s �� ��ȯ�Ǿ�����?", str1, str2);

	return 0;
}
// ��ȯ�� �� ���ڿ� ������ �� ��ȯ
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
	char name[] = "��浿";

	size_t len = strlen(str1);

	//printf("%s �� ����: %d\n", str1, strlen(str1));
	printf("%s �� ����: %d\n", str1, len);

	len = strlen("�ȳ��ϼ���");

	//printf("%s �� ����: %d\n", name, strlen(name));
	printf("%s �� ����: %d\n", "�ȳ��ϼ���", len);

	len = strlen("");

	printf("%s �� ����: %d\n", "", len);

	return 0;
}