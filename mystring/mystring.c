/*
 * mystring.c
 *
 *  Created on: Mar 8, 2016
 *      Author: bingoc
 */

#include "mystring.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#define DEFAULT_CAPICITY 16
#define MAX_INT 2147483647

struct string{
	char *string;
	size_t length;
	size_t capacity;
};

static void expandCapacity(struct string *str, size_t miniCapacity){

	size_t newCapacity = str->capacity <<1;

				if(newCapacity < miniCapacity )
					newCapacity = miniCapacity;

				if(newCapacity < 0)
				{
					if(miniCapacity < 0)
					{
						printf("out of memory!");
						return;
					}
					newCapacity = MAX_INT;
				}
				str->string = realloc(str->string, newCapacity);
				str->capacity = newCapacity;
}
static void ensureCapacity(struct string *str, size_t miniCapacity){
	if(str->capacity == 0)
	{
		str->capacity = DEFAULT_CAPICITY;
		str->string = realloc(str->string, DEFAULT_CAPICITY);
	}


	if(miniCapacity > str->capacity)//;
	{
		expandCapacity(str, miniCapacity);
	}

}


struct string* string_new(const char *init){

	if(init == NULL)
		init = "";
	return string_new_len(init,strlen(init));
}

struct string* string_new_len(const char* init, size_t len){

	struct string* newStr = (struct string *)malloc(sizeof(struct string));

	newStr->string = NULL;
	newStr->length = 0;
	newStr->capacity = 0;

	ensureCapacity(newStr, len);

	memcpy(newStr->string, init, len);
	newStr->string[len] = '\0';
	newStr->length = len;

	return newStr;
}

void string_free(struct string *s){
	free(s->string);
	free(s);
}

unsigned int string_length(struct string *s){
	return s->length;
}

const char *string_cstr(struct string *s){
	return s->string;
}

struct string* string_append(struct string *s, const char *val){
	return string_append_len(s, val, strlen(val));
}

struct string* string_append_len(struct string *s, const char *val, unsigned int len){

	unsigned int miniCapacity = s->length + len;
	ensureCapacity(s, miniCapacity);
	memcpy(s->string + s->length, val , len);//利用char*的偏移
	s->string[miniCapacity] = '\0';
	s->length = miniCapacity;
	return s;
	return s;
}
