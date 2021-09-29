/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:41 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:42 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(int c, t_print *tab)
{
	int	len;

	len = 1;
	if (tab->tochnost != -1 && tab->tochnost < len)
		len = tab->tochnost;
	if (tab->left_align == 1)
		ft_putchar((unsigned char)c, tab);
	while (tab->width > len)
	{
		ft_putchar(' ', tab);
		tab->width--;
	}
	if (tab->left_align == 0)
		ft_putchar((unsigned char)c, tab);
}
