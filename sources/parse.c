/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferna <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:07:43 by daxferna          #+#    #+#             */
/*   Updated: 2024/12/05 17:41:59 by daxferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	ft_addtolist(t_list *stack_a, char	*num)
{
	t_list	*new_node;
	int		*numint;

	numint = malloc(sizeof(int));
	if (ft_imprvatoi(num, numint) == 0) // Comprobar que esta entre minint y maxint y pasar a int
		return (0);
	new_node = ft_lstnew(&num); // Crear nuevo nodo
	if (!new_node)
		return (0);
	ft_lstadd_back(&stack_a, new_node); // Agregar nodo a la lista
	return (1);
}

void	ft_assignindex(t_list *stack_a)
{
	//TODO: Implementar
}

bool	ft_parse(int argc, char **argv, t_list *stack_a)
{
	char	**sp_arg;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc) // Recorrer cada argumento
	{
		sp_arg = ft_split(argv[i++], ' '); // Split de cada argumento
		if (sp_arg == NULL)
			return (0);
		while (sp_arg[j++]) // Recorrer cada argumento splitteado
		{
			if (!ft_addtolist(stack_a, sp_arg[j])) //Comprobar int y no repetido y agregar a lista
				return (0);
		}
	}
	ft_assignindex(stack_a); // Asignar index a cada nodo
	free(sp_arg);
	return (1);
}
