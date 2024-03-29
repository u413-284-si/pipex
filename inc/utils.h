/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:48 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 19:07:35 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* ====== FUNCTIONS ====== */

char	*get_path(char **envp);
void	replace_fd(int input_fd, int output_fd);
char	*get_cmd(char *cmd, char **cmd_paths);

#endif