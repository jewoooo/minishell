#include <stdio.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef enum s_status
{
	SUCCESS,
	FAIL
}	t_status;

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum s_tokentype
{
	COMMAND,
	ARGUMENT,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION,
	APPEND_OUTPUT_REDIRECTION,
	PIPE,
}	t_tokentype;

typedef struct s_token
{
	char		*value;
	t_tokentype	type;
}	t_token;

int	count_inputs(char **inputs)
{
	int	size;

	size = 0;
	while (inputs[size] != NULL)
		size++;
	return (size);
}

t_bool	check_command(char *s)
{
	if (ft_strncmp(s, "echo", 5) == 0)
		return (TRUE);
	else if (ft_strncmp(s, "cd", 3) == 0)
		return (TRUE);
	else if (ft_strncmp(s, "pwd", 4) == 0)
		return (TRUE);
	else if (ft_strncmp(s, "export", 6) == 0)
		return (TRUE);
	else if (ft_strncmp(s, "unset", 6) == 0)
		return (TRUE);
	else if (ft_strncmp(s, "exit", 5) == 0)
		return (TRUE);
	return (FALSE);
}

t_tokentype	check_tokentype(char *s)
{
	if (ft_strncmp(s, "<", 2) == 0)
		return (INPUT_REDIRECTION);
	else if (ft_strncmp(s, ">", 2) == 0)
		return (OUTPUT_REDIRECTION);
	else if (ft_strncmp(s, ">>", 3) == 0)
		return (APPEND_OUTPUT_REDIRECTION);
	else if (ft_strncmp(s, "|", 2) == 0)
		return (PIPE);
	else if (check_command(s) == TRUE)
		return (COMMAND);
	return (ARGUMENT);
}

t_status	init_token(char **inputs, t_token **token, int size)
{
	int	i;

	*token = (t_token *)malloc(sizeof(t_token) * (size + 1));
	if (*token == NULL)
		return (FAIL);
	ft_memset(*token, 0, sizeof(t_token) * size);
	i = 0;
	while (inputs[i] != NULL)
	{
		(*token)[i].value = inputs[i];
		(*token)[i].type = check_tokentype(inputs[i]);
		i++;
	}
	(*token)[i].value = NULL;
	return (SUCCESS);
}

t_status	lexer(char *input, t_token **token)
{
	char	**inputs;

	inputs = ft_split(input, ' ');
	if (inputs == NULL)
		return (FAIL);
	init_token(inputs, token, count_inputs(inputs));
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	int		i;
	t_token	*token;
	char	*input;
	char	**inputs;

	if (isatty(STDIN_FILENO))
	{
		while (1)
		{
			input = readline("minishell$ ");
			if (lexer(input, &token) == FAIL)
				exit(FAIL);
			i = 0;
			while (token[i].value != NULL)
			{
				printf("%u %s\n", token[i].type, token[i].value);
				i++;
			}
			exit(SUCCESS);
		}
	}
	free(input);
	return (0);
}

// Implement prompt
// Implement lexer
// 2024.06.13