/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:06:31 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/14 17:59:51 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define FD_MAX 1024

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
