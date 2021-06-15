#include "ft_printf.h"
//LIBFT FONCTION
int	ft_putchar (char c)
{
	static int bytes = 0;
	write(1, &c, 1);
	bytes++;
	return (bytes);
}
void    ft_putnbr_base(int n, int base)
{
   // long    nb;
	
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;   
	}
	if(n >= base)
	{
		ft_putnbr_base(n / base, base);
		ft_putnbr_base(n % base, base);
	}
	else
		ft_putchar(BASE[n]);
}

// FIN LIBFT FONCTION
// PRINTF FONCTION
/******* FONCTION PRINTF POUR THREAT LE SPECIFIER **********/

int ft_printf(const char *fmt, ...)
 {
	va_list	*ap;
	int		bytes;
	int		pos;
	t_flags	*flag;
	pos = -1;
	va_start(*ap, fmt);
	while (fmt[++pos])
	{
		if (fmt[pos] == '%' && fmt[pos++])
			{
				flag = ft_init_t_flags();
				ft_parse_min_zero((char *)fmt, &pos, flag);
				ft_parse_width((char *)fmt, &pos, flag);
				ft_parse_precision_o_star((char *)fmt, &pos, ap, flag);
				ft_parse_arg_specifier((char *)fmt, &pos, ap, flag);
			}
			//fonction qui doit recupÃ©rer la lettre ft_recup_specifier(char *spec, va_list *arg)
		 // tant que l'on a pas un vrai flag on continue
	}
	 va_end(*ap);
	 return(ft_putchar('\0') - 1);
 }
 /*
 int main()
 {
	// printf("%%");
	 int a = 5;
	 int b = 8;
	 int c = 15;
	 int d = 1564;
  //   ft_printf("mien : %p comment va chakal %d \n tu dis quoi %d du %d\n", &a, b, c, d);
   //  printf("vrai : %p comment va chakal %d \n tu dis quoi %d du %d\n", &a, b, c, d);
	  //printf("retour : %d", ft_putnbr_base(255, 10));
	//ft_putnbr_base(255, 10);
 }
******/