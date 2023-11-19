/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:01:55 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/19 06:35:54 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	if (argc != 3)
	{
		printf("Usage : ./a.out [FILENAME]\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		printf("File not found.\n");
		return (2);
	}
	str = get_next_line(fd);
	i = 0;
	while (str != NULL && i < atoi(argv[2]))
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
