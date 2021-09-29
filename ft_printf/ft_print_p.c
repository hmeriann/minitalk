/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:32 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:33 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p_lalign(char *str, int len, t_print *tab)
{
	if (tab->left_align == 1)
	{
		ft_putstr("0x", 2, tab);
		ft_putstr(str, ft_strlen(str), tab);
		while (tab->width > (len + 2))
		{
			ft_putchar(' ', tab);
			tab->width--;
		}
	}
}

void	ft_print_p(unsigned long long number, t_print *tab)
{
	char	*str;
	int		len;

	if (tab->tochnost == 0 && number == 0)
	{
		ft_putstr("0x", 2, tab);
		return ;
	}
	str = ft_itoa(number, 16);
	len = ft_strlen(str);
	if (tab->tochnost != -1 && tab->tochnost > len)
		len = tab->tochnost;
	ft_print_p_lalign(str, len, tab);
	if (tab->left_align == 0)
	{
		while (tab->width > (len + 2))
		{
			ft_putchar(' ', tab);
			tab->width--;
		}
		ft_putstr("0x", 2, tab);
		ft_putstr(str, ft_strlen(str), tab);
	}
	free(str);
}
