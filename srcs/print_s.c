#include "../includes/ft_printf.h"

void	print_s(const char *string, t_flag *flag)
{
	// printf("PRECISION = %d\n", flag->precision);
	// printf("WIDTH = %d\n", flag->width);
	// printf("MINUS = %d\n", flag->minus);
	// printf("STRING = %s\n", string);
	int		i;
	int		j;
	int		k;
	int		len;
	char	*n;

	i = 0;
	j = 0;
	k = 0;
	n = "(null)";
	if (string != NULL)
		len = ft_strlen(string);
	else
	{
		j += 6;
		if (flag->dot == 0)
			len = 6;
		else if (flag->precision > 5)
			len = 6;
		else
			len = flag->precision;
	}

	
		if (flag->minus == 1)
		{
			if (flag->dot == 1)
			{
				if (string == NULL)
				{
					if (i > flag->precision && flag->precision > 0)
						i = flag->precision;
					else if (flag->precision < 0)
						flag->precision = 6;
					while ((k < 6 && k < flag->precision))
					{
						ft_putchar_ret(n[k], flag);
						k++;
					}
				}
				else if (flag->precision >= 0)
					while (flag->precision > 0 && string[i] != 0)
					{
						ft_putchar_ret(string[i], flag);
						i++;
						if (flag->precision < flag->width)
							flag->precision--;
					}
				else
				{
					flag->precision = -flag->precision + 2;
					while (flag->precision > 0 && string[i] != 0)
					{
						ft_putchar_ret(string[i], flag);
						i++;
						if (-flag->precision < flag->width)
							flag->precision--;
					}
					flag->precision = -flag->precision;
				}
				if (flag->width < 0)
					flag->width = -flag->width;
				while (flag->width - i - k > 0)
				{
					ft_putchar_ret(' ', flag);
					i++;
				}
			}
			else
			{
				if (string == NULL)
				{
					if (i > flag->precision)
						i = flag->precision;

					while (k < 6 && (flag->precision == 0 || k < flag->precision))
					{
						ft_putchar_ret(n[k], flag);
						k++;
					}
				}
				else while (string[i] != 0)
				{
					ft_putchar_ret(string[i], flag);
					i++;
				}
				while (flag->width - i - k > 0)
				{
					ft_putchar_ret(' ', flag);
					i++;
				}
			}
		}
		else
		{
			if (flag->dot == 1)
			{
				j = 0;
				
				while (flag->precision >= 0 && (flag->width - (j + len) > 0 || flag->width - (j + flag->precision) > 0))
				{
					ft_putchar_ret(' ', flag);
					j++;
				}
				if (string == NULL)
				{
					if (i > flag->precision)
						i = flag->precision;
					while (k < 6 && k < flag->precision)
					{
						ft_putchar_ret(n[k], flag);
						k++;
					}
				}
				else while (flag->precision != 0 && string[i] != 0)
				{
					ft_putchar_ret(string[i], flag);
					i++;
					flag->precision--;
				}
				// //if (string[i] == 0)
				// {
				// 	write(1, "\0", 1);
				// 	return ;
				// }
			}
			else
			{
				if (string == NULL)
					len = 0;
				//j = 0;
				while (flag->width - (len + j) > 0)
				{
					ft_putchar_ret(' ', flag);
					j++;
				}
				if (string == NULL)
				{
					if (i > flag->precision)
						i = flag->precision;
					while (k < 6 && (flag->precision == 0 || k < flag->precision))
					{
						ft_putchar_ret(n[k], flag);
						k++;
					}
				}
				else while (string[i] != 0)
				{
					ft_putchar_ret(string[i], flag);
					i++;
				}
			}
		}
//	}
	return ;
}
