/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:56:53 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/19 16:08:00 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_token	*token;

	while (TRUE)
	{
		input = readline("minishell$ ");
		if (input == NULL)
		{
			er_printf("Input error");
			continue ;
		}
		add_history(input);
		token = tokenize(input);
		if (token == NULL)
			continue ;
		token_lst_printf(token);
		// parser
		// executor
	}
	exit(SUCCESS);
}
