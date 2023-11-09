/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 04:02:27 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/06 04:42:20 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



int ft_isspace(int num)
{
    if(num == '\t' || num == '\n' || num == '\r' || num == '\f' || num == '\v' || num == ' ')
        return (1);
    else
    return (0);
    
}

int ft_atoi(const char *str)
{
    int sign;
    int res;
    int i;
    
    i = 0;
    res = 0;
    sign = 1;
    while(ft_isspace(str[i]))
        i++;
    if(str[i] == '+' && str[i+1] != '-')
    i++;
    if(str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] - '0');
        i++;
    }
    return(sign * res);
}
