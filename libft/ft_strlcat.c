/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:07:30 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:03:51 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	slen;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	slen = i;
	while (src[i - slen] != '\0' && i < size - 1)
	{
		dst[i] = src[i - slen];
		i++;
	}
	if (slen < size)
		dst[i] = '\0';
	return (slen + ft_strlen(src));
}
