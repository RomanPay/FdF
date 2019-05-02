/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofrost-g <ofrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:49:03 by ofrost-g          #+#    #+#             */
/*   Updated: 2019/05/02 17:27:18 by ofrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		readfile(int fd, char **s1, char **line)
{
	int		rd;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*str;

	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (!s1[fd])
			s1[fd] = ft_strdup(buf);
		else
		{
			tmp = s1[fd];
			s1[fd] = ft_strjoin(s1[fd], buf);
			ft_strdel(&tmp);
		}
		if ((str = ft_strchr(s1[fd], '\n')))
		{
			*line = ft_strsub(s1[fd], 0, (str - s1[fd]));
			s1[fd] = ft_strcpy(s1[fd], (str + 1));
			return (1);
		}
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*str;
	static char	*s1[BUFF_FD];

	if (fd == -1 || BUFF_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	if ((readfile(fd, s1, line)) == 1)
		return (1);
	if (s1[fd] != NULL && s1[fd][0] != '\0')
	{
		if ((str = ft_strchr(s1[fd], '\n')))
		{
			*line = ft_strsub(s1[fd], 0, (str - (s1[fd])));
			s1[fd] = ft_strcpy(s1[fd], str + 1);
			return (1);
		}
		else
		{
			*line = ft_strdup(s1[fd]);
			ft_strdel(&s1[fd]);
			return (1);
		}
	}
	return (0);
}
