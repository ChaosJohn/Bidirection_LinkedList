/**
 * author : chaos
 * time   : 2014-03-02
 */ 

#ifndef _BI_LINKED_LIST_NODE_H_ 
#define _BI_LINKED_LIST_NODE_H_ 
/**
 * The definition of bidirection linked list node
 */

typedef int elemtype; 


typedef struct _BiLinkedListNode {
  elemtype content; 
  struct _BiLinkedListNode *prev; 
  struct _BiLinkedListNode *next; 
} BiLinkedListNode, *BiLinkedList; 

#endif 
