/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:08 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:09 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_print *tab)
{
	write(1, &c, 1);
	tab->total_length = tab->total_length + 1;
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str, int len, t_print *tab)
{
	while (*str != '\0' && len > 0)
	{
		ft_putchar(*str, tab);
		str++;
		len--;
	}
}

void	ft_print_str(char *str, t_print *tab)
{
	int	len;

	if (str == 0)
		str = "(null)";
	len = ft_strlen(str);
	if (tab->tochnost != -1 && tab->tochnost < len)
		len = tab->tochnost;
	if (tab->left_align == 1)
		ft_putstr(str, len, tab);
	while (tab->width > len)
	{
		ft_putchar(' ', tab);
		tab->width--;
	}
	if (tab->left_align == 0)
		ft_putstr(str, len, tab);
}
