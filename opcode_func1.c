#include "monty.h"

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: no return
 */
void _queue(stack_t **stack, unsigned int line_numb)
{
	(void)stack;
	(void)line_numb;

	vglo.lifo = 0;
}

/**
 * _stack - sets the format fo the data to a stack (LIFO)
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: no return
 */
void _stack(stack_t **stack, unsigned int line_numb)
{
	(void)stack;
	(void)line_numb;

	vglo.lifo = 1;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: no return
 */
void _add(stack_t **stack, unsigned int line_numb)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n += (*stack)->n;
	_pop(stack, line_numb);
}

/**
 * _nop - doesn't do anythinhg
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: no return
 */
void _nop(stack_t **stack, unsigned int line_numb)
{
	(void)stack;
	(void)line_numb;
}

/**
 * _sub - subtracts the top element to the second top element of the stack
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: no return
 */
void _sub(stack_t **stack, unsigned int line_numb)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n -= (*stack)->n;
	_pop(stack, line_numb);
}
