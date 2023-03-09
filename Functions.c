#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
  void Show(books* g){
    printf("----------------------------------------------------------------------------------\n");
		printf("|         Author                |         Title         |  Year  | Pages | Price | \n");
		printf("----------------------------------------------------------------------------------\n");
		do {
			printf("|\t%20s\t|%20s\t| %d\t | %d\t |  %d\t |\n", g->author, g->name, g->year, g->pages, g->price);
		    g = g->next;
		} while(g != NULL);
		printf("----------------------------------------------------------------------------------\n");
  }
  void swap(books*a, books*b){
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
    do{
            pointer_b = a;
            do{
            if (strcmp(pointer_a->name, pointer_b->name) < 0) {
                swap(pointer_a, pointer_b);
            }
            pointer_b = pointer_b->next;
        } while (pointer_b);
        pointer_a = pointer_a->next;
    } while (pointer_a);
}

void ThreeMax(books*a){
    books*rem;
    books*rem1;
    books*max;
    int ch = 0;
    int f = 100000;
    printf("----------------------------------------------------------------------------------\n");
		printf("|         Author                |         Title         |  Year  | Pages | Price | \n");
		printf("----------------------------------------------------------------------------------\n");
    while(ch != 3){
        rem = a;
        max = a;
        do{
            if(max->price < rem->price && rem->price < f){
                max = rem;
                rem1 = rem;
            }
            rem = rem->next;
        }while(rem);
            f = max->price;

        printf("|\t%20s\t|%20s\t| %d\t | %d\t |  %d\t |\n", rem1->author, rem1->name, rem1->year, rem1->pages, rem1->price);
        ch++;
    }
        	printf("----------------------------------------------------------------------------------\n");

}
void Delete_D(books* a, int s){
    for(int i = 0; i < s; i++){
    books*previous = NULL;
    books*current = a;
   while(current){
       if(current->name[0] == 'D'){
           previous->next = current->next;
           free(current);
           current = previous->next;
           break;
       }
       previous = current;
       current = current->next;
   }
    
    }
}

void AddBooks(books*a){
    int check;
    printf("Enter \"0\" if you want to add new book to the list, in other case any other number: \n");
    scanf(" %d", &check);
    while(check == 0){
        books*ch = a, *prev = a;
        books* tmp = (books*)malloc(sizeof(books));
        printf("Enter the name of author: ");
        getchar();
        gets(tmp->author);
        printf("\nEnter the name of a book: ");
        gets(tmp->name);
         printf("\nEnter a year of publication: ");
         scanf("%d", &tmp->year);
         printf("\nEnter a number of pages: ");
         scanf("%d", &tmp->pages);
         printf("\nEnter a price: ");
         scanf("%d", &tmp->price);
        while(ch){
         if(strcmp(tmp->name, ch->name) < 0) {
             tmp->next = ch;
             prev->next = tmp;
             break;
         }  
            prev = ch;
            ch = ch->next;
        }
         printf("Enter \"0\" if you want to add new book to the list, in other case any other number: ");
     scanf(" %d", &check);
    }
            Show(a);
}
