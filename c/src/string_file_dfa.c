/*
 * In The Name Of God
 * ========================================
 * [] File Name : string_file_dfa.c
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

#include "dfa.h"
#include "string_file_dfa.h"

struct sf_dfa_data {
	/* General Data :) */
	int sigma;
	int delta;
	int **ttable;
	int *is_final;
	const char *string;

	/* State specific Data :) */
	int current;
	int index;
};

struct sf_dfa *string_file_dfa_new(FILE *input_file, const char *string)
{
	struct sf_dfa_data *v;
	int i, j;
	int state;

	v = malloc(sizeof(struct sf_dfa_data));

	fscanf(input_file, "%d", &(v->sigma));
	fscanf(input_file, "%d", &(v->delta));

	v->ttable = malloc(v->delta * sizeof(int *));
	for (i = 0; i < v->delta; i++)
		v->ttable[i] = malloc(v->sigma * sizeof(int));
	for (i = 0; i < v->delta; i++)
		for (j = 0; j < v->sigma; j++)
			fscanf(input_file, "%d", &(v->ttable[i][j]));

	v->is_final = calloc(v->delta, sizeof(int));
	do {
		fscanf(input_file, "%d", &state);
		if (state)
			v->is_final[state - 1] = 1;
	} while (state);
	v->string = string;

	v->current = 1;
	v->index = 0;

	struct sf_dfa *new;
	
	new = malloc(sizeof(struct sf_dfa));

	new->d = dfa_new(v);

	return new;
}

void string_file_dfa_process(struct sf_dfa *f)
{
	dfa_process(f->d);
}

void string_file_dfa_delete(struct sf_dfa *f)
{
	dfa_delete(f->d);
	free(f);
}

static void string_file_dfa_data_delete(struct sf_dfa_data *f)
{
	int i;

	for (i = 0; i < f->delta; i++)
		free(f->ttable[i]);
	free(f->ttable);
	free(f->is_final);
	free(f);
}

const struct state *dfa_init(const struct dfa *d, void *init_data)
{
	struct state *s = state_new(init_data);
	s->is_final = 0;
	return s;
}

const struct state *dfa_transition(const struct dfa *d)
{
	struct sf_dfa_data *v = d->c->data;
	struct state *s = state_new(v);
	state_delete(d->c);

	if (v->index < strlen(v->string)) {
		v->current = v->ttable[v->current - 1][v->string[v->index] - 'a'];
		v->index++;
		if (!v->current) {
			printf("Not Accepted\n");
			s->data = NULL;
			s->is_final = 1;
			string_file_dfa_data_delete(v);
			return s;
		}
		if (v->is_final[v->current - 1]) {
			printf("Accepted\n");
			s->data = NULL;
			s->is_final = 1;
			string_file_dfa_data_delete(v);
			return s;
		}
	} else {
		printf("Not Accepted\n");
		s->data = NULL;
		s->is_final = 1;
		string_file_dfa_data_delete(v);
		return s;

	}
	s->is_final = 0;
	return s;
}
