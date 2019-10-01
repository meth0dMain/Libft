/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndremora <ndremora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:36:13 by ndremora          #+#    #+#             */
/*   Updated: 2018/12/14 12:40:08 by ndremora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str2;

	str2 = (char *)str;
	while (*str2)
	{
		if (*str2 == c)
			return (str2);
		str2++;
	}
	if (*str2 == '\0' && !c)
		return (str2);
	return (NULL);
}
