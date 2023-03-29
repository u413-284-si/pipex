/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:02:48 by sqiu              #+#    #+#             */
/*   Updated: 2023/03/29 18:39:50 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

/* ====== FUNCTIONS ====== */

char	*get_path(char **envp);
int		input_check(char *s, t_meta *meta);
void	replace_fd(int input_fd, int output_fd);
char	*get_cmd(char *cmd, char **cmd_paths);

#endif