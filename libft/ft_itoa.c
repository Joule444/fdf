/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:13:13 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/16 14:44:38 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(long int n)
{
	size_t		i;
	long int	nb;

	nb = n;
	i = 1;
	if (nb < 0)
		nb *= -1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	put_nbr(char *str, long int n, size_t i)
{
	if (i > 0)
		put_nbr(str, n / 10, --i);
	str[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	size_t		len;
	long int	nb;
	char		*str;
	int			neg;

	nb = n;
	len = 0;
	neg = 0;
	if (nb < 0)
		len++;
	len += nbr_len(nb);
	str = malloc(sizeof(char) * (len + 1));
	ft_memset(str, 0, len + 1);
	if (nb < 0)
	{
		neg = 1;
		nb = nb * (-1);
	}
	put_nbr(str, nb, len);
	if (neg)
		str[0] = '-';
	return (str);
}
/*
#include <limits.h>

int	main()
{
	printf("%s\n", ft_itoa(INT_MIN));
}
*/
