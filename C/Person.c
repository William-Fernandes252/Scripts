#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Class struct

Class Person {
    char name[10];
    int age;
    int height;
    void(*show)(Class Person *);
};

void print_person(Class Person *person) {
    printf("Name: %s\nAge: %d\nHeight: %d\n", person->name, person->age, person->height);
}

Class Person * newPerson(char name[], int age, int height) {
    Class Person *self = (Class Person*) malloc(sizeof(Class Person));
    strcpy(self->name, name);
    self->age = age;
    self->height = height;
    self->show = &print_person;
    return self;
}

int main(int argc, char **argv) {
    Class Person *person = (Class Person*) newPerson("William", 19, 180);
    person->show(person);
    return 0;
}