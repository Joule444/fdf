/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:54 by jthuysba          #+#    #+#             */
/*   Updated: 2022/10/17 15:35:38 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strcpy_gnl(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen_gnl(src));
}

size_t	ft_strlcat_gnl(char *dest, const char *src)
{
	size_t	i;
	size_t	j;
	size_t	d;

	i = 0;
	j = 0;
	d = ft_strlen_gnl(dest);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (d + ft_strlen_gnl(src));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (free(s1), dest);
}
