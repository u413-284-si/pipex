/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 11:38:22 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/20 15:13:40 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

/* ====== FUNCTIONS ====== */

void	exec_cmd(t_meta *meta, char **argv, char **envp);
char	*get_cmd(char *cmd, char **cmd_paths);
void	create_child(t_meta *meta, char **envp);
void	replace_fd(int input_fd, int output_fd);
void	plug_pipes(t_meta *meta);

#endif