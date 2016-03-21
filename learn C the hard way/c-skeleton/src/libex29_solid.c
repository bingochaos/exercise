#include <stdio.h>
#include <ctype.h>
#include "dbg.h"
#include <assert.h>

int print_a_message_s(const char *msg)
{
	assert(msg != NULL);
	
	printf("A STRING: %s\n", msg);

	return 0;
}

int uppercase_s(const char *msg, const int len)
{
	assert(msg != NULL);

	int i = 0;

	for(i = 0; i < len; i++)
	{
		printf("%c", toupper(msg[i]));
	}

	printf("\n");

	return 0;
}

int lowercase_s(const char *msg, const int len)
{
	assert(msg != NULL);

	int i = 0;

	for(i = 0; i < len; i++)
	{
		printf("%c", tolower(msg[i]));
	}

	printf("\n");

	return 0;
}

int fail_on_purpose_s(const char *msg)
{
	return 1;
}