/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:11:20 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/12 01:51:06 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void    ft_putnbr_fd(int n, int fd)
{
    char *num;

    num = ft_itoa(n);
    ft_putstr_fd(num, fd);
    free(num);
}*/
void	ft_putnbr_fd(int n, int fd)
{
	char	nc;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	nc = nbr % 10 + '0';
	ft_putchar_fd(nc, fd);
}
