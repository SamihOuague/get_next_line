/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:42:43 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/17 19:01:29 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*cursor;

	cursor = *lst;
	while (cursor != NULL)
	{
		tmp = (*cursor).next;
		free(cursor);
		cursor = tmp;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cursor;

	cursor = *lst;
	if (cursor == NULL)
	{
		*lst = new;
		return ;
	}
	while ((*cursor).next != NULL)
		cursor = (*cursor).next;
	(*cursor).next = new;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	(*tmp).content = content;
	(*tmp).next = NULL;
	return (tmp);
}

void	ft_memset(void *buf, int c, size_t siz)
{
	size_t	i;

	i = 0;
	while (i < siz)
	{
		*(unsigned char *)(buf + i) = (unsigned char) c;
		i++;
	}
}
