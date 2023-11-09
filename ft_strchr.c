/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 23:22:44 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/05 23:43:56 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
    int len;
    int i;
    
    i = 0;
    len = ft_strlen(s);
    while(i <= len)
    {
        if(s[i] == (char) c)
        {
            return((char *) &s[i]);
        }
        i++;
    }
    return (NULL);
}