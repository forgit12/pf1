/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_p_f_w_sm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 22:10:04 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/26 19:24:51 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		countp(const char *str, int ivid, int iconv, t_list *lst)
{
	int j;

	lst->p_n = -1;
	j = iconv;
	while (ivid < j)
	{
		if (str[j] == '.')
		{
			lst->p_n = 0;
			j++;
			while (str[j] == '0')
				j++;
			if (str[j] < 48 || str[j] > 57)
				break ;
			while ((str[j] >= 48) && (str[j] <= 57))
			{
				lst->p_n = lst->p_n * 10 + (str[j] - '0');
				j++;
			}
		}
		if (lst->p_n != -1)
			break ;
		j--;
	}
}

void		countflags(const char *str, int ivid, int iconv, t_list *lst)
{
	int	j;

	iconv--;
	j = iconv;
	while (ivid < j)
	{
		if (str[j] == '#')
			lst->hash = 1;
		if (str[j] == '-')
			lst->min = 1;
		if (str[j] == '0' && (str[j - 1] < 48 || str[j - 1] > 57)
			&& (str[j - 1] != '.'))
            lst->nul = 1;
		if (str[j] == '+')
			lst->plus = 1;
		if (str[j] == ' ')
			lst->space = 1;
		j--;
	}
//	printf("\nlst->hash %d\n", lst->hash);
//	printf("\nlst-> %d\n", lst->min);
//	printf("\nlst->nul %d\n", lst->nul);
//	printf("\nlst->plus %d\n", lst->plus);
}

void		countwidth(const char *str, int ivid, int iconv, t_list *lst)
{
	int	j;
	
	j = ivid + 1;
	while (j < iconv && str[j])
	{
		while (str[j] == '0')
			j++;
		if ((str[j] >= 48 && str[j] <= 57) && str[j - 1] != '.')
		{
			lst->width = 0;
			while ((str[j] >= 48 && str[j] <= 57) && (j < iconv))
			{
				lst->width = lst->width * 10 + (str[j] - '0');
				j++;
			}
		}
		if (str[j] == '.')
        {
            j++;
            while ((str[j] >= 48) && (str[j] <= 57) && (j < iconv))
				j++;
        }
		j++;
	}
}

void		convsm(int h, int l ,int z, int j, t_list *lst)
{
//	printf("h %d\n", h);
//	int i;
	if (h > 0)
		lst->smodif = (h % 2 == 0) ? 1 : 2;
//	i = h % 2;
//	printf("mod %d", i);
	if (l > 0)
		lst->smodif = (l % 2 == 0) ? 3 : 4;
	if (j > 0)
		lst->smodif = 5;
	if (z > 0)
		lst->smodif = 7;
//	printf("sm %d\n", lst->smodif);
}

void		countsizemodifier(const char *str, int i, int iconv, t_list *lst)
{
	int h;
	int l;
	int	z;
	int	j;

	h = 0;
	l = 0;
	z = 0;
	j = 0;
	while (i < iconv)
	{
		if (str[i] == 'h')
			h++;
		if (str[i] == 'l')
			l++;
		if (str[i] == 'z')
			z++;
		if (str[i] == 'j')
			j++;
		i++;
	}
	convsm(h, l ,z, j, lst);
}
