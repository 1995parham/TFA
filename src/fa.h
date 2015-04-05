/*
 * In The Name Of God
 * ========================================
 * [] File Name : fa.h
 *
 * [] Creation Date : 05-04-2015
 *
 * [] Last Modified : Sun 05 Apr 2015 08:27:43 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
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
