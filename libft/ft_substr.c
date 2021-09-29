/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 15:05:22 by hmeriann          #+#    #+#             */
/*   Updated: 2021/09/26 16:51:13 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	return_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen1(s);
	if (s_len < start)
		return (ft_strdup(""));
	return_len = ft_min((s_len - start), len);
	tmp = (char *)malloc(sizeof(char) * (return_len + 1));
	if (tmp == NULL)
		return (NULL);
	ft_strlcpy(tmp, s + start, return_len + 1);
	return (tmp);
}
