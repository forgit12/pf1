/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 22:13:28 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/28 22:43:06 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    print_fix_minus_d(t_list *lst, uintmax_t i)
{
//  printf("N%d", lst->nul);
//  printf(" L %lu", i);
    while (lst->width > lst->nsymb && lst->nul != 1)
    {
        ft_putchar(' ');
        lst->width--;
    }
    if (lst->minus == 1)
	ft_putchar('-');
    while (lst->width > lst->nsymb && lst->nul == 1)
    {
        ft_putchar('0');
        lst->width--;
    }
    ft_putnbr(i);
    return ;
}
