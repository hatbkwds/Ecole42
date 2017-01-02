#include "ft_printf.h"

int 	ft_convers_percent(t_input *input)
{
	int flag;

	flag = 1;
	flag += ft_getflags(input);
	ft_add_width(input, 1, "%");
	input->form = input->form + flag;
	return (0);
}

int 	ft_convers_c(t_input *input)
{
	int flag;
	char 	*c;

	flag = 1;
	c = ft_strnew(2);
	c[0] = va_arg(input->ap, int);
	c[1] = '\0';
	flag += ft_getflags(input);
	ft_add_width(input, 1, c);
	input->form += flag;
	return (0);
}

int 	ft_convers_s(t_input *input)
{
	int flag;
	char *str;

	flag = 1;
	str = va_arg(input->ap, char *);
	flag += ft_getflags(input);
	ft_add_width(input, ft_strlen(str), str);
	input->form += flag;
	return (0);
}

int 	ft_convers_p(t_input *input)
{
	int flag;
	int num;
	char *numstr;

	flag = 1;
	num = va_arg(input->ap, int);
	numstr = ft_itoa_base(num, 16);
	flag += ft_getflags(input);
	numstr = ft_strjoin("0x10", numstr);
	ft_add_width(input, ft_strlen(numstr), numstr);
	input->form += flag;
	return(0);
}