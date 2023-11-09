/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:02:00 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/06 03:45:28 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_strrchr(const char *str, int c)
{
    int i;
    int len;
    char *res;

    i = 0;
    res = NULL;
    len = ft_strlen(str);
    while(i <= len)
    {
        if(str[i] == (char)c)
        {
            res = (char *) &str[i];
        }
        i++;
    }
    return (res);
}