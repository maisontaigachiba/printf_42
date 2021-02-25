/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:47:08 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/09 19:47:47 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup_spec(const char *src, int n)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int			ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int			ft_putstr(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (str && *str)
		while (str[i])
		{
			len += (write(1, &str[i], 1));
			i++;
		}
	return (len);
}

int			ft_putchar(char c)
{
	return (write(1, &c, 1));
}
