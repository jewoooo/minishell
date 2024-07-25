/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:56:53 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/25 12:39:43 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_status	ft_minishell(t_info *info)
{
	info->token = ft_tokenize(info->line, info->dup_envp, info->exit_status);
	if (info->token == NULL)
		return (FAIL);
	token_lst_printf(info->token);
	info->cmd = ft_parse(info->token, &(info->total_heredoc_cnt));
	if (info->cmd == NULL)
		return (FAIL);
	cmd_lst_printf(info->cmd);
	ft_execute(info);
	return (SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	t_info		info;

	(void)argc;
	(void)argv;
	if (init_info(&info, envp) == FAIL)
		exit(FAIL);
	while (TRUE)
	{
		init_signal(&info);
		info.line = readline("minishell$ ");
		if (info.line == NULL)
		{
			if(isatty(0))
				ft_putstr_fd("\x1b[1A\033[11Cexit\n", STDOUT_FILENO);
			break ;
		}
		if (ft_strlen(info.line) == 0)
		{
			free(info.line);
			continue ;
		}
		add_history(info.line);
		if (ft_minishell(&info) == FAIL)
			continue ;
	}
	exit(SUCCESS);
}
