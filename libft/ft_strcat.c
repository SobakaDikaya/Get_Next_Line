/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:34:37 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:03:17 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *append)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(dest);
	while (append[j] != '\0')
	{
		dest[i + j] = append[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}
