/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oborysen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:04:51 by oborysen          #+#    #+#             */
/*   Updated: 2017/02/27 23:05:11 by oborysen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
**
*/
# include <string.h>
# include <stdio.h>

int		g_symb;

typedef struct		s_list
{
	int				min;
	int				nul;
	int				plus;
	int				space;
	int				hash;
	int				width;
	int				p_n;
	int				smodif;
	int				conv;
	int				nsymb;
	int				minus;
	char			ch;
	struct s_list	*next;
}					t_list;

int     			ft_printf(const char *str, ...);
void				printconvlet(t_list *lst, va_list ap);
int					*print_symb(const char *str, int *i, va_list ap);
void				countp(const char *str, int ivid, int iconv, t_list *lst);
void				countflags(const char *str, int ivid, int iconv, t_list *lst);
void				countwidth(const char *str, int ivid, int iconv, t_list *lst);
void				convsm(int h, int l ,int z, int j, t_list *lst);
void				countsizemodifier(const char *str, int i, int iconv, t_list *lst);
void				nullst(t_list *lst);
void				conversionletter(const char *str, int *i, t_list *lst);
void				conversionletter2(const char *str, int *i, t_list *lst);
t_list				*recognition_flags(const char *str, int *i, t_list *lst);
void				countnumsymb(t_list *lst, uintmax_t i);
void				printprecision_x(t_list *lst, char *s);
void				print_xstr(char *s, t_list *lst);
void				print_xstr_hash(char *s, t_list *lst);
void				print_xstr_hash_p(char *s, t_list *lst);
void				ft_putpercent(int *i);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(uintmax_t n);
size_t				ft_strlen(const char *s);
void				printprecision(t_list *lst, uintmax_t i);
void				printi(t_list *lst, void *nt);
void				f(unsigned long value, int base1, char *str, int *i, t_list *lst);
void				print_x(t_list *lst, void *nt, unsigned long base, int i);
void				print_s(t_list *lst, void *str);
void				print_s_p(t_list *lst, char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				conv_p_s(t_list *lst, const char *str, int ivid, int iconv);
void				f_p(unsigned long value, int base1, char *str, int *i, t_list *lst);
void   				print_p(t_list *lst, void *nt, unsigned long base);
void				print_p_str(char *s, t_list *lst);
void				print_p_hash(char *s, t_list *lst);
void				print_p_precision(char *s, t_list *lst);
void				printfix(char *s, t_list *lst);
void				print_c(t_list *lst, void *s);
void				conv_sm(t_list *lst, long *i, void *nt);
void				print_vids(t_list *lst);
void				conv_sm_x_o(t_list *lst, unsigned long *value, void *nt);
void				pint_fix_min(char *s, t_list *lst);
void				nul_x(char *str, t_list *lst);
void				ft_nul_width(t_list *lst);
void				ft_nul_min(char *str, t_list *lst);
void				ft_hash_p_n(t_list *lst);
void				print_ch(t_list *lst);
void				print_p_m_symb(t_list *lst, uintmax_t i);
void				print_d_i_null_p_n(t_list *lst);
char				*s_null();
void				print_fix_minus_d(t_list *lst, uintmax_t i);

#endif
