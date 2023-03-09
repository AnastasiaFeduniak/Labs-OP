#pragma once
typedef struct account {
	char author[30];
	char name[30];
	int year;
	int pages;
	int price;
	struct account* next;
} books;
 void Show(books* g);
   void swap(books*a, books*b);
   void AlphaSort(books* a);
