/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdeckard <hdeckard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:12:27 by hdeckard          #+#    #+#             */
/*   Updated: 2021/01/06 18:25:33 by hdeckard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		op_and(t_process *process, t_corewar *corewar)
{
	int8_t		register_number;
	int32_t		argument_1;
	int32_t		argument_2;
	int32_t		result;
	int			current_pc;

	current_pc = process->pc + 2;
	argument_1 = get_int32_t_argument(corewar, process, 0, current_pc);
	current_pc += add_step(process->args[0], &g_ops[6 - 1]);
	argument_2 = get_int32_t_argument(corewar, process, 1, current_pc);
	current_pc += add_step(process->args[1], &g_ops[6 - 1]);
	register_number = get_one_byte(corewar->arena, current_pc);
	result = argument_1 & argument_2;
	process->registers[register_number - 1] = result;
	if (result == 0)
		process->flag_carry = 1;
	else
		process->flag_carry = 0;
}
