/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 09:38:51 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/02 15:32:39 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	char	**tab;
	size_t	words;
	size_t	letters;

	if (!s)
		return (NULL);
	words = ft_wordcount((char*)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (words--)
	{
		while (*s && *s == c)
			s++;
		letters = 0;
		while (s[letters] && s[letters] != c)
			letters++;
		tab[i++] = ft_strsub(s, 0, letters);
		s += letters;
	}
	tab[i] = NULL;
	return (tab);
}
