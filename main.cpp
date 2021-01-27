#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <cmath>
#include <vector>
/*
int main() {
	int a;
	double b;

	char str[] = "The world!";
	printf("PI = %.48lf\n", M_PI);
	printf("int = %d\n", 10);
	printf("str = %s\n", str);
	printf("oct = %o\n", 10);
	printf("hex = %x\n", 10);
	
	scanf("%d", &a);
	printf("a = %d", a);
	scanf("%lf", &b);
	printf("b = %.0lf", b);
	return 0;
} 
*/

struct Book
{
	char title[100];
	char author[150];
	int pageNumber;
	float price;
};

int writeFile(char fname[], Book books[], int size);
int readFile(char fname[], std::vector<Book>& books);
void printBooks(std::vector<Book>& books);


int main() {
	char fileName[] = "Books.txt";

	const int size = 3;
	Book books[] = {
		{"dont give banana monkey", "Uvuvwevwevwe Onyetenyevwe Ugwemuhwem Osas", 10000 , 9999},
		{"Project Venus", "Jacque Fresko", 228, 337},
		{"OBAMA", "OBAMA", 0, 0}
	};

	printf("Writing data to the file %s . . .\n", fileName);
	writeFile(fileName, books, size);
	int err_no = writeFile(fileName, books, size);
	if (err_no == 1) {
		printf("Error while opening file!\n");
		return 1;
	}
	if (err_no == 1) {
		printf("Error while closing file!\n");
		return 2;
	}

	std::vector<Book> newBooks;

	printf("Reading data from the file and destroy you computer %s . . .\n", fileName);
	err_no = readFile(fileName, newBooks);
	if (err_no == 1) {
		printf("Error while opening file!\n");
		return 1;
	}
	if (err_no == 1) {
		printf("Error while closing file!\n");
		return 2;
	}
	printBooks(newBooks);

	return 0;
}

int writeFile(char fname[], Book books[], int size)
{
	FILE* f;

	f = fopen(fname, "w");
	
	if (f == NULL) {
		return 1;
		printf("Error while opening file '-'\n");
	}

	for (int i = 0; i < size; i++) {
		fprintf(f, "%s|%s|%d|%.2f\n", books[i].title, books[i].author, books[i].pageNumber, books[i].price);
	}

	if (fclose(f) != NULL) {
		return 2;
	}

		

	return 0;
}

int readFile(char fname[], std::vector<Book>& books)
{
	FILE* f;

	f = fopen(fname, "r");
	if (f == NULL) {
		return 1;
	}

	char buff[690];
	
	while (fgets(buff, 690, f) != NULL) {
		Book b;
		printf("%s", buff);

		// title
		char* subStr = strtok(buff, "|\n");
		strcpy(b.title, subStr);

		// author, NULL работаем с той же строкой
		subStr = strtok(NULL, "|\n");
		strcpy(b.author, subStr);
		// page number
		subStr = strtok(NULL, "|\n");
		int pageNumber = atoi(subStr);
		b.pageNumber = pageNumber;
		// price
		subStr = strtok(NULL, "|\n");
		float price = atof(subStr);
		b.price = price;

		books.push_back(b);
		//push_back положить назат. //vector
	}

	fclose(f);
	return 0;
}

void printBooks(std::vector<Book>& books)
{
	for (int i = 0; i < books.size(); i++) {
		printf("Title: %s, Author: %s, Page number: %d, Price: %f\n", books[i].title, books[i].author, books[i].pageNumber, books[i].price);
	}
}
