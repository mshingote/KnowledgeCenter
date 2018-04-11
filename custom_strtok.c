#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#pragma region Standard strtok

void standard_strtok(char *string, const char *separators)
{
	char *token = strtok(string, separators);
	while (token)
	{
		printf("%s\n", token);
		token = strtok(NULL, separators);
	}
}

#pragma endregion

#pragma region Custom strtok

char *global_pointer;
char* my_strtok(char *string, const char *separators)
{
	static int index = 0;
	int string_at = 0;
	int separators_at = 0;
	int string_length = 0;
	int token_length = 0;

	if (!string && index)
	{
		string = &global_pointer[index];
	}
	else
	{
		global_pointer = string;
	}
	if (!string || !separators)
	{
		return NULL;
	}

	string_length = strlen(&string[index]);
	token_length = strlen(separators);
	for (string_at = 0; string_at < string_length; ++string_at)
	{
		for (separators_at = 0; separators_at < token_length; ++separators_at)
		{
			if (string[string_at] == separators[separators_at])
			{
				string[string_at] = NULL;
				index += string_at + 1;
				return string;
			}
		}
	}
	index = 0;
	return string;
}

void custom_strtok(char string[], const char *separators)
{
	char *token = my_strtok(string, separators);
	while (token)
	{
		printf("%s\n", token);
		token = my_strtok(NULL, separators);
	}
}

#pragma endregion

int main()
{
	char for_standard_strtok[] = "I#am,a*programmer";
	char for_custom_strtok[] = "I#am,a*programmer";
	const char *separators = "#,*";

	standard_strtok(for_standard_strtok, separators);
	custom_strtok(for_custom_strtok, separators);

	getchar();
	return 0;
}
