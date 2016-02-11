/*
 * In The Name Of God
 * ========================================
 * [] File Name : state.h
 *
 * [] Creation Date : 11-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#ifndef STATE_H
#define STATE_H

struct state {
	const void *data;
	int is_final;
};

struct state *state_new(const void *data);

void state_delete(struct state *s);

#endif
