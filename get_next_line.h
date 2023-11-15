/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:38:05 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/15 06:31:21 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_list
{
	char			content[BUFFER_SIZE];
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(char *buf, int n_line);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_memset(void *buf, int c, size_t siz);
void	ft_lstclear(t_list **lst);
char	*get_next_line(int fd);
char	*ft_get_str(t_list *l);
int		find_newline(char *buf);
int		ft_get_str_size(t_list *l);
int		ft_strlen(char *str);
