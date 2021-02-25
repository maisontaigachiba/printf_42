/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:18:34 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/10 04:02:27 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_checkflag(const char **fmtp, t_info *info)
{
	info->minus = false;
	info->zero = false;
	while (**fmtp == '-' || **fmtp == '0')
	{
		if (**fmtp == '-')
		{
			info->minus = true;
			info->zero = false;
		}
		if (**fmtp == '0' && !info->minus)
			info->zero = true;
		(*fmtp)++;
	}
}

void		ft_checkwidth(const char **fmtp, t_info *info, va_list ap)
{
	int ast;

	info->width = 0;
	if (**fmtp == '*')
	{
		ast = va_arg(ap, int);
		if (ast < 0)
		{
			if (!info->minus)
			{
				info->minus = true;
				info->zero = false;
			}
			info->width = -1 * ast;
		}
		else
			info->width = ast;
		(*fmtp)++;
	}
	else if (**fmtp >= '0' && **fmtp <= '9')
	{
		info->width = ft_atoi(*fmtp);
		while (**fmtp >= '0' && **fmtp <= '9')
			(*fmtp)++;
	}
}

void		ft_checkaccracy(const char **fmtp, t_info *info, va_list ap)
{
	int	ast;

	info->acc = 0;
	info->dot = false;
	if (**fmtp == '.')
	{
		info->dot = true;
		(*fmtp)++;
		if (**fmtp == '*' && (*fmtp)++)
		{
			if ((ast = va_arg(ap, int)) < 0)
			{
				info->dot = false;
				info->acc = 0;
			}
			else
				info->acc = ast;
		}
		else if (**fmtp >= '0' && **fmtp <= '9')
		{
			info->acc = ft_atoi(*fmtp);
			while (**fmtp >= '0' && **fmtp <= '9')
				(*fmtp)++;
		}
	}
}

int			ft_checkformat(const char *s)
{
	while (*s == '-' || *s == '0')
		s++;
	if (*s == '*')
		s++;
	else
	{
		while (*s >= '0' && *s <= '9')
			s++;
	}
	if (*s == '.')
	{
		s++;
		if (*s == '*')
			s++;
		else
		{
			while (*s >= '0' && *s <= '9')
				s++;
		}
	}
	return ((ft_strchr("%cspdiuxX", *s)));
}

bool		ft_infoprocess(const char **fmtp, t_info *info, va_list ap)
{
	(*fmtp)++;
	if (!ft_checkformat(*fmtp))
		return (false);
	ft_checkflag(fmtp, info);
	ft_checkwidth(fmtp, info, ap);
	ft_checkaccracy(fmtp, info, ap);
	return (true);
}
