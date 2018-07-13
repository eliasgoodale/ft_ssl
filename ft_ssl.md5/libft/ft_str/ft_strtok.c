/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:35:22 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/09 14:00:50 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#define TOKEN_CSIZE 256

/*
** Creates a delimiter dictionary of size 256, setting
** the value of all dictionary[*delim[i]]'s equal to
** one and the rest at zero
*/

int		*create_delim_dict(char *delim)
{
	int		*d;
	int i;

	i = -1;
	if (!(d = (int *)malloc(sizeof(int) * TOKEN_CSIZE)))
		return (NULL);
	ft_bzero(d, TOKEN_CSIZE);
	while(++i < ft_strlen(delim))
		d[delim[i]] = 1;
	return (d);
}

char *ft_strtok(char *s, char *delim)
{
	static char *last;
	static char *to_free;
	int *deli_dict; 
	
	if(!(deli_dict = create_delim_dict(delim)))
		return (NULL);
	if (s)
	{
		if(!(last = ft_strdup(s)))
			return (NULL);
		to_free = last;
	}
	while (deli_dict[*last] && *last)
		last++;
	s = last;
	if (!*last)
	{
		free(deli_dict);
		free(to_free);
		return (NULL);
	}
	while(*last && !deli_dict[*last])
		last++;
	*last = '\0';
	free(deli_dict);
	return (s);
}