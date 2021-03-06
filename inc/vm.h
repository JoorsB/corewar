/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:24:18 by joris         #+#    #+#                 */
/*   Updated: 2020/07/14 19:49:56 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>

# define OK     0
# define ERROR  -1

/** Head vm struct */
typedef struct		s_vm
{
	int				champ_fd[MAX_PLAYERS];
	int				champ_c;
	int				f_dump;
    int             f_n;
}					t_vm;

/** Player struct */
typedef struct s_player
{
    int id;
} t_player;

/** Additional cell information */
typedef struct s_cell
{
    char hex;
    bool taken;
} t_cell;

/** Individual cursor */
typedef struct s_cursor
{
    struct s_cursor *next;
    struct s_cursor *prev;
    int id;
    int pos;
    bool carry;
    int opcode;
} t_cursor;

/** Arena environment */
typedef struct s_arena
{
    /** Linked list of cursors */
    t_cursor *cursors;

    /** Individual player structs */
    t_player players[MAX_PLAYERS + 1];

    /** Amount of players */
    int player_count;

    /** Individual cell structs */
    t_cell cells[MEM_SIZE];

    /** Raw memory array of arena */
    char mem[MEM_SIZE];

    /** Current winner player id */
    int winner_id;

    /** Cycles before we die */
    int cycles_to_die;

    /** Current count of cycles past */
    int cylces_count;

    /** Check counter */
    int check_count;

    /** Operations */
    op_t op_tab[17];
} t_arena;

int			check_args(int argc, char **argv, t_vm *vm_s);

#endif