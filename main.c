#include "./includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	char	*input;
	t_token	*token;

	while (TRUE)
	{
		input = readline("minishell$ ");
		if (input == NULL)
			break ;
		add_history(input);
		printf("%s\n", input);
		token = tokenizing(input);
		if (parsing(input, &token) == FAIL)
			continue ;
		free(input);
		// executor
	}
	exit(SUCCESS);
}
