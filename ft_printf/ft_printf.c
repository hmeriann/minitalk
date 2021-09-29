/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:16 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:17 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_print_main(t_print *tab, const char *str, va_list ap)
{
	while (str[tab->index] != '\0')
	{
		tab->left_align = 0;
		if (str[tab->index] == '%' && str[tab->index + 1] != '\0')
		{
			tab->width = 0;
			tab->tochnost = -1;
			tab->index = tab->index + 1;
			while (str[tab->index] == '0' || str[tab->index] == '-')
				ft_parceflags(str, tab, ap);
			if (str[tab->index] == '*' || ft_isdigit(str[tab->index]))
				ft_parcewidth(str, tab, ap);
			if (str[tab->index] == '.' && str[tab->index + 1] != '\0')
				ft_parcetochn(str, tab, ap);
			ft_parcespec(str, tab, ap);
		}
		else
			ft_putchar(str[tab->index], tab);
		tab->index = tab->index + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	t_print	*tab;

	i = 0;
	tab = (t_print *)malloc(sizeof (t_print));
	if (!tab)
		return (-1);
	va_start(ap, str);
	ft_init_tab(tab);
	ft_make_print_main(tab, str, ap);
	va_end(ap);
	i = tab->total_length;
	free(tab);
	return (i);
}
