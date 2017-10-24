/*
* System Programming - mig-term report
* Name: Tomoki Kano
* ID: 1G151026
*
* GitHub: https://github.com/Tomoki-K/linux-commands
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFF_SIZE 1024
#define LN_COUNT 10

// 連結リストの要素
struct node {
    char line[BUFF_SIZE]; // ファイルの一行を格納する
    struct node *next_p; // 次のノードへのポインタ
};

int main(int argc, char *argv[]) {

    // ファイルを開く
    FILE *fp = fopen(argv[1], "r");
    int errnum = errno;
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
        exit(1);
    }

    // 長さ10の循環リストを定義
    struct node *head, *tmp;
    head = (struct node *) malloc( sizeof(struct node) );
    tmp = head;
    for(int i = LN_COUNT; i > 1; i--){
        tmp->next_p = (struct node *) malloc(sizeof(struct node));
        strcpy(tmp->line, "");
        tmp = tmp->next_p;
    }
    tmp->next_p = head;

    // ファイルから一行ずつ読み，循環リストにいれる．
    tmp = head;
    char buffer[BUFF_SIZE];
    while(fgets (buffer, BUFF_SIZE, fp) != NULL){
        strcpy(tmp->line, buffer);
        tmp = tmp->next_p;
    }
    fclose(fp);

    // 出力
    head = tmp;
    while(tmp->next_p != head){
        printf("%s", (tmp->line));
        tmp = tmp->next_p;
    }
    printf("%s", tmp->line);
    return 0;
}
