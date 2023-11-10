/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 03:22:45 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/10 19:55:51 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **p;

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
    t_list  *newlist;
    void    *content;
    t_list  *add;

    if(!f || !del)
        return (NULL);
    newlist = NULL;
    while(lst)
    {
        content = f(lst->content);
        add = ft_lstnew(content);
        if(!add)
        {
            del(content);
            ft_lstclear(&newlist, del);
            return (NULL);
        }
        ft_lstadd_back(&newlist, add);
        lst = lst->next;
    }
    return(newlist);
}
void    *tup(void *ptr)
{
    void *tmp;

    tmp = ptr;
    while (*(char *)ptr)
    {
        *(char *)ptr = ft_toupper(*(char *)ptr);
        ptr++;
    }
    return(tmp);
}

/*int main(int argc, char const *argv[])
{
    t_list *lst;
    
    lst = NULL;

    p = ft_split("hello world am hamza and am a  student here!", ' ');
    int i = 0;
    while (p[i])
        ft_lstadd_back(&lst, ft_lstnew(p[i++]));
    ft_lstmap(lst, tup, free);
    return 0;
}*/