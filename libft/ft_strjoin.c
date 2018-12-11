/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:07:23 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:03:45 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(str = (char *)malloc(((sizeof(*s1) + sizeof(*s2)) * i + 1))))
		return (0);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
