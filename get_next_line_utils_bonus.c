/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycostode <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:57 by ycostode          #+#    #+#             */
/*   Updated: 2023/11/14 17:55:42 by ycostode         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	if (src_len < size)
	{
		while (i < src_len)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	else if (size != 0)
	{
		while (i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[size - 1] = '\0';
	}
	return (src_len);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t			*ptr;
	unsigned char	*ptr_last;

	ptr = (size_t *)s;
	while (n >= sizeof(size_t))
	{
		*ptr = 0;
		++ptr;
		n -= sizeof(size_t);
	}
	ptr_last = (unsigned char *)ptr;
	++n;
	while (--n)
	{
		*ptr_last = 0;
		++ptr_last;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	int				nb;

	if (nmemb * size > INT32_MAX || (nmemb > UINT16_MAX && size > UINT16_MAX))
		return (NULL);
	nb = nmemb * size;
	ptr = (unsigned char *)malloc(nb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nb);
	return (ptr);
}
