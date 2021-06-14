#include "ft_printf.h"
//LIBFT FONCTION
int	ft_putchar (char c)
{
	static int bytes = 0;
	write(1, &c, 1);
	bytes++;
	return (bytes);
}

void	ft_strlen_base(unsigned long long nb, int base)
{
	int i;
	
	i = 1;
	while ((unsigned long long)base <= nb)
	{
		nb /= base;
		i++;
	}
	return (i);
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
int	ft_verif_specifier(char c)
{
	//on doit verifier que la lettre appartiennent bien a un specifier de la liste
	// cspdiuuxX%
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' ||c == '%');
}
void	ft_int_threat(va_list *ap)
{	
	int nb;

	nb = va_arg(*ap, int);
	ft_putnbr_base(nb, 10);
}

/*int     ft_pointer_threat(va_list *ap)
{
	int bytes;

	bytes = 0;
	//zebi = va_arg(*ap, unsigned long long);
	bytes += ft_putnbr_fd(va_arg(*ap, unsigned long long), 16);
}*/
/******* FIN PRINTF POUR THREAT LE SPECIFIER **********/

int	ft_threat_first(char specifier, va_list *ap)
{
	// parse_options -> t_options;
	if (ft_verif_specifier(specifier))
	{
		if (specifier == 'd' || specifier == 'i')
			return (ft_int_threat(ap));
		/*else if (specifier == 'p')
			return (ft_pointer_threat(ap));
		else if (specifier == 'c')
			return (ft_character_threat()*/
	}
	else
		return (0);
	return (0);
}

int ft_printf(const char *format, ...)
 {
	va_list	*ap;
	int		bytes;
	int		pos;
	pos = -1;
	va_start(*ap, format);
	while (format[++pos])
	{
		if (format[pos] == '%' && format[pos++])
			//fonction qui doit recupÃ©rer la lettre ft_recup_specifier(char *spec, va_list *arg)
		 // tant que l'on a pas un vrai flag on continue
	}
	 va_end(*ap);
	 return(0);
 }
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
