#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_numb: line number
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int line_numb)
{
	int i, j;

	if (vglo.arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (j = 0; vglo.arg[j] != '\0'; j++)
	{
		if (!isdigit(vglo.arg[j]) && vglo.arg[j] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_numb);
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(stack, i);
	else
		add_dnodeint_end(stack, i);
}

/**
 * _pall - prints all values on the stack
 * @stack: head of the linked list
 * @line_number: line numbers
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *stack;

	while (aux != NULL)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: head of the linked list
 * @line_numb: line number
 * Return: void
 */
void _pint(stack_t **stack, unsigned int line_numb)
{
	(void)line_numb;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: head of the linked list
 * @line_numb: line number
 *
 * Return: void
 */
void _pop(stack_t **stack, unsigned int line_numb)
{
	stack_t *aux;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(aux);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: head of the linked list
 * @line_numb: line number
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int line_numb)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *stack;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_numb);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *stack;
	*stack = (*stack)->next;
	aux->next = (*stack)->next;
	aux->prev = *stack;
	(*stack)->next = aux;
	(*stack)->prev = NULL;
}
