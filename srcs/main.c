/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:56:53 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/06 20:53:41 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_info		info;

	info.envp = envp;
	while (TRUE)
	{
		info.line = readline("minishell$ ");
		if (info.line == NULL)
			exit(FAIL);
		add_history(info.line);
		info.token = ft_tokenize(info.line);
		if (info.token == NULL)
			continue ;
		info.cmd = ft_parse(info.token);
		if (info.cmd == NULL)
			continue ;
		ft_execute(&info);
		// cmd_lst_printf(info.cmd);
	}
	exit(SUCCESS);
}
