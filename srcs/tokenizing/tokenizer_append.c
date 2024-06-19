/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:00:17 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/19 15:56:14 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	append_operator(t_tokentype type, char **line,
	t_token **token_lst)
{
	t_token	*new;

	new = token_lst_new(NULL, type);
	if (new == NULL)
		return (FAIL);
	token_lst_add_back(token_lst, new);
	(*line)++;
	if (type == HEREDOC || type == APPEND_O_REDIRECT)
		(*line)++;
	return (SUCCESS);
}
