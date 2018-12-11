/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:52:37 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:04:46 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src1, const char *src2)
{
	int	i;
	int	j;
	int	k;

	if (src2[0] == '\0')
		return ((char *)&src1[0]);
	i = 0;
	while (src1[i] != '\0')
	{
		k = -1;
		j = 0;
		if (src2[j] == src1[i])
		{
			k = i;
			while (src2[j] != '\0' && src2[j] == src1[i + j])
				j++;
			if (src2[j] == '\0')
				return ((char *)&src1[k]);
		}
		i++;
	}
	return (NULL);
}
