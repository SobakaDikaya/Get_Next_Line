/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:03:21 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 13:02:11 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long nb)
{
	int		len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char		*ft_stwist(char *str, int i, int neg)
{
	int		j;
	char	s;

	j = 0;
	if (neg == -1)
		j++;
	while (i >= j)
	{
		s = str[i];
		str[i] = str[j];
		str[j] = s;
		i--;
		j++;
	}
	return (str);
}

static char		*ft_toarr(int n, char *str, int *i)
{
	while (n != 0)
	{
		str[*i] = (n % 10) + '0';
		n = n / 10;
		*i = *i + 1;
	}
	str[*i] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		neg;

	if (!(str = malloc(sizeof(char) * ft_len(n) + 1)))
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, "-2147483648"));
	i = 0;
	neg = 0;
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	if (n < 0)
	{
		str[i++] = '-';
		n = n * -1;
		neg--;
	}
	str = ft_toarr(n, str, &i);
	str = ft_stwist(str, i - 1, neg);
	return (str);
}
