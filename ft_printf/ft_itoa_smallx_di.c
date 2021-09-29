/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_smallx_di.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:12:02 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:12:03 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_find_num_idx(int len, unsigned long number, int base, char *str)
{
	while (len > 0)
	{
		str[len - 1] = number % base;
		if (number % base > 9)
			str[len - 1] += 'a' - 10;
		else
			str[len - 1] += '0';
		number /= base;
		len--;
	}
}

char	*ft_itoa(unsigned long long number, int base)
{
	unsigned long	tmp_num;
	int				len;
	char			*str;

	tmp_num = number;
	len = 0;
	str = NULL;
	if (number == 0)
		len += 1;
	while (tmp_num > 0)
	{
		tmp_num /= base;
		len += 1;
	}
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	ft_find_num_idx(len, number, base, str);
	return (str);
}
