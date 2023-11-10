/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 03:21:22 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/11 00:25:19 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char    *ft_strnstr(const char *string, const char *str, size_t len)
{
    size_t  i;
    size_t  j;
    
    i = 0;
    j = 0;
    if(!*str)
        return ((char *)string);
    while(i < len)
    {
        if(string[i] == str[j])
        {
            while(string[i + j] == str[j] && string[i + j] && i + j < len)
            {
                j++;
                if(str[j] == '\0')
                    return((char *)&str[i]);
            }
        }
        i++;
        j = 0;
    }
    return (NULL);
}*/
char	*ft_strnstr(const char *string, const char *str, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*str)
		return ((char *)string);
	while (i < len && string[i])
	{
		if (string[i + j] == str[j])
		{
			while (j < ft_strlen(str) && (i + j) < len 
				&& string[i + j] == str[j])
				j++;
			if (j == ft_strlen(str))
				return ((char *)&string[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
