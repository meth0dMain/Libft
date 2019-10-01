/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:53:19 by ndremora          #+#    #+#             */
/*   Updated: 2019/01/14 13:06:07 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		counter(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s != '\0' && *s != c)
			s++;
	}
	return (count);
}

static int		position(const char *s, int j, char c)
{
	int		i;

	i = 0;
	while (s[j + i] != '\0')
	{
		if (s[j + i] == c)
			return (j + i);
		i++;
	}
	return (j + i);
}

static char		*whole_word(char const *s, int j, char c)
{
	int		i;
	int		end;
	char	*word;

	i = 0;
	end = position(s, j, c);
	if (!(word = ft_memalloc(end - j + 1u)))
		return (NULL);
	while (s[i] != '\0' && end > j)
	{
		word[i] = s[j];
		j++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char		*freemem(char **array, int i)
{
	while (--i > 0)
		free(array[i]);
	free(array);
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	size_t	len;
	int		h;

	i = 0;
	j = 0;
	if (!s || !(array = ft_memalloc(counter(s, c) + 1u)))
		return (NULL);
	h = counter(s, c);
	while (h > i)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		len = ft_strlen(whole_word(s, j, c));
		if (!(array[i] = ft_memalloc(len)))
			freemem(*&array, i);
		array[i] = whole_word(s, j, c);
		j = position(s, j, c);
		i++;
	}
	array[i] = 0;
	return (array);
}
