/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 22:07:04 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/27 22:12:52 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	nul_x(char *str, t_list *lst)
{
	int	n;

	n = 0;
	while (str[n])
        n++;
	if (str[n - 1] == '0' && str[n] == '\0' && n <= 3 && (lst->p_n != -1 || lst->hash == 1))
	{
//		write(1, "L", 1);
		if (lst->hash == 1 && lst->width != 0 && lst->p_n != -1)
		{
			ft_hash_p_n(lst);
			return ;
		}
		if (lst->width != 0 && lst->hash == 0)
			ft_nul_width(lst);
		if (lst->width != 0 && lst->hash == 1)
			ft_nul_min(str, lst);
		if (lst->hash == 1 && lst->p_n == 0)
		{
			str[n - 1] = '\0';
			while (lst->p_n-- > 0 && lst->conv != 7 && lst->conv != 8)
				ft_putchar('0');
		}
		if (lst->width == 0 && lst->hash == 1)
			ft_putchar('0');
	}
	else
	{
		if (lst->p_n >= 0)
			lst->nul = 0;
		print_xstr(str, lst);
	}
}

void	ft_hash_p_n(t_list *lst)
{
	while (lst->width > 0 && lst->p_n == 0 && lst->conv != 7 && lst->conv != 8)
	{
		ft_putchar(' ');
		lst->width--;
	}
//	printf("lw %d", lst->width);
//	printf("lp %d", lst->p_n);
//	printf("lc %d", lst->conv);
	if (lst->width > 0 && lst->p_n == 0 && (lst->conv == 7 || lst->conv == 8))
	{
		while (lst->width - 1 > 0)
		{
			ft_putchar(' ');
			lst->width--;
		}
		ft_putchar('0');
	}
	if (lst->width > 0 && lst->p_n > 0)
	{
		while (lst->width-- > lst->p_n)
			ft_putchar(' ');
		while (lst->p_n-- > 0)
			ft_putchar('0');
	}	
}

void	ft_nul_width(t_list *lst)
{
	//		write(1, "L", 1);
	while (lst->width-- > 0)
		ft_putchar(' ');
//	write(1, "L", 1);
//	ft_putchar(' ');
}

void	ft_nul_min(char *str, t_list *lst)
{
//	write(1, "L", 1);
	if (lst->width != 0 && lst->hash != 0 && lst->min == 0 && lst->p_n == -1)
	{
		while (--lst->width > 0)
			ft_putchar(' ');
		ft_putstr(str);
	}
	if (lst->width != 0 && lst->hash != 0 && lst->min == 1 && lst->p_n == -1)
	{
		ft_putstr(str);
		while (--lst->width > 0)
			ft_putchar(' ');
	}
	if (lst->width != 0 && lst->hash != 0 && lst->min == 1 && lst->p_n != -1)
	{
		while (lst->p_n-- > 0)
			ft_putchar('0');
		ft_putchar(' ');
	}
	if (lst->width != 0 && lst->hash != 0 && lst->min != 1 && lst->p_n != -1)
	{
		ft_putchar(' ');
		while (lst->p_n-- > 0)
			ft_putchar('0');
	}
}
