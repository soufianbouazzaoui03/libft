/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:03:09 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/10 23:17:40 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*rtr;

	rtr = (t_list *)malloc(sizeof(t_list));
	if (!rtr)
		return (NULL);
	rtr->content = content;
	rtr->next = NULL;
	return (rtr);
}
