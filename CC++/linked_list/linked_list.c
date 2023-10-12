#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List {
  char name[16];
  int year;
  struct List *next;
  struct List *prev;
} List;

void l_add(List **list, char *name, int year) {
  List *tmp = (List *)malloc(sizeof(List));
  strcpy(tmp->name, name);
  tmp->year = year;
  tmp->prev = NULL;
  tmp->next = *list;
  (*list)->prev = tmp;
  *list = tmp;
}

void l_print(List *list) {
  while (list != NULL) {
    printf("Name: %s\nYold: %d\nPrev: %s\nNext: %s\n\n", list->name, list->year,
           list->prev->name, list->next->name);
    list = list->next;
  }
}

int main() {
  List *mlist = (List *)malloc(sizeof(List));
  strcpy(mlist->name, "Joao");
  mlist->year = 10;

  l_add(&mlist, "Foo", 12);
  l_add(&mlist, "Bar", 9);

  l_print(mlist);

  return 0;
}
