/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:52 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:53 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parcewidth(const char *str, t_print *tab, va_list ap)
{
	if (str[tab->index] == '*')
	{
		tab->width = va_arg(ap, int);
		if (tab->width < 0)
		{
			tab->left_align = 1;
			tab->width *= -1;
		}
		tab->index = tab->index + 1;
	}
	while (ft_isdigit(str[tab->index]))
	{
		tab->width = tab->width * 10 + (str[tab->index] - '0');
		tab->index = tab->index + 1;
	}
	return (tab->index);
}

int	ft_parcetochn(const char *str, t_print *tab, va_list ap)
{
	tab->dot = 1;
	tab->tochnost = 0;
	tab->index = tab->index + 1;
	if (str[tab->index] == '*' || ft_isdigit(str[tab->index]))
	{
		if (str[tab->index] == '*')
		{
			tab->tochnost = va_arg(ap, int);
			if (tab->tochnost < 0)
				tab->tochnost = -1;
			tab->index = tab->index + 1;
		}
		while (ft_isdigit(str[tab->index]))
		{
			tab->tochnost = tab->tochnost * 10 + (str[tab->index] - '0');
			tab->index = tab->index + 1;
		}
		tab->zero_prefix = 0;
	}
	return (tab->index);
}

int	ft_parceflags(const char *str, t_print *tab, va_list ap)
{
	if (str[tab->index] == '-' && str[tab->index + 1] != '\0')
	{
		tab->left_align = 1;
		tab->index = tab->index + 1;
	}
	if (str[tab->index] == '0' && str[tab->index + 1] != '\0')
	{
		tab->zero_prefix = 1;
		tab->index = tab->index + 1;
	}
	if (str[tab->index] == '*' || ft_isdigit(str[tab->index]))
		ft_parcewidth(str, tab, ap);
	if (str[tab->index] == '.' && str[tab->index + 1] != '\0')
		ft_parcetochn(str, tab, ap);
	return (tab->index);
}

void	ft_parcespec(const char *str, t_print *tab, va_list ap)
{
	if (str[tab->index] == 's')
		ft_print_str(va_arg(ap, char *), tab);
	else if (str[tab->index] == 'x')
		ft_print_x(va_arg(ap, unsigned int), tab);
	else if (str[tab->index] == 'X')
		ft_print_upperx(va_arg(ap, unsigned int), tab);
	else if (str[tab->index] == 'd' || str[tab->index] == 'i')
		ft_print_d(va_arg(ap, int), tab);
	else if (str[tab->index] == '%')
		ft_putchar(str[tab->index], tab);
	else if (str[tab->index] == 'c')
		ft_print_c(va_arg(ap, int), tab);
	else if (str[tab->index] == 'u')
		ft_print_u(va_arg(ap, unsigned int), tab);
	else if (str[tab->index] == 'p')
		ft_print_p(va_arg(ap, unsigned long long), tab);
	else
		tab->index = tab->index + 1;
}
