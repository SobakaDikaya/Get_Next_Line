/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:37:51 by srafe             #+#    #+#             */
/*   Updated: 2018/12/06 13:09:53 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *source, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;

	if (dst < source)
		ft_memcpy(dst, source, n);
	else if (dst > source)
	{
		dest = dst;
		src = source;
		while (n--)
			dest[n] = src[n];
	}
	return (dst);
}
