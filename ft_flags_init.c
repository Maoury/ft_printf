/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:09:30 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/14 16:02:10 by madiallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//fonction de traitement aui doit analyser tout les flags
int ft_ischarset(char c)
{
    int i;

    i = 0;
    while (SPEC[i])
    {
        if (SPEC[i] == c)
            return (1);
        i++;
    }
    return(0);
}
t_flags *ft_init_t_flags(void)
{
    t_flags *new_elem;

    new_elem = (t_flags *)malloc(sizeof(t_flags) + 1);
    if (!new_elem)
        return (NULL);
    new_elem->args = NULL;
    new_elem->minus = -1;
    new_elem->zero = -1;
    new_elem->width = -1;
    new_elem->precision = -1;
    return (new_elem); 
}
//il faut aue je get le moins ou le zero
//
t_flags *get_flags(char *fmt, int *pos, va_list ap)
{
    t_flags *flags;
    int     width;
    int     precision;

    precision = 0;
    width = 0;
    flags = ft_init_t_flags();
    if (fmt[*pos] == '-')
    {
        flags->minus = 1;
        *pos++;
    }
    if (fmt[*pos] == '0')
    {
        flags->zero = 1;
        *pos++;
    }
     if (fmt[*pos] >= '0' && fmt[*pos] <= '9')
    {
         width = width * 10 + fmt[*pos] - 48;
            *pos++;
        flags->width = width;
    }
    if (fmt[*pos] == '.')
    {
        *pos++;
        while (fmt[*pos] >= '0' && fmt [*pos] <= '9')
        {
            precision = precision * 10 + fmt[*pos] - 48;
            *pos++;
        }
        flags->precision = precision;
    }
    while(fmt[*pos])
    {
        if (ft_ischarset(fmt[*pos]))
            return(flags);
        *pos++;
    }
    return(NULL);
}
t_flags	*ft_get_flags(char *fmt, int *pos, va_list *ap)
{
	// while isflag
	// 	++(*fmt)
	//	-> opts->(is_flag()) = 1;
	//
	// 	width = ft_atoi(**fmt)
	// 	while isdigit
	// 		width = width * 10 + atoi(fmt)
	//
	// 	if '.'
	// 		if '*'
	// 		else
	//			while (ft_isdigit(i
	//
	t_flags	*args;
	
	args = ft_init_t_flags();
		if (!args)
			return (NULL);
	// le weroo et le moins sont en conflit permanent on peut soccuper de ca en mm temps	
	if (!ft_parse_min_zero(fmt, &pos, ap, args))
		return (ft_error_parse());
	//on verifie les etoiles pour la width
	if (!ft_parse_star_o_width(fmt, &pos, ap, args))
		return (ft_error_parse());
	//on verifie soit .* soit .numbers
	if (!ft_parse_precision_o_star(fmt, &pos, ap, args))
		return (ft_error_parse());
	if (!ft_parse_arg_specifier(fmt, &pos, ap, args))
		return (ft_error_parse());
	return (args);
}
