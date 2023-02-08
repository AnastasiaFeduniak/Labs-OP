#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
void Show(books* g) {
    printf("----------------------------------------------------------------------------------\n");
    printf("|         Author                |         Title         |  Year  | Pages | Price | \n");
    printf("----------------------------------------------------------------------------------\n");
    do {
        printf("|\t%20s\t|%20s\t| %d\t | %d\t |  %d\t |\n", g->author, g->name, g->year, g->pages, g->price);
        g = g->next;
    } while (g != NULL);
    printf("----------------------------------------------------------------------------------\n");
}
void swap(books* a, books* b) {
    int tmp = a->year;
    a->year = b->year;
    b->year = tmp;
    tmp = a->pages;
    a->pages = b->pages;
    b->pages = tmp;
    tmp = a->price;
    a->price = b->price;
    b->price = tmp;
    char ctmp[30];
    strcpy(ctmp, a->author);
    strcpy(a->author, b->author);
    strcpy(b->author, ctmp);
    strcpy(ctmp, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, ctmp);
}
void AlphaSort(books* a) {
    books* pointer = a;
    books* pointer_a = a;
    books* pointer_b = a;
    while (pointer_a->next != NULL){
            pointer_b = a;
            while (pointer_b->next != NULL){
            if (strcmp(pointer_a->name, pointer_b->name) < 0) {
                swap(pointer_a, pointer_b);
            }
            pointer_b = pointer_b->next;
        }
        pointer_a = pointer_a->next;
    }


}