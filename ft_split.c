/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:56:21 by soel-bou          #+#    #+#             */
/*   Updated: 2023/11/11 20:44:55 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef struct data
{
	char		**list;
	const char	*s;
	char		c;
	size_t		*i;
	int			now;
}t_data;

static int	wordcounter(const char *s, char c)
{
	int	numofwords;
	int	i;

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

static char	*fill(const char *s, size_t start, size_t end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **list, int numofword)
{
	int	i;

	i = 0;
	while (i < numofword)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

static char	**split_loop(t_data mydata)
{
	size_t	start;
	size_t	end;

	while (mydata.s[*mydata.i] == mydata.c)
		(*mydata.i)++;
	if (mydata.s[*mydata.i] != mydata.c && mydata.s[*mydata.i])
	{
		start = *mydata.i;
		while (mydata.s[*mydata.i] != mydata.c && mydata.s[*mydata.i])
			(*mydata.i)++;
		end = *mydata.i;
		*mydata.list = fill(mydata.s, start, end);
		if (!(*mydata.list))
		{
			ft_free(mydata.list, mydata.now);
			return (NULL);
		}
		mydata.list++;
	}
	return (mydata.list);
}

char	**ft_split(const char *s, char c)
{
	char	**list;
	int		now;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	now = wordcounter(s, c);
	list = (char **)malloc((now + 1) * sizeof(char *));
	if (!list)
		return (NULL);
	list[now] = 0;
	while (i <= ft_strlen(s))
	{
		t_data	mydata = {list, s, c, &i, now};
		list = split_loop(mydata);
		if (!list)
			return (0);
		i++;
	}
	return (list - now);
}
/*char **ft_split(const char *s, char c)
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
    while(i <= ft_strlen(s))
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
}*/