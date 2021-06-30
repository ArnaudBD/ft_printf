#include "../includes/ft_printf.h"

int		null_handler(int i, int k, t_flag *f)
{
	char *n;

	n = "(null)";
	if (i > f->precision)
	i = f->precision;
	if (f->minus == 1)
	{
		if (f->dot == 1 && (f->precision < 0
			|| (f->precision != i && f->precision <= 0)))
			f->precision = 6;
		while ((k < 6 && k < f->precision)
			|| (f->dot == 0 && f->precision == 0 && k < 6))
			ft_putchar_ret(n[k++], f);
	}
	else
	{
		if (f->dot == 1)
			while (k < 6 && (k < f->precision || f->precision < 0))
				ft_putchar_ret(n[k++], f);
		else
			while (k < 6 && (f->precision == 0 || k < f->precision))
				ft_putchar_ret(n[k++], f);
	}
	return (k);
}

void	print_s(const char *string, t_flag *flag)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	j = 0;
	k = 0;
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
					k = null_handler(i, k, flag);
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
					k = null_handler(i, k, flag);
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
					k = null_handler(i, k, flag);
				else while (flag->precision != 0 && string[i] != 0)
				{
					ft_putchar_ret(string[i], flag);
					i++;
					flag->precision--;
				}
			}
			else
			{
				if (string == NULL)
					len = 0;
				while (flag->width - (len + j) > 0)
				{
					ft_putchar_ret(' ', flag);
					j++;
				}
				if (string == NULL)
				{
					k = null_handler(i, k, flag);
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
