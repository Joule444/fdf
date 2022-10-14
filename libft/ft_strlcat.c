/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuysba <jthuysba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 16:32:26 by jthuysba          #+#    #+#             */
/*   Updated: 2022/05/12 14:41:24 by jthuysba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	d;

	i = 0;
	j = 0;
	d = ft_strlen(dest);
	if (size <= d)
		return (ft_strlen(src) + size);
	while (dest[i] != '\0' && i < size)
		i++;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	if (size < d)
		return (d + size);
	else
		return (d + ft_strlen(src));
}
/*
   int    main()
   {
   char dst1[20] = "1234";
   char src1[20] = "ABCD";
   char dst2[20] = "1234";
   char src2[20] = "ABCD";

   printf("%ld\n", ft_strlcat(dst1, src1, 7));
   printf("%s\n", dst1);
   printf("%ld\n", strlcat(dst2, src2, 7));
   printf("%s\n", dst2);
   }
 */
