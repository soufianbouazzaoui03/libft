/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:56:21 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/07 22:09:31 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int wordcounter(const char *s, char c)
{
    int numofwords;
    int i;

    if (!s || !*s)
        return (0);
    i = 0;
    numofwords = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            numofwords++;
            while (s[i] && s[i] != c)
                i++;
        }
        else
        {
            i++;
        }
    }
    return (numofwords);
}
char *fill(const char *s, size_t start, size_t end)
{
    char *word;
    int i;
    
    i = 0;
    word = (char *)malloc((end - start + 1) * sizeof(char));
    if (!word)
        return (NULL);
    while(start < end)
    {
        word[i] = s[start];
        i++;
        start++;
    }
    word[i] = '\0';
    return(word);
}

void    ft_free(char **list,int numofword)
{
    int i;

    i = 0;
    while(i<numofword)
    {
        free(list[i]);
        i++;
    }
    free(list);
}


char **ft_split(const char *s, char c)
{
    char **list;
    int now;
    size_t  start;
    size_t  end;
    size_t  i;
    
    if(s == NULL)
        return (NULL);
    i = 0;
    now = wordcounter(s,c);
    list = (char **)malloc((now + 1) * sizeof(char*));
    if(!list)
    return(NULL);
    list[now]  = NULL;
    while(i <= strlen(s))
    {
        while(s[i] == c)
            i++;
        if(s[i] != c && s[i])
        {
            start = i;
            while(s[i] != c && s[i])
                i++;
            end = i;
            *list = fill(s,start,end);
            if(!(*list))
            {
                ft_free(list,now);
                return (NULL);
            }
            list++;
        }
        i++;
    }
    return (list - now);
}

void ff (void)
{
    system("leaks a.out");
}
int main()
{
    atexit(ff);
    int i;
    char **list;
    list = ft_split(NULL, ' ');

    i = 0;
    // printf("========= %p | %p\n", list, *list);
    while (list && list[i])
    {
        puts(list[i++]);
        free(list[i-1]);
    }
    free(list);
    return 0;
}