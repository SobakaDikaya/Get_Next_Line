/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:19:49 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:04:13 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < (int)n)
	{
		dest[i] = src[i];
		i++;
	}
	if (src[i] == '\0' && i < (int)n)
	{
		while (i < (int)n)
		{
			dest[i] = '\0';
			i++;
		}
	}
	return (dest);
}
