/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:20:49 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/12 14:30:57 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int main ()
{
	char	s[10] = "salut";
	char	d[10] = "sava?";
	char	s1[10] = "salut";
	char	d1[10] = "sava?";
	printf("%ld\n", ft_strlcpy(d, s, 7));
	printf("%ld\n", strlcpy(d1, s1, 7));
	printf("%s\n", d);
	printf("%s\n", d1);
}
*/
