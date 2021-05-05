#include "ft_printf.h"

void	print_s(const char *string, t_flag *flag)
{
	int i;
	int j;
	int len;

	i = 0;
	j = 0;
	len = ft_strlen(string);

//	while (string[i] != 0)
//	{
		if (flag->minus == 1)
		{
			if (flag->dot == 1)
			{
				while (flag->precision > 0 && string[i] != 0)
				{
					write(1, &string[i], 1);
					i++;
					flag->precision--;
				}
				while (flag->width - i > 0)
				{
					write(1, " ", 1);
					i++;
				}
			}
			else
			{
				while (string[i] != 0)
				{
					write(1, &string[i], 1);
					i++;
				}
			}
		}
		else
		{
			if (flag->dot == 1)
			{
				while (flag->width - (j + len) > 0 || flag->width - (j + flag->precision) > 0)
				{
					write(1, " ", 1);
					j++;
				}
				while (flag->precision > 0 && string[i] != 0)
				{
					write(1, &string[i], 1);
					i++;
					flag->precision--;
				}
				if (string[i] == 0)
				{
					write(1, "\0", 1);
					return ;
				}
			}
			else
			{
				j = 0;
				while (flag->width - (len + j) > 0)
				{
					write(1, " ", 1);
					j++;
				}
				while (string[i] != 0)
				{
					write(1, &string[i], 1);
					i++;
				}
			}
		}
//	}
	return ;
}