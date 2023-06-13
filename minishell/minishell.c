int	parse_prompt(char *prompt, char **envp)
{
	size_t	i;
	t_pipe_manager	*p_man;

	i = 0;
	p_man = (t_pipe_manager *)malloc(sizeof(t_pipe_manager));
	(p_man->len) = 0;
	(p_man->head) = NULL;
	while (prompt[i])
	{
		
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	char	**c_envp;

	if (argc != 1 || argv[1] != NULL)
		return (0);
	c_envp = ft_strsdup(envp);
	prompt = "echo Hello, World > a";
	parse_prompt(prompt, envp);
	return (0);
}