/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:16:32 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/09 19:17:43 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putinfo_c(char c, t_info info)
{
	int	len;
	int wid;
	int flg;

	if (info.width == INT_MAX)
		return (-1);
	if (info.zero == true)
		wid = '0';
	else if (info.zero == false)
		wid = ' ';
	len = 0;
	flg = 0;
	if (info.minus == true)
	{
		len += ft_putchar(c);
		while (len < info.width)
			len += ft_putchar(wid);
	}
	else
		while (len < info.width - 1)
			len += ft_putchar(wid);
	if (info.minus == false)
		len += ft_putchar(c);
	return (len);
}
