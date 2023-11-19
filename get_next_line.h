/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:38:05 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/19 05:54:57 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char *buf);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_memset(void *buf, int c, size_t siz);
void	ft_lstclear(t_list **lst);
char	*get_next_line(int fd);
char	*ft_get_str(t_list **l);
int		find_newline(char *buf, size_t size);
int		ft_get_str_size(t_list *l, char *str);
int		ft_strlen(char *str);
#endif
