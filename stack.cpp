// Copyright (c) [2023] [Harsh Gautam]

#include <iostream>

int size = 0;
const int MAX = 10;

struct stack {
  int items[MAX];
  int top;
};

void createEmptyStack(stack *s) { s->top = -1; }

int isFull(stack *s) {
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

int isEmpty(stack *s) {
  if (s->top == -1)
    return 1;
  else
    return 0;
}

void push(stack *s, int newitem) {
  if (isFull(s)) {
    std::cout << "stack is full" << std::endl;
    return;
  } else {
    s->top++;
    s->items[s->top] = newitem;
    size++;
  }
}

void pop(stack *s) {
  if (isEmpty(s)) {
    std::cout << "stack is empty";
  } else {
    std::cout << "popped value " << s->items[s->top];
    s->items[s->top] = 0;
    s->top--;
    size--;
  }
  std::cout << std::endl;
}

void printStack(stack *s) {
  if (isEmpty(s)) {
    std::cout << "stack is empty";
  } else {
    for (const int &item : s->items) {
      std::cout << item << " ";
    }
  }
  std::cout << std::endl;
}

int main() {
  int ch;
  stack *st = reinterpret_cast<stack *>(malloc(sizeof(stack)));

  createEmptyStack(st);
  push(st, 1);
  push(st, 2);
  push(st, 3);
  push(st, 4);
  push(st, 5);

  printStack(st);

  pop(st);
  pop(st);
  pop(st);

  printStack(st);
  return 0;
}
