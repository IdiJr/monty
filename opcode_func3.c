#include "monty.h"

/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: void
 */
void _rotl(stack_t **stack, unsigned int line_numb)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)line_numb;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	aux1 = (*stack)->next;
	aux2 = *stack;

	for (; aux2->next != NULL; aux2 = aux2->next)
	;

	aux1->prev = NULL;
	aux2->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = aux2;
	*stack = aux1;
}

/**
 * _rotr - reverse the stack
 * @stack: head of the linked list
 * @line_numb: line number
 * Return: void
 */
void _rotr(stack_t **stack, unsigned int line_numb)
{
	stack_t *aux = NULL;
	(void)line_numb;

	if (*stack == NULL)
		return;

	if ((*stack)->next == NULL)
		return;

	aux = *stack;

	for (; aux->next != NULL; aux = aux->next)
	;

	aux->prev->next = NULL;
	aux->next = *stack;
	aux->prev = NULL;
	(*stack)->prev = aux;
	*stack = aux;
}
