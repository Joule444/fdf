/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:23:34 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/12 12:45:18 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ps;

	i = 0;
	ps = (unsigned char *)s;
	while (i < n)
	{
		if (ps[i] == (unsigned char)c)
			return (ps + i);
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char    s[50] = "Salut";

    printf("%p\n", ft_memchr(s, 2 + 256, 3));
    printf("%p", memchr(s, 2 + 256, 3));
}
*/
