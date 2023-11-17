/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:41:53 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/17 21:07:10 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_endline(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(buf + i) == '\0')
			return (-1);
		else if (*(buf + i) == '\n')
			return (i);
		i++;
	}
	return (-2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_get_size(t_list *l)
{
	t_list	*cursor;

	cursor = l;
        i = 0;
        while (cursor != NULL)
        {
                i += ft_strlen((*cursor).content);
                cursor = (*cursor).next;
        }
	return (i);
}

char	*ft_get_str(t_list **l)
{
	t_list	*cursor;
	char	*str;
	int	i;
	int	len;

	str = malloc(sizeof(char) * ft_get_size(*l) + 1);
	if (str == NULL)
		return (NULL)
	cursor = *l;
	i = 0;
	len = 0;
	while (cursor != NULL)
	{
		if (*((*cursor).content + len) == '\0')
		{
			cursor = (*cursor).next;
			len = 0;
		}
		else
		{
			*(str + i) = *((*cursor).content + len);
			i++;
			len++;
		}
	}
	*(str + i) = '\0';
	return (str);
}


char	*get_next_line(int fd)
{
	static t_list	*buf = ft_lstnew(NULL);
	t_list			*cursor;
	char			*tmp;
	int				len;
	int				n_line;

	if (buf == NULL)
		return (NULL);
	cursor = buf;
	len = 0;
	if ((*cursor).content == NULL)
	{
		(*cursor).content = malloc(BUFFER_SIZE + 1);
		ft_memset(cursor, 0, BUFFER_SIZE + 1);
	}
	len = ft_strlen((*buf).content);
	while (read(fd, (*cursor).content + len, BUFFER_SIZE))
	{
		n_line = ft_find_endline((*cursor).content);
		if (n_line >= 0)
		{
			tmp = malloc(sizeof(char) * (BUFFER_SIZE - n_line) + 1);
			ft_lstadd_back(&buf, ft_lstnew());
			return (ft_get_str(&buf));	
		}
		tmp = malloc(len + BUFFER_SIZE + 1);
                if (tmp == NULL)
                        return (NULL);
                ft_memset(tmp, 0, len + BUFFER_SIZE + 1)
		ft_lstadd_back(&buf, ft_lstnew(tmp));
		cursor = (*cursor).next;
	}
	return (NULL);
}


