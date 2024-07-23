/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:12:58 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/23 12:53:54 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	define_token_type(t_token *token)
{
	while (token != NULL)
	{
		if (token->value != NULL && token->type == ARGUMENT)
		{
			if (token->prev != NULL)
			{
				if ((token->prev->type == INPUT_REDIRECT
						|| token->prev->type == OUTPUT_REDIRECT
						|| token->prev->type == APPEND_O_REDIRECT))
					token->type = FILE_NAME;
				else if (token->prev->type == HEREDOC)
					token->type = END_OF_FILE;
				else if (token->prev->type == FILE_NAME
					|| token->prev->type == END_OF_FILE
					|| token->prev->type == PIPE)
					token->type = COMMAND;
			}
			else
				token->type = COMMAND;
		}
		token = token->next;
	}
}

t_token	*ft_strtok(char *line)
{
	t_status	flag;
	t_token		*token_lst;

	flag = SUCCESS;
	token_lst = NULL;
	while (*line != '\0')
	{
		if (flag == FAIL)
			exit(FAIL);
		while (ft_isspace(*line) == TRUE)
			line++;
		if (*line == '\0')
			break ;
		if (*line == '>' || *line == '<' || *line == '|')
			flag = tokenize_operator(&line, &token_lst);
		else
			flag = tokenize_identifier(&line, &token_lst);
	}
	define_token_type(token_lst);
	return (token_lst);
}

t_token	*ft_tokenize(char *line, char **envp, int exit_status)
{
	t_token	*token_lst;
	char	*expand_line;

	(void)exit_status;
	if (valid_quotes(line) == FALSE)
	{
		ft_fprintf(STDERR_FILENO, "Invalid quote\n");
		return (NULL);
	}
	expand_line = substitute_env(line, envp, exit_status);
	if (expand_line == NULL)
		exit(FAIL);
	free(line);
	token_lst = ft_strtok(expand_line);
	if (token_lst == NULL)
		exit(FAIL);
	free(expand_line);
	return (token_lst);
}
