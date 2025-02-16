/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:44:10 by armtoros          #+#    #+#             */
/*   Updated: 2025/02/16 15:51:54 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (dstsize == 0)
	{
		while (src[len] != '\0')
			len++;
		return (len);
	}
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	l;
	size_t	i;

	l = 0;
	len = 0;
	i = 0;
	if ((!dst || !src) && !dstsize)
		return (0);
	while (dst[len] != '\0' && len < dstsize)
		len++;
	while (src[l] != '\0')
		l++;
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
	{
		while (s[i] != '\0')
			i++;
		return (i + res);
	}
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

	len = 0;
	while (s1[len] != '\0')
		len++;
	res = (char *) malloc(len + 1);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len1 = 0;
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	len = len1 + len2 + 1;
	res = (char *)malloc(len);
	if (res)
	{
		ft_strlcpy(res, s1, len);
		ft_strlcat(res, s2, len);
	}
	return (res);
}
