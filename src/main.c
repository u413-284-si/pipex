/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:30:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 17:33:47 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/initiate.h"
#include "../inc/error.h"
#include "../inc/commands.h"
#include "../inc/cleanup.h"
#include "../inc/utils.h"

int	main(int argc, char **argv, char **envp)
{
	t_meta	meta;

	if (argc < input_check(argv[1], &meta))
		terminate(ERR_ARGC);
	initiate(&meta, argv, argc, envp);
	execute_commands(&meta, argv, envp);
	pipinator(&meta);
	cleanup(&meta);
	return (0);
}
