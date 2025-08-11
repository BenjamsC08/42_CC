/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:42:51 by mkerrien          #+#    #+#             */
/*   Updated: 2025/06/27 15:20:01 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include <sys/types.h>

# define INFILE 0
# define HEREDOC 1
# define TRUNC 0
# define APPEND 1
# define ERROR_REDIR -1
# define IS_REDIR 1
# define NOT_REDIR 0
# define PWD 'P'
# define USER 'U'
# define HOME 'H'
# define PTH "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
# define HISTORY_PATH "/tmp/.ms_history"

typedef struct s_data
{
	char			*name;
	char			**env;
	t_uint			env_size;
	char			**export;
	char			**paths;
	char			**cmd;
	char			*delimiter;
	int				stdin;
	int				stdout;
	int				hd_prompt_fd;
	int				status;
	int				exit_code;
	int				old_exit_code;
	int				*pipes;
	pid_t			*pids;
	char			*pwd;
	struct s_cmd	**head;
}			t_data;

typedef struct s_cmd
{
	char			**cmd;
	char			**hd;
	char			**redir_in;
	char			**redir_out;
	int				no;
	int				infile;
	int				outfile;
	int				type_redir_in;
	int				*type_redir_out;
	t_bool			pipe;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}			t_cmd;

typedef struct s_dlex
{
	char	*token;
	char	type;
}			t_dlex;

#endif
