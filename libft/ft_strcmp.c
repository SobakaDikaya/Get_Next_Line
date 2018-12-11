/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 12:49:05 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 16:08:01 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	unsigned int i;

	i = 0;
	while ((str1[i] != '\0' && str2[i] != '\0') && str1[i] == str2[i])
		i++;
	return ((const unsigned char)str1[i] - (const unsigned char)str2[i]);
}
