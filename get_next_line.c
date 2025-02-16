/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:59:08 by armtoros          #+#    #+#             */
/*   Updated: 2025/02/16 15:58:13 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*create_buff(int fd, ssize_t *tmp)
{
	char	*buff;

	buff = (char *)malloc(31);
	if (!buff)
		return (NULL);
	buff[30] = '\0';
	*tmp = read(fd, buff, 30);
	return (buff);
}

static void	merging(char *res, char *buff)
{
	res = ft_strjoin(res, buff);
	free(buff);
	buff = NULL;
}

static void	merging_in_else(char *buff, char *res, char *dest)
{
	char	*ult_temp;

	*dest = '\0';
	res = ft_strjoin(res, buff);
	if (dest + 1)
	{
		ult_temp = ft_strdup(dest + 1);
		free(buff);
		buff = ult_temp;
	}
}

char	*get_next_line(int fd)
{
	char				*res;
	static char			*buff;
	char				*dest;
	static ssize_t		tmp;
	int					flag;

	res = "";
	flag = 0;
	while (!flag)
	{
		if (!buff)
			create_buff(fd, &tmp);
		if (tmp == 30)
		{
			dest = ft_strchr(buff, '\n');
			if (!dest)
				merging(res, buff);
			else
			{
				flag = 1;
				merging_in_else(buff, res, dest);
			}
		}
		else if (tmp == 0)
			return (NULL);
		else
		{
			buff[tmp] = '\0';
			dest = ft_strchr(buff, '\n');
			if (!dest)
				merging(res, buff);
			else
				merging_in_else(buff, res, dest);
			flag = 1;
		}
	}
	return (ft_strdup(res));
}

int main()
{
	int i =0;
	int fd = open("text.txt", O_RDONLY);
	while (i++ < 11)
	{
		char *p = get_next_line(fd);
		write(1, p, ft_strlen(p));
		printf("\n");
	}
}