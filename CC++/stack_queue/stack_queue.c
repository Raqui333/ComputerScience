#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int top;
    int max;
    int* item;
} Stack;

void push_pilha(Stack* p, int n) {
    if (p->top >= p->max) exit(-1);
    p->top++;
    p->item[p->top] = n;
}

void print_pilha(Stack* p) {
    printf("%d\n", p->item[p->top]);
}

void pop_pilha(Stack* p) {
    if (p->top <= -1) exit(-1);
    p->top--;
}

int main() {
    Stack pilha = {-1, 5, (int*) malloc(5 * sizeof(int))};
    push_pilha(&pilha, 20);
    print_pilha(&pilha);
    pop_pilha(&pilha);
    pop_pilha(&pilha);
    print_pilha(&pilha);

    return 0;
}
