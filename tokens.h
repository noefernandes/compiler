#ifndef TOKENS_H
#define TOKENS_H

typedef enum {
	assign, 
	assign_sum, 
	assign_sub, 
	assign_mult, 
	assign_div, 
	assign_set_union, 
	assign_set_intersection, 
	op_not,
	op_or,
	op_and, 
	op_gt,
	op_lt,
	op_lte, 
	op_gte, 
	op_equal, 
	op_diff, 
	op_mod, 
	parenteses_esquerda, 
	parenteses_direita, 
	op_mult, 
	op_div, 
	op_sum, 
	op_sub, 
	virgula, 
	ponto, 
	set_intersection, 
	set_union, 
	key_bool, 
	key_caractere, 
	key_set,
	key_vetor,
	key_continue, 
	key_while, 
	key_out, 
	key_int, 
	key_read, 
	key_for, 
	key_for_set,
	key_in, 
	key_break, 
	key_string, 
	key_main, 
	key_if, 
	key_else, 
	key_real, 
	key_register, 
	key_return, 
	key_return_nothing, 
	key_def, 
	key_deftipo, 
	key_for_set, 
	key_vetor,

	booleano, 
	inteiro, 
	real, 
	caractere, 
	palavra, 
	id, 

	TExpressao, 
	TExpA, 
	TExpA1,

	eof
} Token;

#endif
