/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:52:22 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:04:53 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		c;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen((char *)s) - 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strcpy(ft_memalloc(sizeof(char) * 2), ""));
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	if (!(str = (char *)malloc(sizeof(char) * (len - i + 2))))
		return (NULL);
	c = 0;
	while (i <= len)
		str[c++] = s[i++];
	str[c] = '\0';
	return (str);
}
