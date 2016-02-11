/*
 * In The Name Of God
 * ========================================
 * [] File Name : dfa.c
 *
 * [] Creation Date : 11-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdlib.h>

#include "dfa.h"

struct dfa *dfa_new(void *init_data)
{
	struct dfa *new = malloc(sizeof(struct dfa));
	
	new->c = dfa_init(new, init_data);

	return new;
}

void dfa_process(struct dfa *d)
{
	while (!d->c->is_final)
		d->c = dfa_transition(d);
}

void dfa_delete(const struct dfa *d)
{
	state_delete(d->c);
	free((void *)d);
}
