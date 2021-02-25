/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:27:41 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/10 04:16:13 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

void		ft_allfree(char **s1, char **s2)
{
	if (s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2)
	{
		free(*s2);
		*s2 = NULL;
	}
}

char		*ft_itoa(int n)
{
	char			*dst;
	unsigned int	un;
	int				len;
	int				i;

	un = (n < 0 ? -n : n);
	len = (n < 0 ? ft_decimal(un) + 1 : ft_decimal(un));
	if (!(dst = malloc(len + 1)))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		if (i == 0 && n < 0)
			dst[i] = '-';
		else
		{
			dst[i] = un % 10 + '0';
			un /= 10;
		}
		i--;
	}
	dst[len] = '\0';
	return (dst);
}

int			ft_atoi(const char *str)
{
	int				i;
	int				sign_cnt;
	long long		num;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign_cnt = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign_cnt *= -1;
		i++;
	}
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i++] - '0';
		if (sign_cnt == -1 && num > 2147483648)
			return (0);
		if (sign_cnt == 1 && num > 2147483647)
			return (-1);
	}
	num *= sign_cnt;
	return ((int)num);
}
