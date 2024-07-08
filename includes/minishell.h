/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 23:57:09 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/08 13:13:22 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>

# include "./basic.h"
# include "../libft/libft.h"
# include "./tokenizing.h"
# include "./parsing.h"

typedef struct	s_info
{
	// int			here_doc_cnt; 보류
	char		*line;
	char		**og_envp;
	char		**dup_envp;
	pid_t		pid;
	t_token		*token;
	t_command	*cmd;
}	t_info;

# include "./executing.h"
# include "./builtins.h"

// 4_envp/init_envp.c
t_bool	init_envp(t_info *info, char **envp);

#endif