#include "../includes/ft_printf.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*str;
	int		i;

	size = ft_strlen(src);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (0);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == 0)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int	reslen(unsigned int number, char *base, int dot)
{
	int	i;
	int	quo;
	int	rem;

	if (number == 0)
		return (1 - dot);
	i = 1;
	quo = number / ft_strlen(base);
	rem = number % ft_strlen(base);
	while (quo != 0)
	{
		rem = quo % ft_strlen(base);
		quo = quo / ft_strlen(base);
		i++;
	}
	return (i);
}

char	*convert_base(unsigned int number, char *base, t_flag *flag)
{
	int		i;
	int		quo;
	int		rem;
	char	*converted;

	i = reslen(number, base, flag->dot) - 1;
	quo = number / ft_strlen(base);
	rem = number % ft_strlen(base);
	converted = malloc(sizeof(char *) * i + 1);
	if (!converted)
		return (0);
	else
		converted[i + 1] = 0;
	while (i >= 0)
	{
		converted[i] = base[rem];
		rem = quo % ft_strlen(base);
		quo = quo / ft_strlen(base);
		i--;
	}
	return (converted);
}

void	print_x(unsigned int number, t_flag *flag, char *base)
{
	char	*converted;
if (flag->precision < 0)
	flag->precision = -flag->precision;
	converted = convert_base(number, base, flag);
	if (flag->minus == 1)
		{
			if (flag->precision <= flag->width)
			{
				print_xchar(flag->precision - reslen(number, base, flag->dot), '0');
				ft_putstr_fd(converted, 1);

				if (flag->precision < reslen(number, base, flag->dot))
					print_xchar(flag->width - reslen(number, base, flag->dot), ' ');
				else
					print_xchar(flag->width - flag->precision, ' ');
			}
			else if (flag->precision > reslen(number, base, flag->dot))
			{
				print_xchar(flag->precision - reslen(number, base, flag->dot), '0');
				ft_putstr_fd(converted, 1);
			}
			else
				ft_putstr_fd(converted, 1);
	}
	else
	{
		if ((flag->zero == 1 && flag->precision < reslen(number, base, flag->dot)) && flag->dot == 0)
			print_xchar(flag->width - reslen(number, base, flag->dot), '0');
		else if (flag->precision <= flag->width)
			{
				if (flag->precision < reslen(number, base, flag->dot))
					print_xchar(flag->width - reslen(number, base, flag->dot), ' ');
				else
					print_xchar(flag->width - flag->precision, ' ');
				print_xchar(flag->precision - reslen(number, base, flag->dot), '0');
			}
		else if (flag->precision > reslen(number, base, flag->dot))
		{
			print_xchar(flag->precision - reslen(number, base, flag->dot), '0');
		}
			ft_putstr_fd(converted, 1);
	}
	free(converted);
}








































