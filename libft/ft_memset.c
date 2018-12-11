/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:52:44 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:02:48 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char	*p;
	int				i;

	i = 0;
	p = (unsigned char *)buf;
	while (i < (int)count)
	{
		p[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
