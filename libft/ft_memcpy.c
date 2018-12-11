/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:04:00 by srafe             #+#    #+#             */
/*   Updated: 2018/12/06 13:11:15 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ds;
	const unsigned char	*sc;

	ds = dest;
	sc = src;
	i = 0;
	while (i < n)
	{
		ds[i] = sc[i];
		i++;
	}
	return (dest);
}
