/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:39:13 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/15 05:08:18 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
#include "get_next_line.h"

int	ft_get_str_size(t_list *l)
{
	t_list	*cursor;
	int		j;
	int		i;

	cursor = l;
	i = 0;
	while (cursor != NULL)
	{
		j = 0;
		while (j < BUFFER_SIZE && (*cursor).content[j] != '\0')
			j++;
		i += j;
		cursor = (*cursor).next;
	}
	return (i);
}

char	*ft_get_str(t_list *l)
{
	t_list	*cursor;
	char	*str;
	int		j;
	int		i;
	int		size;

	size = ft_get_str_size(l);
	if (size == 0)
		return (NULL);
	str = malloc(sizeof(char) * size + 1);
	cursor = l;
	i = 0;
	while (cursor != NULL)
	{
		j = 0;
		while (j < BUFFER_SIZE && (*cursor).content[j] != '\0')
		{
			*(str + (j + i)) = (*cursor).content[j];
			j++;
		}
		i += j;
		cursor = (*cursor).next;
	}
	*(str + i) = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE] = {0};
	t_list		*l;
	char		*str;
	int			i;
	int			n_line;

	l = NULL;
	i = ft_strlen(buf);
	while (read(fd, (buf + i), BUFFER_SIZE - i) || i > 0)
	{
		n_line = find_newline(buf);
		ft_lstadd_back(&l, ft_lstnew(buf, n_line));
		i = 0;
		if (n_line == -1 || n_line >= 0)
			break ;
	}
	str = ft_get_str(l);
	ft_lstclear(&l);
	return (str);
}
