/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:42:48 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/09 19:43:43 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_setuint(unsigned int un, t_info info)
{
	char		*ret;
	char		*cnt;
	char		*tmp;
	int			len;
	int			i;

	if (info.dot && info.acc == 0 && un == 0)
		return (ft_strdup_spec("", 0));
	if (!info.dot || info.acc < ft_decimal(un))
		return (ft_uitoa(un));
	len = info.acc - ft_decimal(un);
	if (!(cnt = malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		cnt[i++] = '0';
	cnt[i] = '\0';
	tmp = ft_uitoa(un);
	ret = ft_strjoin(cnt, tmp);
	ft_allfree(&cnt, &tmp);
	return (ret);
}

int			ft_putinfo_width_ui(t_info info, char *num)
{
	int	len;
	int	dec;

	dec = ft_strlen(num);
	len = 0;
	if (info.zero && !info.dot)
	{
		while (len < info.width - dec)
			len += ft_putchar('0');
		len += ft_putstr(num);
	}
	else
	{
		len += (info.minus ? ft_putstr(num) : 0);
		while (len < (info.width - (info.minus ? 0 : dec)))
			len += ft_putchar(' ');
		len += (info.minus ? 0 : ft_putstr(num));
	}
	return (len);
}

int			ft_putinfo_u(unsigned int un, t_info info)
{
	int		len;
	char	*num;

	if (!(num = ft_setuint(un, info)))
		return (-1);
	len = 0;
	if (info.width >= 0)
		len += ft_putinfo_width_ui(info, num);
	else
		len += ft_putstr(num);
	free(num);
	return (len);
}
