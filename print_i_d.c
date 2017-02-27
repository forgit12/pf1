/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 23:02:47 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/27 23:28:43 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printprecision(t_list *lst, uintmax_t i)
{
	int	r;
	int	t;

//	printf("lst->nsymb %d\n", lst->nsymb);
//	printf("lst->p_n %d\n", lst->p_n);
//	printf("lst->minus %d\n", lst->minus);
//	printf("lst->plus %d\n", lst->plus);
//	printf("lst->width %d\n", lst->width);
	r = (!lst->minus && !lst->plus) ? (lst->p_n - lst->nsymb) : (lst->p_n - lst->nsymb + 1);
//	printf("r %i\n", r);
	t = lst->nsymb + r;
//	printf("t %i\n", t);
	if (lst->conv != 9 && lst->conv != 10 && lst->minus != 1 && lst->plus != 1 && lst->space == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	while (lst->width > t && lst->min == 0)
	{
		ft_putchar(' ');
		lst->width--;
	}
	if (lst->minus)
		ft_putchar('-');
	if (lst->plus && lst->minus != 1)
		ft_putchar('+');
	while (r--)
		ft_putchar('0');
	ft_putnbr(i);
	while (lst->min && lst->width > t)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void	printi(t_list *lst, void *nt)
{
	long	i;

	i = 0;

/*	if ((int)nt < 0)
	{
		lst->minus++;
		lst->nsymb++;
	}
*/
	conv_sm(lst, &i, nt);
//	(lst->minus == 1) ?	(i = i * -1) : (i = i + 0);
//	printf("P2 %ld\n", i);
//	printf("lm %d\n", lst->minus);
//	printf("lst->nsymb %d\n", lst->nsymb);
//	printf("P1 %d\n", (int)nt);
	if (i == 0 && lst->p_n == 0)
	{
		print_d_i_null_p_n(lst);
		return ;
	}
	countnumsymb(lst, i);
//	printf("lst->nsymb %d\n", lst->nsymb);
//	printf("lst->width %d\n", lst->width);
//	printf("lst->min %d\n", lst->min);
//	printf("lst->nul %d\n", lst->nul);
	if (lst->p_n && (lst->p_n - lst->nsymb > 0))
	{
		printprecision(lst, i);
		return ;
	}
	if (lst->plus == 1 && lst->min == 1 && lst->p_n >= lst->nsymb)
	{
		print_p_m_symb(lst, i);
		return ;
	}
	if (lst->conv != 9 && lst->conv != 10 && lst->minus != 1 && lst->plus != 1 && lst->space == 1 && (lst->width == 0 || (lst->width > 0 && lst->min == 1)))
	{
		ft_putchar(' ');
		lst->width--;
	}

	while ((lst->width - lst->plus > lst->nsymb) && (lst->nul == 0 || (lst->p_n <= lst->nsymb)) && lst->min != 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
	if (lst->minus == 1 && ((lst->width > lst->nsymb) || lst->width == 0))
	{
		ft_putchar('-');
		lst->minus = 0;
		lst->plus = 0;
	}
	if (lst->plus == 1 && lst->nul == 1 && lst->minus != 1)
		ft_putchar('+');
//	printf("lw %d\n", lst->width);
//	printf("ln %d\n", lst->nsymb);
	if (lst->plus == 1 && lst->nul != 1 && lst->minus != 1)
		ft_putchar('+');
	while ((lst->width > lst->nsymb) && (lst->nul == 1 || lst->plus == 1) && lst->min != 1)
	{
		ft_putchar('0');
		lst->width--;
	}
	if (lst->minus == 1 && lst->nul != 1)
		ft_putchar('-');
//	printf("lst->plus %d\n", lst->plus);
//	printf("lst->nul %d\n", lst->nul);
//	printf("lst->minus %d\n", lst->minus);

	ft_putnbr(i);
	while (lst->width > lst->nsymb && lst->min == 1)
	{
		ft_putchar(' ');
		lst->width--;
	}
}

void f(unsigned long value, int base1, char *str, int *i, t_list *lst)
{
	char			*tmp;
	char			*tmpl;
	unsigned long	base;
	
	base = (unsigned long)base1;
	tmp = (char*)malloc(17);
	tmpl = (char*)malloc(17);
	tmp = "0123456789ABCDEF";
	tmpl = "0123456789abcdef";
	if (value >= base)
		f(value / base, base, str, i, lst);
	if (lst->conv == 12 || lst->conv == 7 || lst->conv == 8)
		str[(*i)++] = tmp[(value % base)];
	if (lst->conv == 11)
		str[(*i)++] = tmpl[(value % base)];
}


void	print_x(t_list *lst, void *nt, unsigned long base, int i)
{
	char	*str;
	unsigned long value;
    
	value = 0;
	conv_sm_x_o(lst, &value, nt);
	str = (char*)malloc(32);
/*	if (lst->hash == 1 && lst->conv == 11 && lst->p_n != 0  && lst->nul == 0)
	{
		str[i++] = '0';
		str[i++] = 'x';
	}
	if (lst->hash == 1 && lst->conv == 12 && lst->p_n > 0 && lst->nul == 0)
	{
		str[i++] = '0';
		str[i++] = 'X';
	}*/
//	printf("U [%lu]", value);
	if (lst->hash == 1 && (lst->conv == 7 || lst->conv == 8) && value != 0)
		str[i++] = '0';
	f(value, base, str, &i, lst);
	str[i] = '\0';
//	printf("s [%s]", str);
	nul_x(str, lst);
}
