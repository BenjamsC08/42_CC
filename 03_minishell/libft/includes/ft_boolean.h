/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moa <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 06:15:53 by moa               #+#    #+#             */
/*   Updated: 2025/03/04 09:16:41 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# define TRUE 1
# define FALSE 0

# define SUCCESS 0
# define FAILED 1

typedef int				t_bool;
typedef unsigned int	t_booltab;

typedef struct s_boolarray
{
	t_booltab			*data;
	unsigned int		bit_capacity;
}						t_boolarray;

/*enum*/
/*{*/
/*	FLAG_RUNNING = 0,*/
/*	FLAG_PAUSED = 1,*/
/*	FLAG_ERROR = 2,*/
/*	FLAG_ACTIVE = 3*/
/*};*/

#endif
