/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** redirector
*/

#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "proto.h"
#include "macro.h"
#include "proto_lib.h"

int file_function(base_minishell_t *base, need_tab_t *need_tab, int *x)
{
    char **tab_command = NULL;
    if (base == NULL || need_tab == NULL)
        return KO;
    tab_command = my_splitstr(base->p_command[need_tab->tab_pos_y]\
    [need_tab->tab_pos_x], ' ');
    if (need_tab->redirect_arg == 2){
        need_tab->redirect_arg = 0;
        if (right_redirector(base, need_tab, tab_command) != OK){
            base->return_value = 1;
            return OK;
        }
    }
    if (need_tab->redirect_arg == 1){
        base->yes_or_not = 0;
        if (command(base, need_tab, tab_command) != OK){
            return OK;
        }
        *x += 2;
    }
    return OK;
}