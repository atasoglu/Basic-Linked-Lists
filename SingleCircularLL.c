#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node *newNode(void);
Node *add(Node *root, int value);
Node *deleteFromLL(Node *root, int value);
void printLL(Node *root);

int main(void) {
  
  Node *root = NULL;
  for (int i = 0; i < 10; i++) 
   root = add(root, i);
  
  printLL(root);

  return 0;
}

Node *newNode() {
  return (Node*)malloc(sizeof(Node));
}

Node *add(Node *root, int value) {
  if (root == NULL) { // is root uninitialized?
    root = newNode(); 
    root->data = value; 
    root->next = root;
    return root;
  }
  Node *iter = root;
  do {
    if (iter->next == root) {
      Node *temp = newNode(); temp->data = value;
      iter->next = temp;
      temp->next = root;
      break;
    }
    iter = iter->next;
  } while (iter != root);

  return root;
}

Node *deleteFromLL(Node *root, int value) {
  Node *iter = root;
  do {
    Node *temp = iter->next;
    if (temp->data == value) {
      iter->next = temp->next;
      free(temp);
      break;
    }
    iter = iter->next;
  } while (iter != root);
  return root;
}

void printLL(Node *root) {
  Node *iter = root;
  do {
    printf("MyAdd.: %p MyData: %d MyNext: %p\n", iter, iter->data, iter->next);
    iter = iter->next;
  } while (iter != root);
}