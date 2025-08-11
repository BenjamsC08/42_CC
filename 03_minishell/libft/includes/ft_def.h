/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 02:12:12 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/29 17:42:40 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEF_H
# define FT_DEF_H

# include "libft.h"

# define RESET "\001\033[0m\002"
# define RED "\001\033[0;31m\002"
# define GREEN "\001\033[0;32m\002"
# define YELLOW "\001\033[0;33m\002"
# define BLUE "\001\033[0;34m\002"
# define MAGENTA "\001\033[0;35m\002"
# define CYAN "\001\033[0;36m\002"
# define WHITE "\001\033[0;37m\002"
# define ORANGE "\001\033[0;91m\002"
# define PURPLE "\001\033[0;95m\002"
# define DARK_ORANGE "\001\033[0;33m\002"
# define PINK "\001\033[0;95m\002"
# define TEAL "\001\033[0;96m\002"
# define GRAY "\001\033[0;90m\002"

typedef unsigned long	t_ulong;
typedef unsigned long	t_uintptr;
typedef unsigned int	t_uint;

# define START 'S'
# define END 'E'

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

#endif
