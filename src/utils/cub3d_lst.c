/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eewu <eewu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:01:10 by eewu              #+#    #+#             */
/*   Updated: 2024/01/15 13:21:20 by eewu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/Cub3d.h"

// t_lst	*ft_lstnew(char *str)
// {
// 	return(0);
// }

t_list	*get_previous(t_list *list, t_list *current)
{
	t_list	*prev;
	t_list	*tmp;

	prev = NULL;
	tmp = list;
	while (tmp != NULL)
	{
		if (tmp->next == current)
		{
			prev = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	return (prev);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new != NULL)
	{
		new->content = content;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

int	get_current_node_index(t_list *head, t_list *current)
{
	int		index;
	t_list	*tmp;

	index = 0;
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp == current)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (-1); // Nœud non trouvé
}
// void	ft_lstadd_back(t_struct *sl, t_lst **head, t_lst *new)
// {
// 	return(0);
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (new != NULL)
	{
		if (*lst != NULL)
		{
			while (last->next != NULL)
				last = last->next;
			last->next = new;
		}
		else
			*lst = new;
	}
}
// t_lst	*ft_lstcopy(t_struct *sl, t_lst *old_lst)
// {
// 	return(0);
// }

// t_lst	*ft_lstlast(t_lst *lst)
// {
// 	return(0);
// }

// int	ft_lstsize(t_lst *lst)
// {
// 	return(0);
// }
