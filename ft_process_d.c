/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:28:33 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/10 05:00:56 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_decimal(unsigned int n)
{
	int	dec;

	dec = 1;
	while (n >= 10)
	{
		dec++;
		n /= 10;
	}
	return (dec);
}

char		*ft_uitoa(unsigned int n)
{
	char		*dst;
	size_t		len;
	int			i;

	len = ft_decimal(n);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	i = len - 1;
	while (i >= 0)
	{
		dst[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	dst[len] = '\0';
	return (dst);
}

char		*ft_setnum(int n, t_info ti)
{
	char	*cnt;
	char	*tmp;
	char	*ret;
	int		len;
	int		i;

	if (ti.dot && ti.acc == 0 && n == 0)
		return (ft_strdup_spec("", 1));
	if (!ti.dot || ti.acc < (n < 0 ? ft_decimal(-n) + 1 : ft_decimal(n)))
		return (ft_itoa(n));
	len = (n < 0 ? ti.acc - ft_decimal(-n) + 1 : ti.acc - ft_decimal(n));
	cnt = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		if (i == 0 && n < 0)
			cnt[i++] = '-';
		else
			cnt[i++] = '0';
	}
	cnt[i] = '\0';
	tmp = (n < 0 ? ft_uitoa(-n) : ft_uitoa(n));
	ret = ft_strjoin(cnt, tmp);
	ft_allfree(&cnt, &tmp);
	return (ret);
}

int			ft_putinfo_width_d(int n, t_info info, char *num)
{
	int	len;
	int	dec;

	dec = ft_strlen(num);
	len = 0;
	if (info.zero && !info.dot)
	{
		len += (n < 0 ? ft_putchar(*num) : 0);
		while (len < info.width - dec + (n < 0 ? 1 : 0))
			len += ft_putchar('0');
		len += ft_putstr(num + (n < 0 ? 1 : 0));
	}
	else
	{
		if (info.minus)
			len += ft_putstr(num);
		while (len < (info.minus ? info.width : info.width - dec))
			len += ft_putchar(' ');
		if (!info.minus)
			len += ft_putstr(num);
	}
	return (len);
}

int			ft_putinfo_d(int n, t_info info)
{
	int		len;
	char	*num;

	if (!(num = ft_setnum(n, info)))
		return (-1);
	len = 0;
	if (info.width >= 0)
		len += ft_putinfo_width_d(n, info, num);
	else
		len += ft_putstr(num);
	free(num);
	return (len);
}
