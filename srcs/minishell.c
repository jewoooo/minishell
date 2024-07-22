/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:56:53 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/22 19:44:56 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sfree(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

char	*super_join(char *src1, char *src2)
{
	char	*dst;

	dst = ft_strjoin(src1, src2);
	sfree(src1);
	sfree(src2);
	return (dst);
}

//token_lst_printf(info->token);
//cmd_lst_printf(info->cmd);
t_status	ft_minishell(t_info *info)
{
	info->token = ft_tokenize(info->line, info->exit_status);
	if (info->token == NULL)
		return (FAIL);
	info->cmd = ft_parse(info->token, &(info->total_heredoc_cnt));
	if (info->cmd == NULL)
		return (FAIL);
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
