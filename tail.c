/*
* Tomoki Kano
* ID: 1G151026
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 1024

// 連結リストの要素
struct node {
    char line[BUFFER_SIZE]; // ファイルの一行を格納する
    struct node *next_p; // 次のノードへのポインタ
};

int main(int argc, char *argv[]) {

    FILE* pFile = fopen(argv[1], "r");
    int errnum = errno;
    if (pFile == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
        exit(1);
    }
    struct node *head, *tmp;

    // 長さ10の循環リストを定義
    head = (struct node *) malloc( sizeof(struct node) );
    tmp = head;
    for(int i = 10; i > 1; i--){
        tmp->next_p = (struct node *) malloc(sizeof(struct node));
        strcpy(tmp->line, "");
        tmp = tmp->next_p;
    }
    tmp->next_p = head;

    // ファイルから一行ずつ読み，循環リストにいれる．
    tmp = head;
    char buffer[BUFFER_SIZE];
    while(fgets (buffer, BUFFER_SIZE, pFile) != NULL){
        strcpy(tmp->line, buffer);
        tmp = tmp->next_p;
    }

    // 出力
    head = tmp;
    while(tmp->next_p != head){
        printf("%s", (tmp->line));
        tmp = tmp->next_p;
    }
    printf("%s", tmp->line);
    return 0;
}
