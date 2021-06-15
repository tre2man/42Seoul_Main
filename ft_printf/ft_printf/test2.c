#include <stdio.h>
#include <stdlib.h>

static int		ft_iscontrol(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	long long	ans;
	int			minus;

	ans = 0;
	minus = 1;
	while (*str != '+' && *str != '-' && *str
			&& (ft_iscontrol(*str) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		ans = (ans * 10) + minus * (*str - '0');
		if (ans > INT32_MAX)
			return (-1);
		else if (ans < INT32_MIN)
			return (0);
		str++;
	}
	return ((int)ans);
}

int main()
{
    printf("%d", ft_atoi("05d"));
}