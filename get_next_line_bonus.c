/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:55:27 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/14 17:55:43 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*str;
	unsigned char	st;

	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	st = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == st)
			return ((char *)&str[i]);
		i++;
	}
	if (st == 0)
		return ((char *)&str[i]);
	return (NULL);
}

static char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*str;
	int		i;
	int		l;

	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	l = ft_strlen(s1);
	if (s1)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[i - l] && i - l < n)
	{
		str[i] = s2[i - l];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_join(char *buff, char **s)
{
	char	*ref;

	if (buff[0] == '\0')
	{
		*s = NULL;
		return ;
	}
	ref = ft_strchr(buff, '\n');
	if (ref)
	{
		*s = ft_strnjoin(*s, buff, ref - buff + 1);
		ft_strlcpy(buff, ref + 1, BUFFER_SIZE);
	}
	else
		*s = ft_strnjoin(*s, buff, BUFFER_SIZE);
}

static char	*ft_get_line(int fd)
{
	static char	buff[FD_MAX][BUFFER_SIZE + 1];
	int			bytes;
	char		*s;

	bytes = 1;
	s = NULL;
	ft_join(buff[fd], &s);
	while (bytes > 0 && !ft_strchr(s, '\n'))
	{
		bytes = read(fd, buff[fd], BUFFER_SIZE);
		if (bytes < BUFFER_SIZE)
			buff[fd][bytes] = '\0';
		if (bytes > 0)
			ft_join(buff[fd], &s);
	}
	if (s && s[0] == '\0')
		free(s);
	return (s);
}

char	*get_next_line(int fd)
{
	char	*s;

	if (fd < 0 || fd > FD_MAX)
		return (NULL);
	s = ft_get_line(fd);
	return (s);
}
