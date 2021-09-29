/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:19:20 by hmeriann          #+#    #+#             */
/*   Updated: 2021/05/14 12:52:24 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**array_free(char **res_array)
{
	size_t	i;

	i = 0;
	while (res_array[i])
	{
		free(res_array[i]);
		res_array[i] = NULL;
		i++;
	}
	free(res_array);
	res_array = NULL;
	return (NULL);
}

static size_t	words_counter(const char *s, size_t l, char c)
{
	size_t	words_count;
	int		state;

	words_count = 0;
	state = 0;
	while (s[l] != '\0')
	{
		if (s[l] == c)
			state = 0;
		else if (state == 0)
		{
			state = 1;
			words_count++;
		}
		l++;
	}
	return (words_count);
}

static void	action_with_str(const char *s, char **res_array, char c, \
							size_t right)
{
	size_t	left;
	size_t	line_num;

	line_num = 0;
	left = 0;
	while (s[right] != '\0')
	{
		while (s[right] == c && s[right] != '\0')
			right++;
		while (s[right] != c && s[right] != '\0')
		{
			right++;
			left++;
		}
		if (left > 0)
		{
			res_array[line_num] = ft_substr(s, right - left, left);
			if (res_array[line_num] == NULL)
				array_free(res_array);
			line_num++;
			left = 0;
		}
	}
	res_array[line_num] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	right;
	size_t	left;
	size_t	words_count;
	char	**res_array;

	if (s == NULL)
		return (NULL);
	left = 0;
	words_count = words_counter(s, left, c);
	res_array = (char **)malloc((words_count + 1) * sizeof(char *));
	if (res_array == NULL)
		return (NULL);
	right = 0;
	action_with_str(s, res_array, c, right);
	return (res_array);
}
