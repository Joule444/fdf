/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:26:17 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/06 15:02:07 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		if (str[i] == to_find[0])
		{
			while (str[i + j] == to_find[j] && i + j < n)
			{
				if (to_find[j + 1] == '\0')
					return ((char *)str + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
