/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:36:03 by zatalbi           #+#    #+#             */
/*   Updated: 2024/12/19 14:07:34 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buf[BUFFER_SIZE + 1U];
	char		*str;
	char		*s;

	if (read(fd, buf, 0) == -1 && ft_memset_gnl(buf, 0, BUFFER_SIZE))
		return (NULL);
	str = NULL;
	s = ft_strchr(buf, '\n');
	if (*buf)
	{
		str = ft_strjoin_gnl(str, buf, 1);
		if (!str && ft_memset_gnl(buf, 0, BUFFER_SIZE))
			return (NULL);
	}
	while (!s && ft_memset_gnl(buf, 0, BUFFER_SIZE)
		&& read(fd, buf, BUFFER_SIZE) > 0)
	{
		str = ft_strjoin_gnl(str, buf, 1);
		if (!str && ft_memset_gnl(buf, 0, BUFFER_SIZE))
			return (NULL);
		s = ft_strchr(buf, '\n');
	}
	if ((s && *(s + 1)) || !ft_memset_gnl(buf, 0, BUFFER_SIZE))
		ft_strlcpy_gnl(buf, s + 1, BUFFER_SIZE + 1U, 0);
	return (str);
}
