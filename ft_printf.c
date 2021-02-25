/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:27:56 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/10 05:07:06 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_process(const char **fmtp, va_list ap)
{
	int		ret;
	t_info	info;

	if (!(ft_infoprocess(fmtp, &info, ap)))
		return (-1);
	if (**fmtp == '%')
		ret = ft_putinfo_c('%', info);
	if (**fmtp == 'c')
		ret = ft_putinfo_c(va_arg(ap, int), info);
	if (**fmtp == 's')
		ret = ft_putinfo_s(va_arg(ap, char *), info);
	if (**fmtp == 'p')
		ret = ft_putinfo_p(va_arg(ap, void *), info);
	if (**fmtp == 'd' || **fmtp == 'i')
		ret = ft_putinfo_d(va_arg(ap, int), info);
	if (**fmtp == 'u')
		ret = ft_putinfo_u(va_arg(ap, unsigned int), info);
	if (**fmtp == 'x' || **fmtp == 'X')
		ret = ft_putinfo_x(va_arg(ap, unsigned int), **fmtp - 23, info);
	return (ret);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;
	int			tmp;

	va_start(ap, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if ((tmp = ft_process(&fmt, ap)) == -1)
				return (-1);
			len += tmp;
		}
		else
			len += (write(1, fmt, 1));
		fmt++;
	}
	va_end(ap);
	return (len);
}
