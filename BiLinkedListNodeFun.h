/**
 * author : chaos
 * time   : 2014-03-02
 */ 

#ifndef _BI_LINKED_LIST_NODE_FUN_H_ 
#define _BI_LINKED_LIST_NODE_FUN_H_ 
#include "BiLinkedListNode.h" 

/**
 * initialize the bidirection linked list with first node 
 */
void 
initList(BiLinkedList *list, 
    elemtype content);

/**
 * insert one node into the bidirection linked list in the position of specified index 
 */
int 
insert(BiLinkedList *list, 
    BiLinkedListNode *node, 
    int index); 

/**
 * create a new node with content 
 */ 
BiLinkedListNode *
createNode(elemtype content); 

/**
 * append one node to the end of the bidirection linked list 
 */
void 
appendTail(BiLinkedList *list, 
    BiLinkedListNode *node); 

/**
 * append one node to the beginning of the bidirection linked list 
 */
void 
appendHead(BiLinkedList *list, 
    BiLinkedListNode *node); 

/**
 * delete one node of specified index and return the node 
 */
elemtype 
delete(BiLinkedList *list, 
    int index); 


/**
 * calculate the length of bidirection linked list 
 */
int getSize(BiLinkedList list); 

/**
 * print the whole list 
 */ 
void printList(BiLinkedList list); 

#endif 
