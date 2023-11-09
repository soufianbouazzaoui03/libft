/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:44:54 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/06 01:10:39 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char *ss;
    unsigned char cc;
    size_t  i;

    ss = (unsigned char *) s;
    cc = (unsigned char) c;
    i = 0;
    while(i < n)
    {
        if(ss[i] == cc)
            return (void *)&ss[i];
        i++;
    }
    return (NULL);
}
