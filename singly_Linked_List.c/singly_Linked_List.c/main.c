#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode
{
    char data[4]; //데이터필드
    struct ListNode *link; //링크필드
}listNode;

typedef struct{
    listNode *head; // 리스트의 시작을 나타내는 Head노드
}linkedList_h;

linkedList_h* createLinkedList_h(void) // 공백 연결 리스트 생성
{
    linkedList_h* L; //구조체 포인터 L
    L = (linkedList_h*)malloc(sizeof(linkedList_h)); // 동적할당, 노드 생성
    L -> head = NULL; // 공백리스트니까 NULL저장
    return L;
}

void freeLinkedList_h(linkedList_h* L) // 연결리스트의 전체 메모리를 해제하는 연산
{
    listNode *p;
    while(L->head != NULL) // 리스트가 마지막을 가리킬때까지 반복
    {
        p = L->head;  // 포인터 p를 시작 노드를 가르키게 해줌
        L->head = L->head->link; //시작 노드가 가르키는 노드의 링크를 따라 다음 노드로 이동
        free(p); // p가 가르키는 노드 해제
        p = NULL; // p의 값 NULL;
    }
}

void printlist(linkedList_h *L)
{
    listNode* p;
    printf("L = (");
    p = L -> head; // 포인터 p를 시작 노드를 가르키게 해줌
    while(p != NULL)
    {
        printf("%s", p ->data); // p가 가르키는 노드의 데이터 값 출력
        p = p->link; // 링크따라 이동
        if(p != NULL)   printf(", ");
    }
    
    printf(") \n");
    
}


void insertFirstNode(linkedList_h *L, char *x)
{
    listNode* newNode; // 삽입할 새 노드 생성
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x); // 노드에 데이터 값에 문자열 복사
    newNode -> link = L -> head; // 첫번 째 노드가 가르키고 있었던 링크 값을 새로운 노드에 복사
    L -> head = newNode; // 첫번 쨰 노드니 헤드 포인터가 새 노드를 가르키게 설정
}

void insertMiddleNode(linkedList_h *L, listNode *pre, char *x)
{
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    if(L == NULL) // 공백 리스트일 경우
    {
        newNode -> link = NULL; // 삽입 노드의 링크 필드 NULL
        L -> head = newNode; // 새 노드를 첫번쨰 노드로
    }
    
    else if(pre == NULL)
    {
        L->head = newNode;
        newNode -> link = pre;
    }
    
    else
    {
        newNode -> link = pre -> link;
        pre -> link = newNode;
        
    }
}

void insertLastNode(linkedList_h *L, char *x)
{
    listNode* newNode;
    listNode* temp; // 탐색을 위한 포인터
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    newNode -> link = NULL; // 마지막 노드이니 링크 필드를 NULL로 설정
    if(L -> head == NULL) // 노드가 공백 리스트일 경우
    {
        L ->head = newNode;
    }
    
    else
    {
        temp = L ->head; // 탐색 포인터를 시작에 위치 시킴
        while(temp -> link != NULL) temp = temp -> link; // 마지막을 탐색
        temp -> link = newNode; // 마지막 노드의 링크 필드를 삽입 노드의 주소로 설정
    }
}

void deleteNode(linkedList_h *L, listNode *p)
{
    listNode* pre;
    if(L->head == NULL) return;
    if(L ->head->link == NULL)
    {
        free(L->head);
        L->head = NULL;
        return;
    }
    else if(p == NULL) return;
    else
    {
        pre = L -> head;
        while(pre -> link != p)
        {
            pre = pre -> link;
        }
        pre -> link = p -> link;
        free(p);
    }
}

listNode* searchNode(linkedList_h *L, char* x)
{
    listNode *temp;
    temp = L->head;
    while(temp != NULL)
    {
        if(strcmp(temp->data, x) == 0)  return temp;
        else temp = temp -> link;
    }
    
    return temp;
}

void reverse(linkedList_h *L)
{
    listNode *p;
    listNode *q;
    listNode *r;
    
    p = L->head;
    q = NULL;
    r = NULL;
    
    while(p != NULL)
    {
        r=q;
        q=p;
        p = p->link;
        q->link = r;
    }
    L -> head = q;
}
int main()
{
    linkedList_h *L;
    listNode *p;
    L = createLinkedList_h();
    printlist(L);
    
    insertFirstNode(L, "수");
    insertLastNode(L, "금");
    insertFirstNode(L, "월");

    p = searchNode(L, "수");
    printf("%s를 찾았습니다.",p ->data);
    insertMiddleNode(L, p, "토");
    printlist(L);
    p = searchNode(L, "금");
    deleteNode(L, p);
    reverse(L);
    printlist(L);
    
    getchar();
    
    return 0;
}
