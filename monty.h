#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct MontyContext
{
    char *argument;
    FILE *file;
    char *file_content;
    int last_in_first_out;
} MontyContext_t;

extern MontyContext_t monty_con;


void st_pall(stack_t **entry, unsigned int shelf);
void st_push(stack_t **entry, unsigned int shelf);
void stack_remover(stack_t *entry);
void new_node(stack_t **entry, int value);
void new_queue(stack_t **entry, int value);
void execute_bytecode(char *content, stack_t **entry, unsigned int line_number, FILE *file);
char *read_file_content(FILE *file);
void st_pop(stack_t **entry, unsigned int shelf); 
void st_swap(stack_t **entry, unsigned int shelf);
void st_add(stack_t **entry, unsigned int shelf); 
void st_nop(stack_t **entry, unsigned int shelf); 
void st_sub(stack_t **entry, unsigned int shelf); 
void st_div_op(stack_t **entry, unsigned int shelf); 
void st_mul(stack_t **entry, unsigned int shelf); 
void st_mod(stack_t **entry, unsigned int shelf); 
void st_pchar(stack_t **entry, unsigned int shelf); 
void st_pstr(stack_t **entry, unsigned int shelf); 
void st_rotl(stack_t **entry, unsigned int shelf);


#endif
