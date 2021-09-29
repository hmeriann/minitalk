/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:12:07 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:12:08 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init_tab(t_print *tab)
{
	tab->index = 0;
	tab->isnegative = 0;
	tab->left_align = 0;
	tab->zero_prefix = 0;
	tab->width = 0;
	tab->dot = 0;
	tab->tochnost = -1;
	tab->total_length = 0;
	return (tab);
}
