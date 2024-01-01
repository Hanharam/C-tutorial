#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode{
    ElementType Data;
    struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node**Head, Node* NewNode);     //"Node*" 가 아닌 "Node**" 의 이유 'List포인터 변수의 주소를 전달해야함'
void SLL_InsertAfter(Node* Current,Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewHead);
void SLL_RemoveNode(Node** Head,Node* Remove);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);



//노드 생성
Node* SLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->NextNode = NULL;
    NewNode->Data = NewData;

    return NewNode;
}

//노드 소멸
void SLL_DestroyNode(Node* Node){
    free(Node);
}

//노드 추가
void SLL_AppendNode(Node** Head,Node* NewNode){
    if(*Head == NULL){
        *Head = NewNode;
    }
    else{
        Node* Tail = *Head;

        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }
        Tail->NextNode = NewNode;
    }
}

//노드 삽입
void SLL_InsertAfter(Node* Current,Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    Current->NextNode = NewNode;
}

//노드 head에 추가
void SLL_InsertNewHead(Node** Head, Node* NewHead){
    if(*Head == NULL){
        *Head = NewHead;
    }
    else{
        NewHead->NextNode = (*Head);    //*Head를 NewHead로 바꾸기위한 빌드업
        (*Head) = NewHead;     //*Head는 항상 맨 앞이다. NewNode를 *Head 처럼 만들고 Head에 삽입한다.
    }
}

//노드 제거
void SLL_RemoveNode(Node** Head,Node* Remove){
    if(*Head == Remove){
        (*Head) = Remove->NextNode;
    }
    else{
        Node* Current = (*Head);
        while(Current != NULL && Current->NextNode != Remove){
            Current = Current->NextNode;
        }
        if(Current != NULL){
            Current->NextNode = Remove->NextNode;
        }
    }
}

//노드 탐색
Node* SLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;

    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }

    return Current;
}

//노드 개수 세기
int SLL_GetNodeCount(Node* Head){
    int cnt =0;
    Node* Current = Head;
    while(Current != NULL){
        Current = Current->NextNode;
        cnt++;
    }
    return cnt;
}

//List 포인터가 담고있는 '주소값'만 _Head에 복가되고 정작 List포인터 변수의 주소는 전달되지 않은 것이다.