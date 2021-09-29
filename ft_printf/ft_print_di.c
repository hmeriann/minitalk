/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:36 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:37 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d_ralign(int len, t_print *tab)
{
	if (tab->left_align == 0)
	{
		if (tab->tochnost == 0)
			while (tab->width-- > len)
				ft_putchar(' ', tab);
		else
			while (tab->width-- > tab->tochnost)
				ft_putchar(' ', tab);
	}
}

void	ft_print_tochn_pstv(char *str, int len, t_print *tab)
{
	if (tab->tochnost >= tab->width)
	{
		if (tab->isnegative)
			ft_putchar('-', tab);
		while (tab->tochnost-- > len)
			ft_putchar('0', tab);
		ft_putstr(str, len, tab);
	}
	else
	{
		ft_print_d_ralign(len, tab);
		if (tab->isnegative)
			ft_putchar('-', tab);
		while (tab->tochnost-- > len)
		{
			ft_putchar('0', tab);
			tab->width--;
		}
		ft_putstr(str, len, tab);
		if (tab->left_align == 1)
			while (tab->width-- > len)
				ft_putchar(' ', tab);
	}
}

void	ft_make_print_d(long long nbr, t_print *tab)
{
	char		*str;
	int			len;

	str = ft_itoa(nbr, 10);
	len = ft_strlen(str);
	if (tab->tochnost >= 0)
		ft_print_tochn_pstv(str, len, tab);
	else
	{
		if (tab->isnegative)
			ft_putchar('-', tab);
		if (tab->left_align == 0)
		{
			if (tab->zero_prefix)
				while (tab->width-- > len)
					ft_putchar('0', tab);
			while (tab->width-- > len)
				ft_putchar(' ', tab);
		}
		ft_putstr(str, len, tab);
		if (tab->left_align == 1)
			while (tab->width-- > len)
				ft_putchar(' ', tab);
	}
	free(str);
}

void	ft_print_d(int number, t_print *tab)
{
	int			len;
	char		sym;
	long long	nbr;

	nbr = number;
	tab->isnegative = 0;
	sym = ' ';
	len = 0;
	if (tab->zero_prefix == 1 && tab->width > len && tab->tochnost <= 0)
		sym = '0';
	if (!number && tab->tochnost == 0)
	{
		while (tab->width--)
			ft_putchar(sym, tab);
		return ;
	}
	if (number < 0)
	{
		tab->isnegative = 1;
		nbr *= -1;
		tab->width--;
	}
	ft_make_print_d(nbr, tab);
}
