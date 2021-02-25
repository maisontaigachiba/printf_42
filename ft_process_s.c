/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:26:10 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/10 04:10:15 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_setstr(char *sp, t_info info)
{
	if (!sp)
	{
		if (info.dot)
			return (ft_strdup_spec("(null)", info.acc));
		else
			return (ft_strdup_spec("(null)", 6));
	}
	else if (info.acc > ft_strlen(sp))
		return (ft_strdup_spec(sp, ft_strlen(sp)));
	else
	{
		if (info.dot)
			return (ft_strdup_spec(sp, info.acc));
		else
			return (ft_strdup_spec(sp, ft_strlen(sp)));
	}
}

int			ft_putinfo_s(char *src, t_info info)
{
	int		len;

	if (!(src = ft_setstr(src, info)))
		return (-1);
	len = 0;
	if (info.width >= 0)
	{
		if (info.minus)
		{
			len += ft_putstr(src);
			while (len < info.width)
				len += (info.zero ? ft_putchar('0') : ft_putchar(' '));
		}
		else
		{
			while ((info.width || (!info.dot ||
				(info.acc && info.dot))) && len < info.width - ft_strlen(src))
				len += (info.zero ? ft_putchar('0') : ft_putchar(' '));
			len += ft_putstr(src);
		}
	}
	else
		len += ft_putstr(src);
	free(src);
	return (len);
}
