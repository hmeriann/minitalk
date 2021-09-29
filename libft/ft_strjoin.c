/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:16:42 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 19:09:34 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join(char *total, char *begin, char *end)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (begin[i] != '\0')
	{
		total[i] = begin[i];
		i++;
	}
	j = 0;
	while (end[j] != '\0')
	{
		total[i + j] = end[j];
		j++;
	}
	total[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*begin;
	char	*end;
	char	*total;

	begin = (char *)s1;
	end = (char *)s2;
	if ((char *)s1 == NULL || (char *)s2 == NULL)
		return (NULL);
	total = (char *)malloc((ft_strlen1(s1) + ft_strlen1(s2) + 1) \
	* sizeof(char));
	if (total == NULL)
		return (NULL);
	join(total, begin, end);
	return (total);
}
