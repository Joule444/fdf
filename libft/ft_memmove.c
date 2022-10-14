/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:23:52 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/12 12:08:29 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dest;
	s = src;
	if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
/*
int main()
{
char dest[10] = "123456789";
char src[10] = "+";

char dest1[10] = "123456789";
char src1[10] = "+";

printf("%p\n", ft_memmove(dest, src, 1));
printf("%s\n", dest);

printf("%p\n", memmove(dest1, src1, 1));
printf("%s\n", dest1);
}
*/
