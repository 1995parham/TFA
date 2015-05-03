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

#include "fa.h"

int main(int argc, char *argv[])
{
	struct fa *f = fa_new(stdin);
	printf("%d\n", fa_validate(f, "aaaaba"));
}
