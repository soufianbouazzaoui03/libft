/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:46:57 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/06 17:48:58 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *fill(char  *strj, const char   *s1, const char *s2, size_t s1len, size_t   s2len)
{
    size_t  i;
    size_t  j;

    i = 0;
    j = 0;
    while(i < s1len)
    {
        strj[i] = s1[i];
        i++;
    }
    while(i < s1len + s2len)
    {
        strj[i] = s2[j];
        i++;
        j++;
    }
    strj[i++] = '\0';
    return strj;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *strj;
    size_t  s1len;
    size_t  s2len;
    size_t  i;
    size_t  j;
    
    i = 0;
    j = 0;
    s1len = ft_strlen(s1);
    s2len = ft_strlen(s2);
    strj = (char*)malloc((s1len + s2len + 1)*sizeof(char));
    if(!strj)
    return (NULL);
    if(s1 && s2)
    {
        strj = fill(strj,s1,s2,s1len,s2len);
        return (strj);
    }
    return NULL;
}
