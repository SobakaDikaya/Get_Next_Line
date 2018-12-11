/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:34:24 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:02:28 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ds;
	const unsigned char	*sc;

	ds = (unsigned char*)dest;
	sc = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		ds[i] = sc[i];
		if (sc[i] == (unsigned char)c)
		{
			i++;
			return (void *)(&ds[i]);
		}
		i++;
	}
	return (NULL);
}
