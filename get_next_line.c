/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:31:07 by srafe             #+#    #+#             */
/*   Updated: 2018/12/13 16:31:15 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ret_res(char *str, char **line)
{
	int		i;
	int		j;
	char	*temp;
	char	*del;

	i = 0;
	temp = ft_strnew(0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	j = ft_strlen(&str[i]);
	del = temp;
	temp = ft_strsub(str, i + 1, j);
	ft_strdel(&del);
	(*line) = ft_strsub(str, 0, i);
	ft_strdel(&str);
	return (temp);
}

int		get_next_line(const int fd, char **line)
{
	int			j;
	char		buf[BUFF_SIZE + 1];
	static char	*str[4096];
	char		*del;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	while (!ft_strchr(str[fd], '\n') && (j = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[j] = '\0';
		del = str[fd];
		str[fd] = ft_strjoin(del, buf);
		ft_strdel(&del);
	}
	if (*str[fd] != '\0')
	{
		str[fd] = ret_res(str[fd], line);
		return (1);
	}
	ft_strdel(&str[fd]);
	return (0);
}
