/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zatalbi <zatalbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:46:05 by zatalbi           #+#    #+#             */
/*   Updated: 2024/12/18 22:17:08 by zatalbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE_MAX 2147483647
# define FD_SIZE 10240

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if (BUFFER_SIZE < 0 || BUFFER_SIZE > BUFFER_SIZE_MAX)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s, int endl);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize, int endl);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t dstsize, int endl);
char	*ft_strjoin_gnl(char *s1, char *s2, int endl);
void	*ft_memset_gnl(void *s, int c, size_t len, int p);

#endif