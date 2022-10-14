/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:47:29 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/16 14:54:35 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	check_str(char const *s, char const c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	if (!set)
		return (ft_strdup(s1));
	j = ft_strlen(s1);
	while (check_str(set, s1[i]) && s1[i])
		i++;
	while (j > 0)
	{
		if (!check_str(set, s1[j - 1]))
			break ;
		j--;
	}
	if (i > j)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (j - i + 1));
	ft_memset(dest, 0, j - i + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1 + i, j - i + 1);
	return (dest);
}
/*
int main(void)
{
	printf("%s", ft_strtrim("1000000000000101","01"));
}
*/
