/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiallo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:09:30 by madiallo          #+#    #+#             */
/*   Updated: 2021/06/15 18:24:37 by madiallo         ###   ########.fr       */
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
            return (i);
        i++;
    }
    return(-1);
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