/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:22:15 by bahn              #+#    #+#             */
/*   Updated: 2021/04/12 20:33:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static	int		ft_strlen(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}

static	char	*ft_isspace(char *str)
{
	while (*str != '\0' && (*str == ' ' || *str == '\f' || *str == '\n' ||
				*str == '\r' || *str == '\t' || *str == '\v'))
		str++;
	return (str);
}

static	int		ft_getnbr(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, char *base)
{
	int sign;
	int nbr;
	int base_length;

	sign = 1;
	nbr = 0;
	base_length = ft_strlen(base);

	str = ft_isspace(str);
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		else if (*str == '+')
			sign *= 1;
		str++;
	}
	while (*str != '\0')
	{
		if (ft_getnbr(*str, base) >= 0)
		{
			nbr = (nbr * base_length) + ft_getnbr(*str, base);
			str++;
		}
		else
			break ;
	}
	return (nbr * sign);
}

int	main(void)
{
	printf("%d\n", ft_atoi_base("      -+--+++---42", "0123456789"));
	printf("%d\n", ft_atoi_base("      -+--ff", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("      -+-ff", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("      -+abc", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("      ----456", "01234567"));
	printf("%d\n", ft_atoi_base("      ++++123", "01234567"));
	printf("%d\n", ft_atoi_base("      11111111", "01"));
	printf("%d\n", ft_atoi_base("      00001111", "01"));
	printf("%d\n", ft_atoi_base("      12345", "1a2b3c4d5e"));
	printf("%d\n", ft_atoi_base("      12a4cb", "1a2b3c4d5e"));

	return (0);
}
