/*
 * mystring.c
 *
 *  Created on: Mar 8, 2016
 *      Author: bingoc
 */

#include "mystring.h"
#include <stddef.h>
#include <stdlib.h>

#define DEFAULT_CAPICITY 16
#define MAX_INT 2147483647

void ensureCapacity(struct string *str, int miniCapacity){
	if(str->capacity == 0)
		str->capacity = DEFAULT_CAPICITY;

	if(miniCapacity - str->capacity >0)
		expandCapacity(str, miniCapacity);
}

void expandCapacity(struct string *str, int miniCapacity){
	int newCapacity = str->capacity*2 +2;

	if(newCapacity - miniCapacity <0)
		newCapacity = miniCapacity;

	if(newCapacity <0)
	{
		if(miniCapacity <0)
		{
			printf("out of memory!");
			return;
		}
		newCapacity = MAX_INT;
	}
	str->string = realloc(str->string, newCapacity);
	str->capacity = newCapacity;
}


struct string* string_new(const char *init){

	struct string* newStr=(struct string *)malloc(sizeof(struct string));
	newStr->string = (char* )malloc(sizeof(char *));
	char* newChar = newStr->string;

	while((*newStr->string++ = *init++ )!= '\0');

	newStr->string = newChar;

	return newStr;
}

struct string* string_new_len(const char* init, size_t len){

	struct string* newStr = (struct string *)malloc(sizeof(struct string));

	newStr->string = (char *)malloc(sizeof(char *));
	newStr->length = 0;
	newStr->capacity = 0;

	//ensureCapacity(newStr, len);

	char *dest = newStr->string;

	for(int i =0;i<len;i++)
	{
		*newStr->string++ = *init++;
	}

	*newStr->string++='\0';

	newStr->string = dest;

	return newStr;
}

void string_free(struct string *s){
	free(s->string);
	free(s);
}

unsigned int string_length(struct string *s){

	unsigned int len=0;

	while(*s->string++!='\0')
	{
		len++;
	}
	return len;
}

const char *string_cstr(struct string *s){
	return s->string;
}

struct string* string_append(struct string *s, const char *val){

	char *new = s->string;

	while(*s->string!='\0')
	{
		*s->string++;
	}

	while((*s->string++ = *val++ ) != '\0');

	*s->string='\0';
	s->string=new;

	return s;
}

struct string* string_append_len(struct string *s, const char *val, unsigned int len){

	char* tmp = s->string;

	while(*s->string != '\0')
	{
		*s->string++;
	}

	while(len--)
	{
		if((*(s->string)++ = *val++) != '\0');
	}

	*s->string='\0';
	s->string= tmp;

	return s;
}
