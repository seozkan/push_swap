/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozkan <seozkan@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:43:32 by seozkan           #+#    #+#             */
/*   Updated: 2023/02/17 23:54:50 by seozkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	count_words(const char *str, char c)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 0;
	while (*str)
	{
		if (*str != c && toggle == 0)
		{
			toggle = 1;
			i++;
		}
		else if (*str == c)
			toggle = 0;
		str++;
	}
	return (i);
}

char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(str, c) + 1) * sizeof(char *));
	if (!str || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str)) && index >= 0)
		{
			split[j++] = word_dup(str, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
