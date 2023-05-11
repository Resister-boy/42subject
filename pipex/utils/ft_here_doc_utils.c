void	ft_here_doc(char *argv, t_pipe *pip)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		ft_print_error(ERROR_HEREDOC);
	while (fd != 0)
	{
		line = get_next_line(0);
		if (!line)
		{
			free(line);
			break ;
		}
		write(1, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	ft_is_created(".heredoc_tmp", pip);
}

int	ft_check_heredoc(char *argv)
{
	if (argv == NULL)
		return (-1);
	if (ft_strncmp("here_doc", argv) == 1)
		return (1);
	return (0);
}

void	ft_is_created(char *filename, t_pipe *pip)
{
	(pip->fd)[0] = open(filename, O_RDONLY);
	if ((pip->fd)[0] < 0)
	{
		unlink(".heredoc_tmp");
		ft_print_error(ERROR_HEREDOC);
	}
}