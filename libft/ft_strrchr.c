/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:54:09 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/16 14:20:06 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (ft_strlen(s) > 0)
		i = ft_strlen(s) - 1;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main ()
{
	char	s[15] = "bonjour";
	printf("%s", ft_strrchr(s, 's'));
}
*/
