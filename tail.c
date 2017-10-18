/*
* Tomoki Kano
* ID: 1G151026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1028

struct node {
	char line[BUFFER_SIZE];
	struct node *next_p;
};

int main(int argc, char *argv[]) {

    FILE* pFile = fopen(argv[1], "r");
    struct node *head, *tmp;

	head = (struct node *) malloc( sizeof(struct node) );

    tmp = head;
	for(int i = 10; i > 1; i--){
		tmp->next_p = (struct node *) malloc(sizeof(struct node));
		strcpy(tmp->line, "");
		tmp = tmp->next_p;
	}
	tmp->next_p = head;

    tmp = head;
    char buffer[BUFFER_SIZE];
    while(fgets (buffer, BUFFER_SIZE, pFile) != NULL){
        strcpy(tmp->line, buffer);
        tmp = tmp->next_p;
    }

	head = tmp;
	while(tmp->next_p != head){
		printf("%s", (tmp->line));
		tmp = tmp->next_p;
	}
	printf("%s", tmp->line);
	return 0;
}
