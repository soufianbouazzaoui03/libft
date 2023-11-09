/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:04:53 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/05 21:37:42 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t  i;
    unsigned char   *d;
    unsigned char   *s;

    i = 0;
    d = (unsigned char*) dst;
    s = (unsigned char*) src;
    if (!dst && !src)
        return (NULL);
    if(s < d)
    {
        i = len;
        while(i > 0)
        {
            d[i - 1] = s[i - 1];
            i--;
        }
    }
    else
    {
        while(i < len)
        {
            d[i] = s[i];
            i++;
        } 
    }
    return dst;
}