/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:06:53 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/09 20:07:34 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_setbase(unsigned int un, unsigned int base)
{
	int num;

	num = 1;
	while (un >= base)
	{
		num++;
		un /= base;
	}
	return (num);
}

char		*ft_hextoa(unsigned int un, char c)
{
	int		i;
	int		len;
	char	*dst;

	len = ft_setbase(un, 16);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		if ((un % 16) < 10)
			dst[i] = un % 16 + '0';
		else
			dst[i] = un % 16 + (c - 10);
		un /= 16;
		i--;
	}
	dst[len] = '\0';
	return (dst);
}

char		*ft_sethex(unsigned int un, char c, t_info info)
{
	int		i;
	int		len;
	char	*ret;
	char	*cnt;
	char	*tmp;

	if (info.dot && info.acc == 0 && un == 0)
		return (ft_strdup_spec("", 0));
	len = info.acc - ft_setbase(un, 16);
	if (len < 0)
		len = 0;
	if (!(cnt = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		cnt[i++] = '0';
	cnt[i] = '\0';
	tmp = ft_hextoa(un, c);
	ret = ft_strjoin(cnt, tmp);
	ft_allfree(&cnt, &tmp);
	return (ret);
}

int			ft_putinfo_width_x(char *num, t_info info)
{
	int len;
	int i;

	i = ft_strlen(num);
	len = 0;
	if (info.zero && !info.dot)
	{
		while (len < info.width - i)
			len += ft_putchar('0');
		len += ft_putstr(num);
	}
	else
	{
		if (info.minus)
			len += ft_putstr(num);
		while (len < (info.minus ? info.width : info.width - i))
			len += ft_putchar(' ');
		if (!info.minus)
			len += ft_putstr(num);
	}
	return (len);
}

int			ft_putinfo_x(unsigned int un, char c, t_info info)
{
	int		len;
	char	*num;

	if (!(num = ft_sethex(un, c, info)))
		return (-1);
	len = 0;
	if (info.width >= 0)
		len += ft_putinfo_width_x(num, info);
	else
		len += ft_putstr(num);
	free(num);
	return (len);
}
