#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

#pragma region Standard strtok

void standard_strtok(char *s, const char *sep)
{
	char *tok = strtok(s, sep);
	while (tok)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, sep);
	}
}

#pragma endregion

#pragma region Custom strtok

char *global_pointer;
char* my_strtok(char *string, const char *separators)
{
	static int index = 0;

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
	int string_length = strlen(&string[index]);
	int token_length = strlen(separators);
	int string_at = 0;
	int separators_at = 0;
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

void custom_strtok(char s[], const char *sep)
{
	char *tok = my_strtok(s, sep);
	while (tok)
	{
		printf("%s\n", tok);
		tok = my_strtok(NULL, sep);
	}
}

#pragma endregion

int main()
{
	char s1[] = "I#am,a*programmer";
	char s2[] = "I#am,a*programmer";
	const char *separators = "#,*";

	standard_strtok(s1, separators);
	custom_strtok(s2, separators);

	getchar();
	return 0;
}