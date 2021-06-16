#include "../includes/ft_printf.h"

void	print_s(const char *string, t_flag *flag)
{
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
					if (i > flag->precision)
						i = flag->precision;
					while ((k < 6 && k < flag->precision))
					{
						write(1, &n[k], 1);
						k++;
					}
				}
				else while (flag->precision > 0 && string[i] != 0)
				{
					write(1, &string[i], 1);
					i++;
					flag->precision--;
				}
				while (flag->width - i - k > 0)
				{
					write(1, " ", 1);
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
						write(1, &n[k], 1);
						k++;
					}
				}
				else while (string[i] != 0)
				{
					write(1, &string[i], 1);
					i++;
				}
				while (flag->width - i - k > 0)
				{
					write(1, " ", 1);
					i++;
				}
			}
		}
		else
		{
			if (flag->dot == 1)
			{
				j = 0;
				
				while (flag->width - (j + len) > 0 || flag->width - (j + flag->precision) > 0)
				{
					write(1, " ", 1);
					j++;
				}
				if (string == NULL)
				{
					if (i > flag->precision)
						i = flag->precision;
					while (k < 6 && k < flag->precision)
					{
						write(1, &n[k], 1);
						k++;
					}
				}
				else while (flag->precision > 0 && string[i] != 0)
				{
					write(1, &string[i], 1);
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
					write(1, " ", 1);
					j++;
				}
				if (string == NULL)
				{
					if (i > flag->precision)
						i = flag->precision;
					while (k < 6 && (flag->precision == 0 || k < flag->precision))
					{
						write(1, &n[k], 1);
						k++;
					}
				}
				else while (string[i] != 0)
				{
					write(1, &string[i], 1);
					i++;
				}
			}
		}
//	}
	return ;
}
