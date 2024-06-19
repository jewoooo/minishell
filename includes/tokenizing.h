/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jewlee <jewlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 02:40:32 by jewlee            #+#    #+#             */
/*   Updated: 2024/06/19 15:29:04 by jewlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

typedef enum	s_tokentype
{
	IDENTIFIER,
	INPUT_REDIRECT,
	OUTPUT_REDIRECT,
	APPEND_O_REDIRECT,
	HEREDOC,
	PIPE,
	FILE_NAME,
}	t_tokentype;

typedef struct	s_stack {
    char quote;
    struct s_stack *next;
}	t_stack;

typedef struct	s_token
{
	t_tokentype		type;
	char			*value;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;


// tokenizer.c
t_token			*tokenize(char *line);

// tokenizer_append.c
t_status	append_operator(t_tokentype type, char **line
	, t_token **token_lst);

// tokenizer_strtok.c
t_token	*ft_strtok(char *line);

// tokenizer_lst.c
t_token	*token_lst_new(char *value, t_tokentype type);
void	token_lst_clear(t_token **lst);
void	token_lst_add_back(t_token **lst, t_token *new);

// tokenizer_stack.c
t_stack	*st_create_node(char quote);
void	st_push(t_stack **stack, char quote);
char	st_pop(t_stack **stack);
t_bool	st_is_empty(t_stack *stack);

// lst_printf
void	token_lst_printf(t_token *lst);

// tokenizer_utils.c
t_bool		valid_quotes(char *line);
t_bool		ft_isspace(char c);
t_bool		ft_isquote(char c);
t_status	skip_quotes(char *line, int *i);

#endif