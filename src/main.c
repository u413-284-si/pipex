/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:30:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/16 17:28:37 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/initiate.h"
#include "../inc/error.h"

int	main(int argc, char **argv, char **envp)
{
	t_meta	meta;

	if (argc < input_check(argv[1], &meta))
		terminate(ERR_ARGC);
	initiate(&meta, argv, argc, envp);
	i = 1;
	while (++i < argc - 1)
		process_cmd(argv[i]);
	open_outfile(argv[i + 1]);
	return (0);
}

/* 	(void)argc;
	(void)argv;
	int	i = 0;

	while (envp[i])
		printf("%s\n", envp[i++]); */