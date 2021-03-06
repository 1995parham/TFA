/*
 * In The Name Of God
 * ========================================
 * [] File Name : state.c
 *
 * [] Creation Date : 11-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include "state.h"

#include <stdlib.h>

struct state *state_new(void *data)
{
	struct state *new = malloc(sizeof(struct state));

	new->data = data;
	new->is_final = 0;

	return new;
}

void state_delete(const struct state *s)
{
	free((void *)s);
}
