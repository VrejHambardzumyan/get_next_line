/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:59:08 by armtoros          #+#    #+#             */
/*   Updated: 2025/02/16 14:25:58 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}
static char		*create_buff(int fd, ssize_t *temp)
{
	
}
char	*get_next_line(int fd)
{
	char				*res;
	static char			*buff;
	char				*dest;
	static ssize_t		tmp;
	int					flag;
	int					currl;
	char				*ult_temp;

	res = "";
	flag = 0;
	currl = 0;
	while (!flag)
	{
		if (!buff)
		{
			buff = (char *)malloc(31);
			if (!buff)
				return (NULL);
			buff[30] = '\0';
			tmp = read(fd, buff, 30);
		}
		if (tmp == 30)
		{
			dest = ft_strchr(buff, '\n');	
			if (!dest)
			{
				res = ft_strjoin(res, buff);
				free(buff);
				buff = NULL;
			}
			else
			{
				flag = 1;
				*dest = '\0';
				res = ft_strjoin(res, buff);
				if (dest + 1)
				{
					ult_temp = ft_strdup(dest + 1);
					free(buff);
					buff = ult_temp;
				}	
			}
		}
		else
		{	
			buff[tmp] = '\0';
			dest = ft_strchr(buff, '\n');
			if (!dest)
			{
				res = ft_strjoin(res, buff);
				free(buff);
				buff = NULL;
			}
			else
			{
				*dest = '\0';
				res = ft_strjoin(res, buff);
				if (dest + 1)
				{
					ult_temp = ft_strdup(dest + 1);	
					free(buff);
					buff = ult_temp;
				}	
			}
				flag = 1;
		}
	}
	return (ft_strdup(res));
}

int main()
{
	int i =0;
	int fd = open("text.txt", O_RDONLY);
	while (i++ < 10)
	{
		char *p = get_next_line(fd);
		write(1, p, ft_strlen(p));
		printf("\n");
	}
}