/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:46:55 by thendric          #+#    #+#             */
/*   Updated: 2017/01/02 11:47:28 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include "libft.h"

typedef struct 	s_read
{
	va_list		ap;
	void		*var;
	char		*form;
	char		*str;
	char		*flags;
	char		c;
	long long	size;
	int 		width;
	int 		negative;
	int 		precision;
	int 		flagplus;
	int 		flagpound;
	int 		flagspace;
	int 		flagminus;
	int 		flagzero;
}				t_input;

/*
** Declare digit functions
*/
int 	ft_convers_id(t_input *input);
int 	ft_convers_uUD(t_input *input);
int 	ft_convers_f(t_input *input);
int 	ft_convers_oO(t_input *input);
int 	ft_convers_xX(t_input *input);
/*
** Declare digit negative functions
*/
char	*ft_deletenegative(t_input *input, char *str);
char	*ft_addnegative(t_input *input, char *str);
/*
** Declare char functions
*/
int 	ft_convers_percent(t_input *input);
int 	ft_convers_c(t_input *input);
int 	ft_convers_s(t_input *input);
int 	ft_convers_p(t_input *input);
/*
** Declare flag operation functions
*/
char	*ft_flagspace(char *str);
char	*ft_flagpound(t_input *input, char *str);
char	*ft_flagplus(char *str);
char	*ft_flagwidth(t_input *input, char *str, int left);
/*
** Declare universal helper functions
*/
int 	ft_isconversion(char c);
int		ft_isflag(char c);
char	ft_getconversion(char *str);
long	ft_vartype(t_input *input);
/*
** Declare functionality functions
*/
char    *ft_checkprecision(t_input *input, char *str);
void	ft_add_width(t_input *input, size_t var_size, char *str);
void	ft_checkflags(t_input *input, char *str);
int		ft_getflags(t_input *input);
int 	ft_init(t_input *input);
int		ft_printf(const char *format, ...);

#endif
