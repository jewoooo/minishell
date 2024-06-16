/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 02:43:40 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/17 02:51:52 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*token_lst_new(char *value, t_tokentype type)
{
	t_token	*new;

	new = (t_token *)ft_calloc(1, sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->value = value;
	new->type = type;
	return (new);
}

void	token_lst_add_back(t_token **lst, t_token *new)
{
	t_token	*curr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	new->prev = curr;
	curr->next = new;
}

void	token_lst_clear(t_token **lst)
{
	t_token	*curr;
	t_token	*tmp;

	if (lst == NULL)
		return ;
	curr = *lst;
	while (curr)
	{
		free(curr->value);
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*lst = NULL;
}
