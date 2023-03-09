#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Header.h"
static books * book = NULL;

int main(void){
	FILE* fp;
	fp = fopen("List.txt", "r");
	if (fp == NULL) {
		printf("dorime\n");
	}	else {
	    char ch[200];
		char* h;
		int i = 0;
		char lim[] = ",";
	    	while (fgets(ch, 200, fp))	{
			 books *new = (books*)malloc(sizeof(books));
             strcpy(new->author, strtok(ch, lim));
             strcpy(new->name, strtok(NULL, lim));
             int l = 0;
             while (h = strtok(NULL, lim))
             {
             if (l == 0) new->year = atoi(h);
             if (l == 1) new->pages = atoi(h);
             if (l == 2) new->price = atoi(h);
                 l++;}
 
                 i++;
	    	    books* current = book;
	    	    if(!(book)){
	    	        book = new;
	    	        book->next = NULL;
	    	    } else {
	    	        while (current->next){
	    	            current = current->next;
	    	        }
	    	        current->next = new;
	    	        new->next = NULL;
	    	    }
	    	    
	    	}
	    	if (book == NULL) {return 0;}
	    	printf("Original list\n");
	    	Show(book);
	    	printf("Alphabetically sorted list\n");
	    	AlphaSort(book);
	    	Show(book);
	    	printf("List of the most expensive books\n");
	    	ThreeMax(book);
	    	printf("List without books name of whose title begins from letter \"D\"\n");
	    	Delete_D(book, i);
	    	Show(book);
	    	AddBooks(book);
	       
	    	fclose(fp);
}
	   
}
