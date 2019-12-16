#include <stdlib.h>
#include <stack.h>

STACK *stack_create() {
	return (STACK *) calloc(1, sizeof(STACK));
}

int stack_push(STACK *stack, void *elem) {
	if (!stack) return INVALID_STACK;
	STACK_ELEMENT *e = 
		(STACK_ELEMENT *) malloc(sizeof(STACK_ELEMENT));
	e->elem = elem;
	e->next = stack->top;
	stack->top = e;
	stack->counter++;

	return SUCCESS;
}

void *stack_pop(STACK *stack, int *error) {
	if (!stack) {
		*error = INVALID_STACK;
		return NULL;
	}

	if (!stack->counter) {
		*error = EMPTY_STACK;
		return NULL;
	}

	void *e;
	STACK_ELEMENT *elem = stack->top;
	stack->top = elem->next;
	e = elem->elem;
	free(elem);
	stack->counter--;

	*error = SUCCESS;
	return e;
}

void *stack_top(STACK *stack, int *error) {
	if (!stack) {
		*error = INVALID_STACK;
		return NULL;
	}

	if (!stack->counter) {
		*error = EMPTY_STACK;
		return NULL;
	}

	*error = SUCCESS;
	return stack->top->elem;
}

int stack_size(STACK *stack) {
	if (!stack) return INVALID_STACK;
	return stack->counter;
}

int stack_free(STACK *stack) {
	if (!stack) return INVALID_STACK;
	int i;
	STACK_ELEMENT *e;
	for (i = 0; i < stack->counter; i++) {
		e = stack->top;
		stack->top = e->next;
		free(e);
	}
	free(stack);
	return SUCCESS;
}





