/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:49:03 by benjamsc          #+#    #+#             */
/*   Updated: 2025/03/04 09:19:24 by benjamsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_boolarray	create_bool_array(unsigned int num_bits)
{
	unsigned int	num_ints;
	t_booltab		*data;

	num_ints = (num_bits + 31) / 32;
	data = ft_calloc(num_ints, sizeof(t_booltab));
	return ((t_boolarray){data, num_bits});
}

void	free_bool_array(t_boolarray *arr)
{
	free(arr->data);
	arr->data = NULL;
	arr->bit_capacity = 0;
}
/*enum*/
/*{*/
/*	FLAG_RUNNING = 0,*/
/*	FLAG_PAUSED = 1,*/
/*	FLAG_ERROR = 2,*/
/*	FLAG_ACTIVE = 3*/
/*};*/
/**/
/*int main() {*/
/*    // Pour un petit nombre de flags (< 32), utilisation directe*/
/*    t_booltab flags = 0;*/
/*    BIT_SET(flags, FLAG_RUNNING);*/
/*    BIT_SET(flags, FLAG_ERROR);*/
/**/
/*    printf("Running: %u\n", BIT_GET(flags, FLAG_RUNNING)); // 1*/
/*    printf("Paused: %u\n", BIT_GET(flags, FLAG_PAUSED));   // 0*/
/*    printf("Error: %u\n", BIT_GET(flags, FLAG_ERROR));     // 1*/
/*    printf("Active: %u\n", BIT_GET(flags, FLAG_ACTIVE));   // 0*/
/**/
/*    // Pour plus de 32 bits, utilisation de BoolArray*/
/*    BoolArray ba = create_bool_array(64); // 64 bits par exemple*/
/*    BA_SET(ba, 35); // Set bit 35*/
/*    BA_SET(ba, FLAG_RUNNING); // Set bit 0 (running)*/
/**/
/*    printf("Bit 35: %u\n", BA_GET(ba, 35)); // 1*/
/*    printf("Running: %u\n", BA_GET(ba, FLAG_RUNNING)); // 1*/
/**/
/*    free_bool_array(&ba); // Nettoyage*/
/*    return (0);*/
/*}*/
