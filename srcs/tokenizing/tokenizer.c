/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:12:58 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/19 16:27:48 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*tokenize(char *line)
{
	t_token	*token_lst;

	if (valid_quotes(line) == FALSE)
	{
		er_printf("Quotes errors\n");
		return (NULL);
	}
	token_lst = ft_strtok(line);
	free(line);
	return (token_lst);
}
