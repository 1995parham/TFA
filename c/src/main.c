/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 03-05-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#include <stdio.h>

#include "string_file_dfa.h"

int main(int argc, char *argv[])
{
	struct sf_dfa *f = string_file_dfa_new(stdin, "aaaaba");
	string_file_dfa_process(f);
}
