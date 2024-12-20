/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:45:51 by zatalbi           #+#    #+#             */
/*   Updated: 2024/12/19 14:08:23 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	v;

	v = 0;
	while (s[v] != '\0')
	{
		if (s[v] == (char)c)
			return ((char *)(s + v));
		v++;
	}
	if ((char)c == '\0')
		return ((char *)(s + v));
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buf[FD_SIZE][BUFFER_SIZE + 1U];
	char		*str;
	char		*s;

	if (fd < 0 || fd >= FD_SIZE || (read(fd, buf[fd], 0) == -1
			&& ft_memset_gnl(buf[fd], 0, BUFFER_SIZE, 0)))
		return (NULL);
	s = ft_strchr(buf[fd], '\n');
	if (ft_memset_gnl(&str, 0, sizeof(str), 1) && *buf[fd])
	{
		str = ft_strjoin_gnl(str, buf[fd], 1);
		if (!str && ft_memset_gnl(buf[fd], 0, BUFFER_SIZE, 0))
			return (NULL);
	}
	while (!s && ft_memset_gnl(buf[fd], 0, BUFFER_SIZE, 0)
		&& read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_gnl(str, buf[fd], 1);
		if (!str && ft_memset_gnl(buf[fd], 0, BUFFER_SIZE, 0))
			return (NULL);
		s = ft_strchr(buf[fd], '\n');
	}
	if ((s && *(s + 1)) || !ft_memset_gnl(buf[fd], 0, BUFFER_SIZE, 0))
		ft_strlcpy_gnl(buf[fd], s + 1, BUFFER_SIZE + 1U, 0);
	return (str);
}
