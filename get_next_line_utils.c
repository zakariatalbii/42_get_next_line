/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:28:08 by zatalbi           #+#    #+#             */
/*   Updated: 2024/12/18 18:58:28 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s, int endl)
{
	size_t	v;

	v = 0;
	while (s && s[v])
	{
		if (s[v++] == '\n' && endl)
			break ;
	}
	return (v);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize, int endl)
{
	size_t	v;
	size_t	srclen;

	srclen = ft_strlen_gnl(src, endl);
	if (dstsize == 0)
		return (srclen);
	v = 0;
	while (v < dstsize - 1 && src[v])
	{
		dst[v] = src[v];
		v++;
	}
	while (v < dstsize && dst[v])
		dst[v++] = '\0';
	return (srclen);
}

size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize, int endl)
{
	size_t	v;
	size_t	y;
	size_t	dstlen;
	size_t	srclen;
	size_t	size;

	srclen = ft_strlen_gnl(src, endl);
	if (dstsize == 0)
		return (srclen);
	dstlen = ft_strlen_gnl(dst, endl);
	size = dstsize - dstlen;
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	v = dstlen;
	y = 0;
	while (y < size - 1 && src[y])
		dst[v++] = src[y++];
	dst[v] = '\0';
	return (dstlen + srclen);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int endl)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen_gnl(s1, endl) + ft_strlen_gnl(s2, endl);
	str = (char *)malloc(len + 1);
	if (!str)
		return (free(s1), NULL);
	if (s1)
		ft_strlcpy_gnl(str, s1, len + 1, endl);
	if (!s1 && s2)
		ft_strlcpy_gnl(str, s2, len + 1, endl);
	else if (s1 && s2)
		ft_strlcat_gnl(str, s2, len + 1, endl);
	free(s1);
	return (str);
}

void	*ft_memset_gnl(void *s, int c, size_t len)
{
	size_t	v;

	v = 0;
	while (s && v < len && ((unsigned char *)s)[v] != (unsigned char)c)
		((unsigned char *)s)[v++] = (unsigned char)c;
	return (s);
}
