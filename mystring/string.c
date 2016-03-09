/*
 ============================================================================
 Name        : string.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "mystring.h"

int main(void) {
	struct string *s = string_new("hello");  // s = "hello";
	string_append(s, ", boy!");  // s = "hello, boy!";
	string_free(s);

	s = string_new_len("hellooooooooooooooooo2222222o", 23);  // s = "hel"
	string_append_len(s, "baby", 2); // s = "helba"
	string_free(s);
	return EXIT_SUCCESS;
}
