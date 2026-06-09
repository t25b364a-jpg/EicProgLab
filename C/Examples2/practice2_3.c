/*
 * practice2_3.c
 *
 * プログラミングBI 演習課題2-3
 * 
 * 線形リストを使った挿入と削除
 *
 */ 
#include <stdio.h>
#include <stdlib.h>

/* ノード構造体 */
typedef struct Node {
    int value;
    struct Node* next;
} Node;

/* 関数プロトタイプ */
Node* insertSorted(Node* head, int value);
Node* deleteValue(Node* head, int value);
void printList(Node* head);
void freeList(Node* head);

int main(void)
{
    Node* head = NULL;
    int mode = 0;
    int value;

    while (mode != 3) {
        printf("\n--- メニュー ---\n");
        printf("1: 挿入（昇順）\n");
        printf("2: 削除\n");
        printf("3: 終了\n");
        printf("選択: ");
        scanf("%d", &mode);

        if (mode == 1) {
            printf("挿入する値: ");
            scanf("%d", &value);
            head = insertSorted(head, value);
            printList(head);
        }
        else if (mode == 2) {
            printf("削除する値: ");
            scanf("%d", &value);
            head = deleteValue(head, value);
            printList(head);
        }
        else if (mode != 3) {
            printf("これは無効な入力です。\n");
        }
    }

    freeList(head);
    return 0;
}

/* 昇順に挿入する関数 */
Node* insertSorted(Node* head, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    /* 先頭に挿入すべき場合 */
    if (head == NULL || value < head->value) {
        newNode->next = head;
        return newNode;
    }

    /* 挿入位置を探す */
    Node* element = head;
    while (element->next != NULL && element->next->value < value) {
        element = element->next;
    }

    /* 挿入 */
    newNode->next = element->next;
    element->next = newNode;

    return head;
}

/* 指定した値を削除する関数 */
Node* deleteValue(Node* head, int value)
{
    if (head == NULL) return head;

    /* 先頭が削除対象 */
    if (head->value == value) {
        Node* Element = head->next;
        free(head);
        return Element;
    }

    Node* element = head;
    while (element->next != NULL && element->next->value != value) {
        element = element->next;
    }

    if (element->next != NULL) {
        Node* Element = element->next;
        element->next = Element->next;
        free(Element);
    }

    return head;
}

/* リストの表示 */
void printList(Node* head)
{
    printf("リスト: ");
    Node* element = head;
    while (element != NULL) {
        printf("%d ", element->value);
        element = element->next;
    }
    printf("\n");
}

/* 全ノード解放 */
void freeList(Node* head)
{
    Node* element = head;
    while (element != NULL) {
        Node* next = element->next;
        free(element);
        element = next;
    }
}
