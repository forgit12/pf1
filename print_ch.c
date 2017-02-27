/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:38:08 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/27 19:59:37 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ch(t_list *lst)
{
//	write(1, "r", 1);
	while (--lst->width > 0 && lst->min != 1 && lst->nul != 1)
		ft_putchar(' ');
	while (lst->width-- > 0 && lst->min != 1 && lst->nul == 1)
		ft_putchar('0');
	ft_putchar(lst->ch);
	while (lst->width-- + 1 > 0 && lst->min == 1 && lst->nul != 1)
		ft_putchar(' ');
}
