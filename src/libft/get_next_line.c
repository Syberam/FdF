/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 18:25:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/06/08 17:00:38 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_fill_line(char **line, char *buff)
{
	char			*tmp;

	tmp = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	*line = ft_ext_strjoin_free(*line, ft_strccpy(tmp, buff, '\n'),
				(*line ? 3 : 2));
	if (ft_strchr(buff, '\n'))
		buff = ft_strcpy(buff, ft_strchr(buff, '\n') + 1);
	else
		ft_bzero(buff, BUFF_SIZE + 1);
}

static t_gnl		*ft_new_fd(int fd)
{
	t_gnl			*new;

	if (!(new = (t_gnl *)ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	if (!(new->content = ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static t_gnl		*ft_select_fd(t_gnl **begin, int fd)
{
	t_gnl			*current;

	if (!*begin)
		*begin = ft_new_fd(fd);
	current = *begin;
	while (current)
	{
		if (fd == current->fd)
			return (current);
		else if (!(current->next))
			current->next = ft_new_fd(fd);
		current = current->next;
	}
	return (current);
}

int					gnl(const int fd, char **line)
{
	static t_gnl	*buff;
	t_gnl			*current;
	int				nbread;

	nbread = BUFF_SIZE;
	if (!line || fd < 0 || BUFF_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (-1);
	*line = NULL;
	if (!(current = ft_select_fd(&buff, fd)))
		return (-1);
	while (nbread >= BUFF_SIZE)
	{
		if (!(*(current->content)))
		{
			nbread = read(fd, current->content, BUFF_SIZE);
			ft_bzero(current->content + nbread, BUFF_SIZE - nbread);
			if (*line == NULL && nbread == 0)
				return (0);
		}
		if (ft_strchr(current->content, '\n'))
			nbread = 0;
		ft_fill_line(&*line, current->content);
	}
	return (1);
}
