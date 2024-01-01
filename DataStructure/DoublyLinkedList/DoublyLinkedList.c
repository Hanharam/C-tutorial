#include "DoublyLinkedList.h"

Node* DLL_CreateNode(ElementType NewData){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->Data = NewData;
    NewNode->NextNode = NULL;
    NewNode->PrevNode = NULL;

    return NewNode;    
}

void DLL_DestroyNode(Node* Node){
    free(Node);
}

void DLL_AppendNode(Node** Head, Node* NewNode){
    if(*Head == NULL){
        (*Head) = NewNode;
    }
    else{
        Node* Tail = (*Head);
        while(Tail->NextNode != NULL){
            Tail = Tail->NextNode;
        }    
        Tail->NextNode = NewNode;
        NewNode->PrevNode = Tail;
    }
}

Node* DLL_GetNodeAt(Node* Head, int Location){
    Node* Current = Head;
    while(Current != NULL && (--Location) >= 0){
        Current = Current->NextNode;
    }
    return Current;
}

void DLL_RemoveNode(Node** Head, Node* Remove){
    if(*Head == Remove){ //*Head를 Remove로 할당한 후 *Head의 PrevNode를 NULL로 바꿈
        (*Head) = Remove->NextNode;
        if((*Head) != NULL){
            (*Head)->PrevNode == NULL;
        }

        Remove->NextNode == NULL;
        Remove->PrevNode == NULL;
    }
}

void DLL_InsertAfter(Node* Current, Node* NewNode){
    NewNode->NextNode = Current->NextNode;
    NewNode->PrevNode = Current;

    if(Current->NextNode != NULL){
        Current->NextNode->PrevNode = NewNode;
        Current->NextNode = NewNode;
    }
}

ElementType DLL_GetNodeCount(Node* Head){
    unsigned int Count = 0;
    Node* Current = Head;

    while(Current != NULL){
        Current = Current->NextNode;
        Count++;
    }
    return Count;
}

