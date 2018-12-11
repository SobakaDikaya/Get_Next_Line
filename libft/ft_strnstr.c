/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:34:42 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 18:11:24 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	if (ft_strlen((char *)find) == 0)
		return ((char *)src);
	i = 0;
	j = 0;
	while (*src && i < n)
	{
		j = 0;
		if (*src == find[j])
		{
			while (find[j] && find[j] == *(src + j)
				&& i + j < n)
				j++;
			if (find[j] == '\0')
				return ((char *)src);
		}
		src++;
		i++;
	}
	return (NULL);
}
