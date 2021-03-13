#ifndef TOKENS_H
#define TOKENS_H

typedef enum {op_assign, op_assign_sum, op_assign_sub, op_assign_mult, op_assign_div, op_assign_conj_union, op_assign_conj_intersection, op_log_or, op_log_and, op_log_lte, op_log_gte, op_log_equal, op_log_diff, op_mod, parenteses_esquerda, parenteses_direita, op_mult, op_div, op_sum, op_sub, virgula, ponto, 
	op_conj_intersection, op_conj_union, booleano, inteiro, real, caractere, palavra, id, 
	key_bool, key_caractere, key_set, key_continue, key_while, key_out, key_int, key_read, key_for, key_in, key_break, key_string, key_main, key_if, key_else, key_real, key_register, key_return, key_return_nothing, eof,
	key_def, key_deftipo, key_for_set, key_vetor} Token;

#endif