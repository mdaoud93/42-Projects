/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaoud <mdaoud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 13:39:22 by mdaoud            #+#    #+#             */
/*   Updated: 2018/11/21 19:57:47 by mdaoud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list		*get_current_file(t_list **files, int fd)
{
	t_list		*temp;
	char		*empty;

	temp = *files;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	empty = ft_strdup("");
	ft_lstadd_head(files, ft_lstnew(empty, 1));
	ft_strdel(&empty);
	(*files)->content_size = fd;
	return (*files);
}

char		*get_next_token(t_list *file)
{
	char	*end;
	char	*temp;
	char	*token;

	token = file->content;
	end = ft_strchr(file->content, '\n');
	if (end == NULL)
		return (NULL);
	*end = '\0';
	token = ft_strsub(file->content, 0, end - token + 1);
	if (token == NULL)
	{
		ft_strdel(&token);
		return (NULL);
	}
	end++;
	temp = ft_strdup(end);
	if (temp == NULL)
	{
		ft_strdel(&temp);
		return (NULL);
	}
	free(file->content);
	file->content = temp;
	return (token);
}

int			return_line(int read_retval, t_list *current_file,
						char *token, char **line)
{
	if (read_retval < 0)
		return (-1);
	if (*(char *)(current_file->content) == '\0' && read_retval == 0)
		return (0);
	if (read_retval == 0 && token == NULL)
	{
		*line = ft_strdup(current_file->content);
		free(current_file->content);
		current_file->content = ft_strdup("");
	}
	else
	{
		*line = ft_strdup(token);
		ft_strdel(&token);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*files = NULL;
	t_list			*current_file;
	int				read_retval;
	char			*token;
	char			buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	read_retval = 1;
	token = NULL;
	current_file = NULL;
	current_file = get_current_file(&files, fd);
	while ((token = get_next_token(current_file)) == NULL)
	{
		if ((read_retval = read(fd, buff, BUFF_SIZE)) <= 0)
			break ;
		buff[read_retval] = '\0';
		current_file->content = ft_strjoin(current_file->content, buff, 1);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	read_retval = return_line(read_retval, current_file, token, line);
	if (read_retval == 0)
		ft_lstremove(&files, &current_file);
	return (read_retval);
}
