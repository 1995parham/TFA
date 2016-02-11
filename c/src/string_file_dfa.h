/*
 * In The Name Of God
 * ========================================
 * [] File Name : string_file_dfa.h
 *
 * [] Creation Date : 03-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#ifndef STRING_FILE_DFA_H
#define STRING_FILE_DFA_H

struct sf_dfa {
	struct dfa *d;	
};


struct sf_dfa *string_file_dfa_new(FILE *input_file, const char *string);

void string_file_dfa_process(struct sf_dfa *f);

void string_file_dfa_delete(struct sf_dfa *f);

#endif
