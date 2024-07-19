/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:18:44 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/19 12:47:03 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char *stash;
	char *line;
	char *buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	while (!ft_strchr(stash, '\n') && (read(fd, buffer, BUFFER_SIZE) > 0))
	{
		buffer[BUFFER_SIZE] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	if (!ft_strchr(stash, '\n'))
	{
		line = ft_strdup(stash);
		free(stash);
		stash = NULL;
		return (line);
	}
	line = ft_substr(stash, 0, (size_t)(ft_strchr(stash, '\n') - stash));
	stash = ft_strdup(ft_strchr(stash, '\n') + 1);
	return (line);
}

// int main(void)
// {
//     int fd;
//     char *line;

//     fd = open("test.txt", O_RDONLY);
//     while ((line = get_next_line(fd)))
//     {
//         printf("%s\n", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }