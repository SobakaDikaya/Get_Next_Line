/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srafe <srafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:49:10 by srafe             #+#    #+#             */
/*   Updated: 2018/12/03 19:27:45 by srafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*start;
	t_list		*node;

	if (!lst || !f || (node = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	node = f(lst);
	start = node;
	while (lst->next)
	{
		lst = lst->next;
		if ((node->next = (t_list*)malloc(sizeof(t_list))) == NULL)
		{
			ft_lstfree(start);
			return (NULL);
		}
		if ((node->next = f(lst)) == NULL)
		{
			ft_lstfree(start);
			return (NULL);
		}
		node = node->next;
	}
	return (start);
}
