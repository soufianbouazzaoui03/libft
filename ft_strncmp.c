/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 00:30:15 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/06 00:41:11 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t  i;

    i = 0;
    while((str1[i] || str2[i]) && i < n)
    {
        if((unsigned char)str1[i] != (unsigned char)str2[i])
            return ((unsigned char)str1[i] - (unsigned char)str2[i]);
        i++;
    }
    return (0);
}
