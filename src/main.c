/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:30:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/20 14:53:00 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/initiate.h"
#include "../inc/error.h"
#include "../inc/commands.h"
#include "../inc/cleanup.h"

int	main(int argc, char **argv, char **envp)
{
	t_meta	meta;

	if (argc < input_check(argv[1], &meta))
		terminate(ERR_ARGC);
	initiate(&meta, argv, argc, envp);
	exec_cmd(&meta, argv, envp);
	plug_pipes(&meta);
	cleanup(&meta);
	return (0);
}

/* 	(void)argc;
	(void)argv;
	int	i = 0;

	while (envp[i])
		printf("%s\n", envp[i++]); */