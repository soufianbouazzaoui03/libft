/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:56:07 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/06 17:01:58 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t num, size_t size)
{
    void    *ptrcalloc;

    ptrcalloc = malloc(num * size);
    if(ptrcalloc == NULL)
        return (NULL);
    ft_memset( ptrcalloc, 0, num * size);
    return (ptrcalloc);
}