/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thendric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 11:48:42 by thendric          #+#    #+#             */
/*   Updated: 2017/01/13 14:38:41 by thendric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//WHOLE PROBLEM MAY LAY BEHIND NOT CLEARING OUT WHAT FLAGS ARE PRESENT AFTER SECOND RUN THROUGH OF ANOTHER VARIBALE!!!!!!!

#include "ft_printf.h"

int		ft_convers_id(t_input *input)
{
	int		flag;
	long	num;
	char	*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype(input);
	numstr = ft_itoa_base_long(num, 10);
	ft_checkflags(input, numstr);
	input->form = input->form + flag;
	return (0);
}

int		ft_convers_u(t_input *input)
{
	int		flag;
	unsigned long	num;
	char	*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype_u(input);
	numstr = ft_itoa_base_long(num, 10);
	//Problem exists above!
	ft_checkflags(input, numstr);
	input->form = input->form + flag;
	return (0);
}

int		ft_convers_f(t_input *input)
{
	input = NULL;
	return (0);
}

int		ft_convers_o(t_input *input)
{
	int		i;
	int		flag;
	long	num;
	char	*numstr;

	i = 0;
	flag = 1;
	flag += ft_getflags(input);
	num = (long)input->var;
	numstr = ft_itoa_base(num, 8);
	ft_checkflags(input, numstr);
	input->form += flag;
	return (0);
}

int		ft_convers_x(t_input *input)
{
	int		flag;
	long	num;
	char	*numstr;

	flag = 1;
	flag += ft_getflags(input);
	num = ft_vartype(input);
	numstr = ft_itoa_base_long(num, 16);
	ft_checkflags(input, numstr);
	input->form += flag;
	return (0);
}
