/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:50:23 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:04:50 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		i;

	if (!s || (len > (size_t)-1))
		return (0);
	i = 0;
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (0);
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[len] = '\0';
	return (str);
}
