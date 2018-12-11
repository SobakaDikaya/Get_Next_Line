/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:05:29 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 16:01:30 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ctwd(char const *str, char c)
{
	unsigned int	i;
	int				cntr;

	i = 0;
	cntr = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			cntr++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (cntr);
}

static void	free_str(char **str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(*str);
}

char		**ft_strsplit(char const *s, char c)
{
	char			**str;
	int				i;
	int				len;
	int				ct;

	if (!s || !c)
		return (NULL);
	ct = 0;
	i = 0;
	if (!(str = (char **)malloc(sizeof(char *) * (ft_ctwd(s, c)) + 1)))
		return (NULL);
	while (s[ct])
	{
		while (s[ct] == c)
			ct++;
		len = ct;
		while (s[ct] && s[ct] != c)
			ct++;
		if (ct > len && ((str[i] = ft_strndup(s + len, ct - len)) == 0))
			free_str(str);
		else if (ct > len)
			i++;
	}
	str[i] = NULL;
	return (str);
}
