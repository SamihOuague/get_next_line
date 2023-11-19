/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:42:43 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/19 06:56:01 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*cursor;

	cursor = *lst;
	while (cursor != NULL)
	{
		tmp = (*cursor).next;
		free((*cursor).content);
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
		*(char *)(buf + i) = (char) c;
		i++;
	}
}

int	find_newline(char *buf, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (buf[i] == '\n')
			return (i);
		else if (buf[i] == '\0')
			return (-1);
		i++;
	}
	return (-2);
}
