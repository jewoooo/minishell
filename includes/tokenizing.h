/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minhulee <minhulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 02:40:32 by jewlee            #+#    #+#             */
/*   Updated: 2024/07/22 19:34:31 by minhulee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

#include "./struct.h"

typedef enum	e_token_type
{
	COMMAND,
	ARGUMENT,
	INPUT_REDIRECT,
	OUTPUT_REDIRECT,
	APPEND_O_REDIRECT,
	HEREDOC,
	PIPE,
	FILE_NAME,
	END_OF_FILE,
}	t_token_type;

typedef struct	s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

/* token */
t_token		*new_token(char *value, t_token_type type);
void		token_lst_append(t_token **lst, t_token *dst);
void		token_lst_clear(t_token **lst);
void		token_lst_printf(t_token *lst);

/* env_to_value */
char		*substitute_env(char *line, int exit_status);

/* tokenizer */
t_token		*ft_tokenize(char *line, int exit_status);

/* method */
char		*tokenize_quote_str(char **line);
char		*tokenize_str(char **line);
t_status	tokenize_operator(char **line, t_token **token_lst);
t_status	tokenize_identifier(char **line, t_token **token_lst);

/* utils */
t_bool		valid_quotes(char *line);
t_bool		ft_isspace(char c);
t_bool		ft_isquote(char c);
t_bool		ft_isoperator(char c);
t_status	skip_quotes(char *line, int *i);

#endif