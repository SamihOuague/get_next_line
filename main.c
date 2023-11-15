/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaguen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:01:55 by  souaguen         #+#    #+#             */
/*   Updated: 2023/11/15 08:05:05 by souaguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#elif BUFFER_SIZE >= 65535
# undef BUFFER_SIZE
# define BUFFER_SIZE 65535
#endif
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	char	*str;
	int		fd;

	if (argc != 2)
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
	while (str != NULL)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
