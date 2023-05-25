#include "monty.h"

/**
 * _div - divides the second element by the top element of the stack
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_numb)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n /= (*stack)->n;
	_pop(stack, line_numb);
}

/**
 * _mul - multiplies the top element to the second top element of the stack
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int line_numb)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n *= (*stack)->n;
	_pop(stack, line_numb);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int line_numb)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->next;
	aux->n %= (*stack)->n;
	_pop(stack, line_numb);
}

/**
 * _pchar - print the char value of the first element
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: void
 */
void _pchar(stack_t **stack, unsigned int line_numb)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string of the stack
 * @stack: head of the linked list
 * @line_numb: line number;
 *
 * Return: void
 */
void _pstr(stack_t **stack, unsigned int line_numb)
{
	stack_t *aux;
	(void)line_numb;

	aux = *stack;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
