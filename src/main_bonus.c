/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:30:40 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 18:47:36 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../inc/initiate_bonus.h"
#include "../inc/error_bonus.h"
#include "../inc/commands_bonus.h"
#include "../inc/cleanup_bonus.h"
#include "../inc/utils_bonus.h"

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
