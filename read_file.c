/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:27:14 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/19 20:14:20 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"
#include "object.h"

int	check_format(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	if (i-- < 5)
		return (0);
	if (file[i--] != 'f')
		return (0);
	if (file[i--] != 'd')
		return (0);
	if (file[i--] != 'f')
		return (0);
	if (file[i--] != '.')
		return (0);
	return (1);
}

void	free_text(t_text **text)
{
	t_text	*aux;
	t_text	*tmp;

	if (!*text)
		return ;
	aux = *text;
	while (aux)
	{
		tmp = aux->next;
		free(aux->line);
		free(aux);
		aux = tmp;
	}
	*text = NULL;
}

void	add_line(t_text **text, char *line)
{
	t_text	*new_line;
	t_text	*aux;

	new_line = malloc(sizeof(t_text));
	if (!new_line)
		return (free_text(text), free(line));
	new_line->line = line;
	new_line->next = NULL;
	if (!*text)
	{
		*text = new_line;
		return ;
	}
	aux = *text;
	while (aux->next)
		aux = aux->next;
	aux->next = new_line;
}

t_text	*read_fd(int fd)
{
	t_text	*text;
	char	*line;

	text = NULL;
	line = (void *)1;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		add_line(&text, line);
		if (!text)
			break ;
	}
	return (text);
}

t_text	*read_file(char *filename)
{
	t_text	*text;
	int		fd;

	if (!check_format(filename))
	{
		write(2, "Wrong format file\n", 18);
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Opening file failed\n", 20);
		return (NULL);
	}
	text = read_fd(fd);
	close(fd);
	if (!text)
		write(2, "Reading file failed\n", 20);
	return (text);
}
/*
void	print_text(t_text *text)
{
	printf("Text:\n\"");
	while (text)
	{
		printf("%s", text->line);
		text = text->next;
	}
	printf("\"\n");
}

int	main(int argc, char **argv)
{
	t_text	*text;

	if (argc != 2)
		return (write(1, "Too many arguments\n", 19));
	text = read_file(argv[1]);
	if (!text)
		return (write(1, "No text\n", 8));
	print_text(text);
	free_text(&text);
}*/
