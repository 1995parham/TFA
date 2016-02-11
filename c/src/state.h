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
	void *data;
	int is_final;
};

struct state *state_new(void *data);

void state_delete(const struct state *s);

#endif
