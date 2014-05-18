/**
 * author : chaos
 * time   : 2014-03-02
 */ 

#include "BiLinkedListNodeFun.h" 
#include "BiLinkedListNode.h" 
#include <stdio.h> 
#include <stdlib.h> 

/**
 * initialize the bidirection linked list with first node 
 */
void 
initList(BiLinkedList *list, 
    elemtype content) {
  (*list) = (BiLinkedListNode *)malloc(sizeof(BiLinkedListNode)); 
  (*list)->content = content; 
  (*list)->prev = NULL; 
  (*list)->next = NULL; 
}

/**
 * create a new node with content 
 */ 
BiLinkedListNode *
createNode(elemtype content) {
  BiLinkedListNode *node = (BiLinkedListNode *)malloc(sizeof(BiLinkedListNode)); 
  node->next = NULL; 
  node->prev = NULL; 
  node->content = content; 
  return node; 
}

/**
 * insert one node into the bidirection linked list in the position of specified index 
 */
int  
insert(BiLinkedList *list, 
    BiLinkedListNode *node, 
    int index) {
  int size = getSize(*list); 
  if (index > size) {
    /*
     * Error: index out of the size 
     */ 
    return -1; 
  } else if (index == size) {
    /*
     * call the function of appendTail 
     */ 
    appendTail(list, node); 
  } else if (index == 0) {
    /*
     * call the function of appendHead 
     */ 
    appendHead(list, node); 
  } else {
    /* 
     * move the cursor to the right position of the list 
     */ 
    BiLinkedList cursor = (*list); 
    int pos = 0; 
    for (; pos < index - 1; pos++) {
      cursor = cursor->next; 
    } 
    /*
     * insert the node into the list 
     */ 
    node->next = cursor->next; 
    cursor->next->prev = node; 
    cursor->next = node; 
    node->prev = cursor; 
  }
  return index; 
}

/**
 * append one node to the end of the bidirection linked list 
 */
void 
appendTail(BiLinkedList *list, 
    BiLinkedListNode *node) {
  /*
   * move the cursor to the end of list 
   */ 
  BiLinkedList cursor = (*list); 
  while(cursor->next) {
    cursor = cursor->next; 
  } 
  /* 
   * connect the new node to the tail of the list 
   */ 
  cursor->next = node; 
  node->prev = cursor; 

}

/**
 * append one node to the beginning of the bidirection linked list 
 */
void 
appendHead(BiLinkedList *list, 
    BiLinkedListNode *node) {
  /*
   * save the original head of list 
   */
  BiLinkedList oldHead = (*list); 
  /*
   * reconnect the new head to the old list 
   */ 
  (*list) = node; 
  node->prev = NULL; 
  node->next = oldHead; 
  oldHead->prev = node; 
}

/**
 * delete one node of specified index and return the node 
 */
elemtype 
delete(BiLinkedList *list, 
    int index) {
  elemtype content; 
  int size = getSize(*list); 
  if (index > size) {
    /*
     * Error: index out of the size 
     */ 
    return -1; 
  } else if (index == size) {
    /*
     * move the cursor to the node just before the tail 
     */ 
    BiLinkedList cursor = (*list); 
    int pos = 0; 
    for (; pos < size - 1; pos++) {
      cursor = cursor->next; 
    }
    content = cursor->next->content; 
    free(cursor->next); 
    cursor->next = NULL; 
  } else if (index == 0) {
    (*list) = (*list)->next;
    content = (*list)->prev->content; 
    free((*list)->prev); 
    (*list)->prev = NULL; 
  } else {
    /* 
     * move the cursor to the right position of the list 
     */ 
    BiLinkedList cursor = (*list); 
    int pos = 0; 
    for (; pos < index; pos++) {
      cursor = cursor->next; 
    } 
    cursor->prev->next = cursor->next; 
    cursor->next->prev = cursor->prev; 
    content = cursor->content; 
    free(cursor); 
  }
  return content; 
}

/**
 * calculate the length of bidirection linked list 
 */
int getSize(BiLinkedList pointer) {
  int size = 1; 
  BiLinkedList cursor = NULL; 
  /*
   * get the size of all nodes before the pointer
   */
  cursor = pointer; 
  while (cursor->prev) {
    size++;
    cursor = cursor->prev; 
  } 
  /*
   * get the size of all nodes after the pointer 
   */
  cursor = pointer; 
  while (cursor->next) {
    size++; 
    cursor = cursor->next; 
  }

  return size; 
}

/**
 * print the whole list 
 */ 
void printList(BiLinkedList list) {
  int size = getSize(list); 
  BiLinkedList cursor = list; 
  int i = 0; 
  for (; i < size; i++) {
    printf("[%d]:%d\t", i, cursor->content); 
    cursor = cursor->next; 
  }
  printf("\n"); 
}

