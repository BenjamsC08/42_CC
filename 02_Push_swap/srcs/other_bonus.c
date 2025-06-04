
#include "push_swap_bonus.h"

int	check_instruct(char **instruct)
{
	int	i;

	i = 0;
	while (instruct[i])
	{
		if (ft_strncmp(instruct[i], "ra", 3) && ft_strncmp(instruct[i], "rb", 3) && ft_strncmp(instruct[i], "rr", 3) && ft_strncmp(instruct[i], "rra", 3) && ft_strncmp(instruct[i], "rrb", 3) && ft_strncmp(instruct[i], "rrr", 3) && ft_strncmp(instruct[i], "sa", 3) && ft_strncmp(instruct[i], "sb", 3) && ft_strncmp(instruct[i], "ss", 3) && ft_strncmp(instruct[i], "pb", 3) && ft_strncmp(instruct[i], "pa", 3))
		{
			ft_putstr_fd(RED, 2);
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd(RESET, 2);
			return (0);
		}
		i++;
	}
	return (1);
}
