/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threat_characters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:08:33 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/15 18:23:56 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	is_digit(char c)
{
	return(c >= '0' && c <= '9');
}
static void     ft_function_tab((*tab[9])(va_list *ap, t_flags *flag))
{
    tab[0] = ft_threat_char;
    tab[1] = ft_threat_string;
    tab[2] = ft_threat_pointer;
    tab[3] = ft_threat_int;
    tab[4] = ft_threat_int;
    tab[5] = ft_threat_unsigned;
    tab[6] = ft_threat_hex_low;
    tab[7] = ft_threat_hex_up;
    tab[8] = ft_threat_percent;
}
int     ft_parse_min_zero(char *fmt, int *pos, t_flags *flag)
{
    while ((fmt[*pos] == '0' || fmt[*pos] == '-'))
    {
        if(flag->minus != 1 && fmt[*pos] == '0')
            flag->zero = 1;
        else
            flag->zero = 0;
        // on doit print que 00 est mauvais quand il y un moins
        if (fmt[*pos] == '-')
            flag->minus = 1;
        (*pos)++;
    }
    if (flag->minus == 1 || flag->zero == 1)
        return(1);
    return (-1);
}
int     ft_parse_width(char *fmt, int *pos, t_flags *flag)
{
    if (is_digit(fmt[*pos]))
        flag->width = 0;
    while (is_digit(fmt[*pos]))
        {
            flag->width = flag->width * 10 + (fmt[*pos] - 48);
            (*pos)++;
        }
        return(1);
}
int     ft_parse_precision_o_star(char *fmt, int *pos, va_list *ap, t_flags *flag)
{
    
    if (fmt[*pos] == '.')
    {
        flag->precision = 0;
        (*pos)++;
        if (fmt[*pos] == '*')
        {
            flag->precision = va_arg(*ap, int);
            return (1);
        }
        while (is_digit(fmt[*pos]))
        {
            flag->precision = flag->precision * 10 + (fmt[*pos] - 48);
            (*pos)++;
        }
        return (1);
    }
    return (-1);
}
int     ft_parse_arg_specifier(char *fmt, int *pos, va_list *ap, t_flags *flag)
{
    int (*tab[8])(va_list *ap, t_flags *flag);

    ft_function_tab(tab);
    if (ft_ischarset(fmt[*pos]) != -1)
    {
       return (tab[ft_ischarset(fmt[*pos])]);
    }
    return (-1);
}

int main()
 {
     int a = 5;
     int b = 8;
     int c = 15;
     int d = 1564;
    // ft_printf("mien : %p comment va chakal %d \n tu dis quoi %d du %d\n", &a, b, c, d);
    printf("vrai :  comment va chakal%50%\n tu dis quoi du \n", 9);
    
 }