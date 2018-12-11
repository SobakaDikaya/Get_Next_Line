/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:11:09 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:01:44 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	i;
	long int	j;
	int			k;

	i = 0;
	j = 0;
	k = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
		str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		k = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] > 47 && str[i] < 58)
		j = (j * 10) + (str[i++] - 48);
	j = j * (long)k;
	return ((int)j);
}
