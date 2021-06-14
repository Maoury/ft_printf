# ifndef PRINTF_H
# define PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
# define BASE "0123456789abcdef"
# define SPEC "cspdiuxX%"
# define FLAGS "-0.*"

typedef struct  s_flags{

    void        *args;
    int         minus;
    int         zero;
    int         width;
    int         precision;
}               t_flags;


int 	ft_putchar(char c);
int	    ft_putstr_fd(char *s, int fd);
void    ft_putnbr_base(int n, int base);
int		is_digit(char c);

// FIN LIBFT FONCTION
t_flags *ft_init_t_flags(void);
t_flags *get_flags(char *fmt, int *pos, va_list ap);
// FONCTION FOR FLAGS
//FONCTION POUR PARSE
int     ft_parse_min_zero(char *fmt, int *pos, t_flags *flag);
int     ft_parse_width(char *fmt, int *pos, va_list *ap, t_flags *flag);
int     ft_parse_precision_o_star(char *fmt, int *pos, va_list *ap, t_flags *flag);
int     ft_parse_arg_specifier(char *fmt, int *pos, va_list *ap, t_flags *flag);
// PRINTF FONCTION
/******* FONCTION PRINTF POUR THREAT LE SPECIFIER **********/
int     ft_verif_specifier(char c);
void    ft_int_threat(va_list *ap);
int     ft_pointer_threat(va_list *ap);
/******* FIN PRINTF POUR THREAT LE SPECIFIER **********/

int	    ft_threat_first(char specifier, va_list *ap);
int     ft_printf(const char *format, ...);
# endif