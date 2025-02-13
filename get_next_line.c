/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorillo <emorillo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:33:05 by emorillo          #+#    #+#             */
/*   Updated: 2025/01/17 19:15:13 by emorillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update(char *remainder)
{
	int		len;
	char	*new;
	int		i;
	int		j;

	if (remainder == NULL)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	if (remainder[i] == '\n')
		i++;
	if (remainder[i] == '\0')
		return (ft_clean(&remainder));
	len = ft_strlen(remainder);
	new = malloc(sizeof(char) * (len - i) + 1);
	if (new == NULL)
		return (ft_clean(&remainder));
	j = 0;
	while (remainder[i] != '\0')
		new[j++] = remainder[i++];
	new[j] = '\0';
	free(remainder);
	return (new);
}

char	*read_line(int fd, char *rem)
{
	char	*buffer;
	int		b_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	buffer[0] = '\0';
	b_read = 1;
	while (b_read > 0 && !ft_strchr(buffer, '\n'))
	{
		b_read = read (fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		if (b_read > 0)
		{
			buffer[b_read] = '\0';
			rem = ft_strjoin(rem, buffer);
		}
	}
	free(buffer);
	return (rem);
}

char	*get_line(char *remain)
{
	char	*line;
	int		j;
	int		i;

	if (remain == NULL || !remain)
		return (NULL);
	i = 0;
	while (remain[i] != '\n' && remain[i] != '\0')
		i++;
	if (remain[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = remain[j];
		j++;
	}
	line[i] = '\0';
	if (j == 0)
		return (free(line), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*newline;

	newline = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	remainder = read_line (fd, remainder);
	if (remainder == NULL || !remainder)
		return (NULL);
	newline = get_line(remainder);
	if (newline == NULL)
		return (NULL);
	remainder = update(remainder);
	return (newline);
}
/*
int main(void)
{
	int fd;
   char *line;
	
    // Abre el archivo en modo solo lectura
    fd = open("prueba.txt", O_RDONLY);
	if (fd < 0)
    {
	    perror("Error al abrir el archivo");
        return (1);
    }
	// Llama a get_next_line en un bucle para leer todas las líneas del archivo
    while ((line = get_next_line(fd)) != NULL)
    {
		printf("%s", line);
		free(line); // Libera la memoria asignada por get_next_line
}
    // Cierra el archivo
    close(fd);
    return (0);
}*/
/*
int	main()
{
	char *line;
	line = get_next_line(1);
	printf("%s", line);
	return (0);
}*/
