/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threat_characters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:08:33 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/14 17:12:46 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
        *pos++;
    }
    if (flag->minus == 1 || flag->zero == 1)
        return(1);
    return (-1);
}
int     ft_parse_width(char *fmt, int *pos, va_list *ap, t_flags *flag)
{
    if (fmt[*pos] >= '0' && fmt[*pos] >= '9')
        flag->width = 0;
    while (fmt[*pos]  >= '0' && fmt[*pos] <= '9')
        {
            flag->width = flag->width * 10 + (fmt[*pos] - 48);
            *pos++;
        }
        return(1);
}
int     ft_parse_precision_o_star(char *fmt, int *pos, va_list *ap, t_flags *flag)
{
    
    if (fmt[*pos] == '.')
    {
        flag->precision = 0;
        *pos++;
        if (fmt[*pos] == '*')
        {
            flag->precision = va_arg(*ap, int);
            return (1);
        }
        while (fmt[*pos]  >= '0' && fmt[*pos] <= '9')
        {
            flag->precision = flag->precision * 10 + (fmt[*pos] - 48);
            *pos++;
        }
        return (1);
    }
    return (-1);
}
int     ft_parse_arg_specifier(char *fmt, int *pos, va_list *ap, t_flags *flag);
int main()
 {
     int a = 5;
     int b = 8;
     int c = 15;
     int d = 1564;
    // ft_printf("mien : %p comment va chakal %d \n tu dis quoi %d du %d\n", &a, b, c, d);
    printf("vrai :  comment va chakal%.s\n tu dis quoi du \n", "sunshine");
    
 }