/**
 * author : chaos
 * time   : 2014-03-03
 */ 

#include "BiLinkedListNode.h" 
#include "BiLinkedListNodeFun.h" 
#include <stdio.h> 
#include <stdlib.h> 

int 
main(int argc, 
    char **argv) {
  /*
   * create the list with default value from 0 to 6
   */ 
  BiLinkedList list = NULL; 
  initList(&list, 0); 
  int i = 1; 
  for (; i < 7; i++) {
    appendTail(&list, createNode(i)); 
  }
  printf("original list\n\t"); 
  printList(list); 

  /*
   * test for insert 
   */ 
  printf("insert value(10) to index(0)\n\t"); 
  insert(&list, createNode(10), 0); 
  printList(list); 

  printf("insert value(11) to index(4)\n\t"); 
  insert(&list, createNode(11), 4); 
  printList(list); 
  
  /*
   * test for appendHead 
   */
  printf("append value(12) to the beginning of the list\n\t"); 
  appendHead(&list, createNode(12)); 
  printList(list); 

  /*
   * test for appendTail 
   */
  printf("append value(13) to the end of the list\n\t"); 
  appendTail(&list, createNode(13)); 
  printList(list); 

  /*
   * test for delete 
   */ 
  printf("delete the node at the index(0)\n\t"); 
  delete(&list, 0); 
  printList(list); 

  printf("delete the node at the index(4)\n\t"); 
  delete(&list, 4); 
  printList(list); 

  return 0; 
}
