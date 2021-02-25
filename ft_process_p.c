/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:02:39 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/10 05:06:50 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_addlen(unsigned long ul, t_info info)
{
	int len;

	len = 1;
	while (ul >= 16)
	{
		ul /= 16;
		len++;
	}
	if (info.dot)
		if (info.acc > len)
			len = info.acc;
	return (len + 2);
}

char	*ft_gethex(int len, char *dst, unsigned long ul)
{
	int i;

	i = len - 1;
	while (i >= 0)
	{
		if (i == 0)
			dst[i] = '0';
		else if (i == 1)
			dst[i] = 'x';
		else
		{
			if ((ul % 16) < 10)
				dst[i] = ul % 16 + '0';
			else
				dst[i] = ul % 16 - 10 + 'a';
			ul /= 16;
		}
		i--;
	}
	dst[len] = '\0';
	return (dst);
}

char	*ft_adtoa(unsigned long ul, t_info info)
{
	int		len;
	char	*dst;

	len = ft_addlen(ul, info);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	dst = ft_gethex(len, dst, ul);
	return (dst);
}

int		ft_cntlen_p(int i, t_info info, char *num)
{
	int len;

	len = 0;
	if (info.width >= 0)
	{
		if (info.minus)
			len += ft_putstr(num);
		while (len < (info.minus ? info.width : info.width - i))
			len += ft_putchar(' ');
		if (!info.minus)
			len += ft_putstr(num);
	}
	else
		len += ft_putstr(num);
	return (len);
}

int		ft_putinfo_p(void *p, t_info info)
{
	int		i;
	int		len;
	char	*num;

	if (!p && info.dot && info.acc == 0)
	{
		if (!(num = ft_strdup_spec("0x", 2)))
			return (-1);
	}
	else if (!(num = ft_adtoa((unsigned long)p, info)))
		return (-1);
	i = ft_strlen(num);
	len = ft_cntlen_p(i, info, num);
	free(num);
	return (len);
}
