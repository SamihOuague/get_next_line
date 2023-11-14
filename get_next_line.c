/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:39:13 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/14 04:02:26 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

typedef struct s_list
{
	char			content[BUFFER_SIZE];
	struct s_list	*next;
}	t_list;

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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
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

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE] = {0};
	t_list	*l;
	t_list	*tmp;
	t_list	*cursor;
	int	i;
	int	j;
	int	n_line;
	
	l = NULL;
	i = 0;
	while (buf[i] != '\0')
		i++;
	while (read(fd, (buf + i), BUFFER_SIZE - i))
	{
		tmp = malloc(sizeof(t_list));
		ft_memset((*tmp).content, 0, BUFFER_SIZE);
		n_line = find_newline(buf);
		if (n_line < 0)
		{
			j = 0;
			while (j < BUFFER_SIZE)
			{
				ft_memset((*tmp).content + j, buf[j], 1);
				j++;
			}
			(*tmp).next = l;
			l = tmp;
			if (find_newline(buf) == -1)
			{
				ft_memset(buf, 0, BUFFER_SIZE);
				break ;
			}
		}
		else
		{
			j = 0;
			while (j <= n_line)
			{
				ft_memset((*tmp).content + j, buf[j], 1);
				if (j < n_line)
					ft_memset((buf + j), buf[j + n_line + 1], 1);
				j++;
			}
			(*tmp).next = l;
                        l = tmp;
			break ;
		}
	}
	return (NULL);
}

int	main(void)
{
	get_next_line(0);
	get_next_line(0);
	get_next_line(0);
	return (0);
}
