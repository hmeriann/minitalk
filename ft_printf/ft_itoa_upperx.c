/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_upperx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 19:11:57 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:11:58 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	find_num_upperx(int len, unsigned long number, int base, char *str)
{
	while (len > 0)
	{
		str[len - 1] = number % base;
		if (number % base > 9)
			str[len - 1] += 'A' - 10;
		else
			str[len - 1] += '0';
		number /= base;
		len--;
	}
}

char	*ft_itoa_upperx(unsigned long long number, int base)
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
	str = (char *)malloc(sizeof(len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	find_num_upperx(len, number, base, str);
	return (str);
}
