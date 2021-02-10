#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *newNode(void);
Node *add(Node *root, int value);
Node *reverse(Node *root);
Node *deleteFromLL(Node *root, int value);
void printLL(Node *root);

int main(void) {
  
  Node *root = NULL;
  for (int i = 0; i < 10; i++) 
   root = add(root, i);
  
  printLL(root);

  root = reverse(root);
  printf("Reversed...\n");
  printLL(root);

  root = deleteFromLL(root, 9);
  printf("Deleted 5...\n");
  printLL(root);


  return 0;
}

Node *newNode() {
  return (Node*)malloc(sizeof(Node));
}

Node *add(Node *root, int value) {
  if (root == NULL) { // is root uninitialized?
    root = newNode(); 
    root->data = value; root->next = NULL;
    return root;
  }
  Node *iter = root;
  while (iter != NULL) {
    if (iter->next == NULL) {
      Node *temp = newNode();
      temp->data = value; temp->next = NULL;
      iter->next = temp;
      break;
    }
    iter = iter->next;
  }
  return root;
}

Node *reverse(Node *root) {
  Node *iter = root;
  Node *prev = NULL;
  Node *next = NULL;

  while (iter != NULL) {
    next = iter->next;
    iter->next = prev;
    prev = iter;
    iter = next;
  }
  return prev;
}

Node *deleteFromLL(Node *root, int value) {
  
  Node *iter = root;
  Node *prev = NULL;

  while (iter != NULL) {
    if (iter->data == value) {
      if (prev == NULL) root = iter->next;
      else prev->next = iter->next;
      free(iter);
      break;
    }
    prev = iter;
    iter = iter->next;
  }
  return root;
}

void printLL(Node *root) {
  Node *iter = root;
  while (iter != NULL) {
    printf("MyAdd.: %p MyData: %d MyNext: %p\n", iter, iter->data, iter->next);
    iter = iter->next;
  }
}