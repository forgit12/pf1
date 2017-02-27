/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 18:32:06 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/25 16:38:50 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int a = 6823534;
	int b = -2147483648;
	size_t c = 98;
	char s[] = "mystr ---- юхху";
	char s1[] = "1234567";
	int d = -214748364;
	int t = 6087416;

//	ft_putstr("OOP\n");
//	printf("%030x\n", a);
//	ft_printf("%030x", a);

//	printf("%#15.20X\n", a);
//	ft_printf("%#15.20X", a);

//	printf("%#15o\n", a);
//	ft_printf("%#15o", a);

//	printf("%#030.x\n", a);
//	ft_printf("%#030.x", a);

//	printf("%#030.o\n", a);
//	ft_printf("%#030.o", a);
//	int cv = 42457835673;

//	printf("%u\n", cv);
//	ft_printf("%u", cv);

	char ch = 'M';

	int ko = 23847;
//	printf("%-030.20d\n", ko);
//	ft_printf("%-030.20d\n", ko);

//	printf("%-05%\n");
//	printf("%-05%\n");
//	ft_printf("%-030.20d\n");

//	printf("%-12c\n", ch);
//	ft_printf("%-12c\n", ch);

//	printf("%#50.25x\n", a);
//	ft_printf("%#50.25x", a);
	int re = -42;

//	printf("%0+5i\n", re);
//	ft_printf("%0+5i", re);

	int rn = 5456;
//	printf("%020h+i\n", rn);
//	ft_printf("%020h+i", rn);

	printf("P%22. 15-i\n", rn);
	ft_printf("F%22. 15-i\n", rn);

//	printf("%30- .20i\n", rn);
//	ft_printf("%30- .20i\n", rn);

//	printf("%00d\n", re);
//	ft_printf("%ll0lll.5 d", re);

//	printf("%X\n", -42);
//	ft_printf("%X", -42);

//	printf("\n%u", 500);	

//	printf("%-9.4s\n", s1);
//	ft_printf("%-9.4s", s1);
//	ft_printf("123456789", "ret1", "ret2", "ret3");
//	ft_printf("123456789", a*a, b, c);
// test testcase	ft_printf("123456789%#123.0000123456hh.34.56.000hhh234i", d);
//	ft_printf("123456789%#123.0000123456.34.56z234i", d);
/*	ft_printf("%i\n", d);
	ft_printf("%i\n", d);*/
//	ft_printf("%#x\n", t);
//	ft_printf("1%% %%23     %%     \n");
	intmax_t f = 2345;
	int tp = -129;
	int tp1 = 198;
//	ft_printf("%10.5i", (long)t);
//	ft_printf("%- 10 .5i", (long)tp);
//	printf("\n% .5i", tp);
//	printf("\n%+ .5i", tp);
//	printf("\n%- 10.5i", tp);
//	ft_printf("%#5.6o", tp);
//	printf("\n%#5.6o", tp);
//	printf("0123%20.6.8.0.i\n", tp1);
//	ft_printf("0123%20.6.8.0.i", tp1);

//	ft_printf("%-10.06o", tp);
//	printf("\n%-10.06o", tp);

//	ft_printf("%-40.20U", tp);
//	printf("\n%.1U", tp);



//	printf("\n%llll.5d", tp);
//	printf("\n%#010X", tp);

//	ft_printf("%012i", f);
//	printf("\n%012i", f);

// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
// 1 2 3 4 5 6 7 8 9 % #  .  1  2  3  4  5  6  i  \0
}
