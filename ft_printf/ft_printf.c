#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include <stdarg.h>

int ft_putstr(char *str, int len)
{
	if(!str)
	{
		str = "(null)";
	}	
	while (*str)
	{ 
		write(1,str,1);
		len++;
		str++;
	}
	return(len);
}

int ft_putnbr(long long int nbr, int base,int len)
{
	char *hexa="0123456789abcdef";
		if (nbr < 0)
		{
			nbr = -nbr;
			write(1,"-",1);
			len++;
		}
		if (nbr >= base)
		{
			len = ft_putnbr((nbr / base),base , len);
		}
		write(1,&hexa[nbr % base],1);
		len++;
		return (len);
}
int ft_printf(const char *str, ... )
{
	int len = 0;
	va_list arg;
	
	va_start(arg,str);
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			if (*str == 's')
			{
				len = ft_putstr(va_arg(arg,char *),len);
			}
			else if(*str == 'd')
			{
				len = ft_putnbr(va_arg(arg,int),10,len);
			}
			else if(*str == 'x')
			{
				len = ft_putnbr(va_arg(arg, unsigned int), 16,len);
			}
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(arg);
	return(len);
}
int main()
{
	int c = -555;
	printf("\n%d", ft_printf("%x", c));
	printf("\n");
	printf("\n%d", printf("%x", c));    
}
