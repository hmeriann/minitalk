/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:22 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:23 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u_ralign(char *str, char sym, int len, t_print *tab)
{
	if (tab->tochnost >= 0 && tab->tochnost > len)
		while (tab->width-- - tab->tochnost > 0)
			ft_putchar(sym, tab);
	else
		while (tab->width-- - len > 0)
			ft_putchar(sym, tab);
	if (tab->isnegative == 1)
		ft_putchar('-', tab);
	if (tab->tochnost >= 0)
		while (tab->tochnost-- > len)
			ft_putchar('0', tab);
	ft_putstr(str, ft_strlen(str), tab);
}

void	ft_print_u_lalign(char *str, int len, t_print *tab)
{
	if (tab->isnegative == 1)
		ft_putchar('-', tab);
	if (tab->tochnost >= 0)
	{
		while (tab->tochnost-- > len)
		{
			ft_putchar('0', tab);
			tab->width--;
		}
	}
	ft_putstr(str, ft_strlen(str), tab);
	tab->width -= len;
	while (tab->width-- > 0)
		ft_putchar(' ', tab);
}

void	ft_print_u(unsigned int number, t_print *tab)
{
	char		*str;
	int			len;
	char		sym;
	long long	nbr;

	nbr = number;
	tab->isnegative = 0;
	sym = ' ';
	if (tab->zero_prefix == 1)
		sym = '0';
	if (!number && tab->tochnost == 0)
	{
		while (tab->width--)
			ft_putchar(sym, tab);
		return ;
	}
	str = ft_itoa(nbr, 10);
	len = ft_strlen(str);
	if (tab->left_align == 0)
		ft_print_u_ralign(str, sym, len, tab);
	else
		ft_print_u_lalign(str, len, tab);
	free(str);
}
