/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:42:02 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 19:39:39 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/initiate_bonus.h"
#include "../inc/error_bonus.h"
#include "../inc/cleanup_bonus.h"
#include "../inc/utils_bonus.h"

/* This function initiates the program by opening the in-/outfile (files
to be read from and written to), allocating the required memory space
for the commands to be processed and retrieving the command paths. */

void	initiate(t_meta *meta, char **argv, int argc, char **envp)
{
	init_var(meta);
	open_infile(meta, argv);
	open_outfile(meta, argv[argc - 1]);
	meta->cmd_num = argc - 3 - meta->here_doc;
	meta->cmds = ft_calloc(meta->cmd_num, sizeof(t_cmd));
	if (!meta->cmds)
		terminate(ERR_MEM);
	meta->the_path = get_path(envp);
	meta->cmd_paths = ft_split(meta->the_path, ':');
	if (!meta->cmd_paths)
		abort_mission(meta, ERR_PATH);
}

/* This function initialises all variables in the structure with
default values. */

void	init_var(t_meta *meta)
{
	meta->infile = "";
	meta->outfile = "";
	meta->fd_in = -1;
	meta->fd_out = -1;
	meta->cmd_num = 0;
	meta->the_path = "";
}

/* This function opens the given file ready to be read from. If
here_doc is specified,  */

void	open_infile(t_meta *meta, char **argv)
{
	if (meta->here_doc == 0)
	{
		meta->infile = argv[1];
		meta->fd_in = open(meta->infile, O_RDONLY);
		if (meta->fd_in < 0)
			perror(meta->infile);
	}
	else
		here_doc(meta, argv[2]);
}

/* This function opens the given file ready to be written to. If
here_doc is specified, the text will be appended to already existing
text in the file. Else the existing text will be replaced by the new
input. */

void	open_outfile(t_meta *meta, char *s)
{
	meta->outfile = s;
	if (meta->here_doc)
		meta->fd_out = open(meta->outfile, O_WRONLY | O_APPEND \
			| O_CREAT, 0644);
	else
		meta->fd_out = open(meta->outfile, O_RDWR | O_TRUNC \
			| O_CREAT, 0644);
	if (meta->fd_out < 3)
		terminate(ERR_OPEN);
}

/* This function creates a heredoc file to which the stdin input is written
until the DELIMITER is given. It then opens the heredoc file for reading
for the following command. */

void	here_doc(t_meta *meta, char *s)
{
	int		fd;
	char	*buf;

	fd = open(".tmp_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 3)
		terminate(ERR_HEREDOC);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		buf = get_next_line(0);
		if (!buf)
			unlink_heredoc(ERR_GNL);
		if (ft_strncmp(s, buf, ft_strlen(s)) == 0)
			break ;
		write(fd, buf, ft_strlen(buf));
		free(buf);
	}
	free(buf);
	do_close(fd);
	meta->fd_in = open(".tmp_heredoc", O_RDONLY);
	if (meta->fd_in < 3)
		unlink_heredoc(ERR_HEREDOC);
}
