/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 20:39:13 by egoodale          #+#    #+#             */
/*   Updated: 2018/06/02 15:32:39 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstpushback(t_list **begin_list, t_list *node)
{
	t_list	*current;

	if (!begin_list)
		return (NULL);
	if (!*begin_list)
		return (*begin_list = node);
	current = *begin_list;
	if (!(current))
	{
		*begin_list = node;
		return (*begin_list);
	}
	while (current->next)
		current = current->next;
	current->next = node;
	return (*begin_list);
}
