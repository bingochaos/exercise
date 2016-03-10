/*
 * mystring.h
 *
 *  Created on: Mar 8, 2016
 *      Author: bingoc
 */

#ifndef MYSTRING_H_
#define MYSTRING_H_
#include <stddef.h>
struct string;

struct string* string_new(const char *init);
struct string* string_new_len(const char* init, size_t len);
void string_free(struct string *s);

unsigned int string_length(struct string *s);
const char *string_cstr(struct string *s);

struct string* string_append(struct string *s, const char *val);
struct string* string_append_len(struct string *s, const char *val, unsigned int len);

#endif /* MYSTRING_H_ */
