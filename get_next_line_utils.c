/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:44:10 by armtoros          #+#    #+#             */
/*   Updated: 2025/02/16 14:19:22 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	l;
	size_t	i;

	len = 0;
	i = 0;
	if ((!dst || !src) && !dstsize)
		return (0);
	while (dst[len] != '\0' && len < dstsize)
		len++;
	l = ft_strlen(src);
	if (len < dstsize)
	{
		while (src[i] != '\0' && (len + i) < dstsize - 1)
		{
			dst[len + i] = src[i];
			i++;
		}
		dst[len + i] = '\0';
	}
	return (l + len);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	res = (char *) s;
	i = 0;
	if (c % 256 == 0)
		return (ft_strlen(res) + res);
	while (res[i])
	{
		if (res[i] == c % 256)
			return (&res[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s1);
	res = (char *) malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(len);
	if (res)
	{
		ft_strlcpy(res, s1, len);
		ft_strlcat(res, s2, len);
	}
	return (res);
}
