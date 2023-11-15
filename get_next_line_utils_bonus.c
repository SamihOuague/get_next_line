/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:42:43 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/15 07:49:33 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#elif BUFFER_SIZE >= 65535
# undef BUFFER_SIZE
# define BUFFER_SIZE 65535
#endif
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

t_list	*ft_lstnew(char *buf, int n_line)
{
	t_list	*tmp;
	int		j;

	tmp = malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	(*tmp).next = NULL;
	ft_memset((*tmp).content, 0, BUFFER_SIZE);
	j = -1;
	if (n_line >= 0)
	{
		while ((++j) < BUFFER_SIZE)
		{
			if (j <= n_line)
				ft_memset(((*tmp).content + j), buf[j], 1);
			else
				ft_memset((buf + (j - n_line - 1)), (char) buf[j], 1);
			ft_memset((buf + j), 0, 1);
		}
		return (tmp);
	}
	while ((++j) < BUFFER_SIZE)
		ft_memset((*tmp).content + j, buf[j], 1);
	ft_memset(buf, 0, BUFFER_SIZE);
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

int	find_newline(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buf[i] == '\n')
			return (i);
		else if (buf[i] == '\0')
			return (-1);
		i++;
	}
	return (-2);
}
