/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:20:26 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/08 01:52:51 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int  ft_size(long n)
{
    int size;

    size = 1;
    while(n / 10)
    {
        size++;
        n /= 10;
    }
    return size;
}

long ft_size2(long n)
{
    long res;

    res = 1;
    while(n > 1)
    {
        res *= 10;
        n--;
    }
    return res;
}

char    *fillpos(size_t    size,long   nbr, long   zeros)
{
    int i;
    char    *res;

    i = 0;
    res = (char *)malloc((size + 1) * sizeof(char));
    while(zeros)
    {
        res[i++] = nbr / zeros + '0';
        nbr = nbr - (nbr/zeros)*zeros;
        zeros /= 10;
    }
    res[size] = '\0';
    return (res);
}
char    *fillnega(size_t    size, long  nbr, long   zeros)
{
    int i;
    char    *res;

    i = 1;
    nbr = nbr * (-1);
    res = (char *)malloc((size + 2) * sizeof(char));
    res[0] = '-';
    while(zeros)
    {
        res[i++] = nbr / zeros + '0';
        nbr = nbr - (nbr/zeros)*zeros;
        zeros /= 10;
    }
    res[size + 1] = '\0';
    return (res);
}
char    *ft_itoa(int n)
{
    long    nbr;
    char    *res;
    size_t  size;
    long    zeros;
    
    nbr = n;
    size = ft_size(nbr);
    zeros = ft_size2(size);
    if (nbr == 0)
    return(strdup("0"));
    if(nbr > 0)
    {
        res = fillpos(ft_size(nbr),nbr,ft_size2(ft_size(nbr)));
        if(!res)
        return (NULL);
    }
    else
    {
        res = fillnega(ft_size(nbr), nbr, ft_size2(ft_size(nbr)));
        if(!res)
        return (NULL);
    }
    return(res);
}



/*int main()
{
    printf("%s",ft_itoa(2));
    return(0);
}*/
