/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:56:32 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 16:55:07 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	max_min_handling(long long res, int sign)
{
	if (res > 2147483647)
	{
		if (sign == 0)
			return (-1);
		return (0);
	}
	return (1);
}

int	ft_atoi1(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 0;
	res = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit1(str[i + 1]))
		if (str[i++] == '-')
			sign = 1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (max_min_handling(res, sign) != 1)
			return (max_min_handling(res, sign));
		res = 10 * res + (str[i] - '0');
		i++;
	}
	if (sign == 1)
		res = -res;
	return (res);
}
