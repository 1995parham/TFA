/*
 * In The Name Of God
 * ========================================
 * [] File Name : fa.c
 *
 * [] Creation Date : 03-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fa.h"

struct fa *fa_new(FILE *input_file)
{
	struct fa *new;
	int i, j;
	int state;

	new = malloc(sizeof(struct fa));

	fscanf(input_file, "%d", &(new->sigma));
	fscanf(input_file, "%d", &(new->delta));

	new->ttable = malloc(new->delta * sizeof(int *));
	for (i = 0; i < new->delta; i++)
		new->ttable[i] = malloc(new->sigma * sizeof(int));
	for (i = 0; i < new->delta; i++)
		for (j = 0; j < new->sigma; j++)
			fscanf(input_file, "%d", &(new->ttable[i][j]));

	new->is_final = calloc(new->delta, sizeof(int));
	do {
		fscanf(input_file, "%d", &state);
		if (state)
			new->is_final[state - 1] = 1;
	} while (state);

	return new;
}

int fa_validate(struct fa *f, const char *string)
{
	int i = 0;
	int current = 1;

	while (i < strlen(string)) {
		current = f->ttable[current - 1][string[i] - 'a'];
		i++;
		if (!current)
			return 0;
	}
	if (f->is_final[current - 1])
		return 1;
	return 0;
}

void fa_delete(struct fa *f)
{
	int i;

	for (i = 0; i < f->delta; i++)
		free(f->ttable[i]);
	free(f->ttable);
	free(f->is_final);
	free(f);
}

struct fa *fa_new_intersection(const struct fa *f1, const struct fa *f2)
{
	if (f1->sigma == f2->sigma)
		return NULL;

	struct fa *new;
	int i, j, k;

	new = malloc(sizeof(struct fa));
	new->sigma = f1->sigma;
	new->delta = f1->delta * f2->delta;
	new->ttable = malloc(new->delta * sizeof(int));
	for (i = 0; i < new->delta; i++)
		new->ttable[i] = malloc(new->sigma * sizeof(int));
	for (i = 0; i < f1->delta; i++)
		for (j = 0; j < f2->delta; j++)
			for (k = 0; k < new->sigma; k++)
				new->ttable[(i + 1) * (j + 1) - 1][k] =
					f1->ttable[i][k] * f2->ttable[j][k];
	new->is_final = calloc(new->delta, sizeof(int));
	for (i = 0; i < f1->delta; i++)
		for (j = 0; j < f2->delta; j++)
			new->is_final[(i + 1) * (j + 1) - 1] = f1->is_final[i] && f1->is_final[j];
	return new;
}
