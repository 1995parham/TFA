/*
 * In The Name Of God
 * ========================================
 * [] File Name : fa.h
 *
 * [] Creation Date : 03-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#ifndef FA_H
#define FA_H

struct fa {
	int sigma;
	int delta;
	int **ttable;
	int *is_final;
};

struct fa *fa_new(FILE *input_file);

int fa_validate(struct fa *f, const char *string);

void fa_write(struct fa *f, FILE *output_file);

void fa_delete(struct fa *f);

#endif
