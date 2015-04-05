/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 05-04-2015
 *
 * [] Last Modified : Sun 05 Apr 2015 09:11:17 AM IRDT
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>

#include "fa.h"

int main(int argc, char *argv[])
{
	struct fa *f = fa_new(stdin);
	printf("%d\n", fa_validate(f, "aaaaba"));
}
