/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:39:13 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/19 12:57:01 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_get_str_size(t_list *l, char *str)
{
	t_list	*cursor;
	int		j;
	int		i;

	cursor = l;
	i = 0;
	if (str != NULL)
	{
		while (*(str + i) != '\0')
			i++;
		return (i);
	}
	while (cursor != NULL)
	{
		j = 0;
		while ((*cursor).content[j] != '\0')
			j++;
		i += j;
		cursor = (*cursor).next;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL && n > 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		i++;
	}
	return (dest);
}

char	*ft_get_str(t_list **l)
{
	t_list	*cursor;
	char	*str;
	int		j;
	int		i;
	int		size;

	size = ft_get_str_size(*l, NULL);
	if (size == 0)
		return (NULL);
	str = malloc(sizeof(char) * size + 1);
	cursor = *l;
	i = 0;
	while (cursor != NULL)
	{
		j = -1;
		while ((*cursor).content[(++j)] != '\0')
			*(str + (j + i)) = (*cursor).content[j];
		i += j;
		cursor = (*cursor).next;
	}
	*(str + i) = '\0';
	ft_lstclear(l);
	return (str);
}

int	ft_set_list(t_list **lst, char *buf)
{
	char	*str;
	int		len;
	int		n_line;

	str = NULL;
	len = ft_get_str_size(NULL, buf);
	n_line = find_newline(buf, BUFFER_SIZE);
	if (n_line >= 0)
	{
		str = malloc(sizeof(char) * n_line + 2);
		ft_memcpy(str, buf, n_line + 1);
		*(str + n_line + 1) = '\0';
		ft_memcpy(buf, (buf + n_line + 1), BUFFER_SIZE - n_line);
		if (n_line == (len - 1))
			ft_memset(buf, 0, BUFFER_SIZE);
	}
	else
	{
		str = malloc(sizeof(char) * BUFFER_SIZE + 1);
		ft_memcpy(str, buf, BUFFER_SIZE + 1);
		if (n_line == -1)
			ft_memset(buf, 0, BUFFER_SIZE);
	}
	ft_lstadd_back(lst, ft_lstnew(str));
	return (ft_get_str_size(NULL, buf));
}

char	*get_next_line(int fd)
{
	static char	buf[64][BUFFER_SIZE + 1] = {0};
	t_list		*l;
	int			n_line;
	int			len;
	int			n_read;

	if (fd < 0 || fd >= 64)
		return (NULL);
	l = NULL;
	len = ft_get_str_size(NULL, buf[fd]);
	if (len > 0 && ft_set_list(&l, buf[fd]) != 0)
		return (ft_get_str(&l));
	n_read = read(fd, buf[fd], BUFFER_SIZE);
	while (n_read != 0)
	{
		if (n_read < 0)
			return (ft_lstclear(&l));
		n_line = find_newline(buf[fd], BUFFER_SIZE);
		ft_set_list(&l, buf[fd]);
		if (n_line >= 0 || n_line == -1)
			break ;
		ft_memset(buf[fd], 0, BUFFER_SIZE);
		n_read = read(fd, buf[fd], BUFFER_SIZE);
	}
	return (ft_get_str(&l));
}
