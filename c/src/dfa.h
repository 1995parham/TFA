/*
 * In The Name Of God
 * ========================================
 * [] File Name : dfa.h
 *
 * [] Creation Date : 11-02-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#ifndef DFA_H
#define DFA_H

#include "state.h"

struct dfa {
	const struct state *c;
};

/*
 * DFA implemented function
 * create DFA just for YOU :)
*/
struct dfa *dfa_new(void *init_data);

/*
 * DFA to be implemented function
 * call in dfa_new for get initial state
 * you can use init_data in order to give it
 * needed information
*/
const struct state *dfa_init(const struct dfa *d, void *init_data);

/*
 * DFA implemented funtion
 * block until DFA process completely to final state
*/
void dfa_process(struct dfa *d);

/*
 * DFA to be implemented function
 * call in dfa_process for state transition
*/
const struct state *dfa_transition(const struct dfa *d);

#endif
