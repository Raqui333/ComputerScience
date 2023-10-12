#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_SIZE 128

typedef struct Person {
    int id;
    int yo;
    char* name;
} Hash;

void add_person(Hash** h, char* n, int i, int id) {
    int addr = id % DB_SIZE;
    while (h[addr] != NULL) addr++;
    h[addr] = (Hash*) malloc(sizeof(Hash));
    h[addr]->id = id, h[addr]->yo = i;
    h[addr]->name = (char*) malloc(strlen(n) * sizeof(char));
    strcpy(h[addr]->name, n);
}

void print_person(Hash** h, int id) {
    printf("Pessoa com id \e[1;32m%d\e[00m:\n", id);
    for (int addr = id % DB_SIZE; h[addr] != NULL; addr++) {
        if (h[addr]->id == id)
            printf("Nome: %s\nIdade: %d\n\n", h[addr]->name, h[addr]->yo);
    }
}

int main() {
    Hash** db = (Hash**) malloc(DB_SIZE * sizeof(Hash*));
    add_person(db, "Foo", 21, 6102023);
    add_person(db, "Bar", 22, 6102023);
    add_person(db, "Foobar", 22, 7102023);
    print_person(db, 6102023);
    print_person(db, 7102023);
    return 0;
}
