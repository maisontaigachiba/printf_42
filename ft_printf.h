/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchiba <tchiba@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:37:12 by tchiba            #+#    #+#             */
/*   Updated: 2021/01/10 04:24:04 by tchiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct	s_info
{
	bool		zero;
	bool		minus;
	bool		dot;
	int			width;
	int			acc;
}				t_info;

bool			ft_infoprocess(const char **fmtp, t_info *info, va_list ap);
void			ft_allfree(char **s1, char **s2);
void			ft_checkflag(const char **fmtp, t_info *info);
void			ft_checkwidth(const char **fmtp, t_info *info, va_list ap);
void			ft_checkaccracy(const char **fmtp, t_info *info, va_list ap);
int				ft_checkformat(const char *s);
int				ft_setbase(unsigned int un, unsigned int base);
int				ft_addlen(unsigned long ul, t_info info);
int				ft_printf(const char *fmt, ...);
int				ft_process(const char **fmtp, va_list ap);
int				ft_atoi(const char *str);
int				ft_putinfo_c(char c, t_info info);
int				ft_putinfo_d(int n, t_info info);
int				ft_putinfo_width_d(int n, t_info info, char *num);
int				ft_putinfo_s(char *src, t_info info);
int				ft_putinfo_u(unsigned int un, t_info info);
int				ft_putinfo_width_ui(t_info info, char *num);
int				ft_putinfo_x(unsigned int un, char c, t_info info);
int				ft_putinfo_width_x(char *num, t_info info);
int				ft_putinfo_p(void *p, t_info info);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_cntlen_p(int i, t_info info, char *num);
int				ft_strchr(char *s, char c);
int				ft_decimal(unsigned int n);
char			*ft_setnum(int n, t_info ti);
char			*ft_hextoa(unsigned int un, char c);
char			*ft_sethex(unsigned int un, char c, t_info info);
char			*ft_adtoa(unsigned long ul, t_info info);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_uitoa(unsigned int n);
char			*ft_itoa(int n);
char			*ft_setuint(unsigned int un, t_info info);
char			*ft_gethex(int len, char *dst, unsigned long ul);
char			*ft_strdup_spec(const char *src, int n);
char			*ft_setstr(char *sp, t_info info);

#endif
