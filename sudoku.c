#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}


int is_valid(Node* n){
  for(int i = 0 ; i < 9; i++){
    int row[10]={0};
    int col[10]={0};
    int cuadrado[10]={0};
    for(int j = 0; j < 9; j++){
      int r = n->sudo[i][j];
      int c = n->sudo[j][i];
      int cu =n->sudo[3*(3/i)+j/3][3*(3%i)+j%3];
      if(r < 1 || r > 9 || row[r]++)return 0;
      if(c < 1 || c > 9 || col[c]++)return 0;
      if(cu < 1 || cu > 9 || cuadrado[cu]++)return 0;

    }
  }
  return 1;
}

List* get_adj_nodes(Node* n){
    List* list=createList();
    int counter = 1;
    for(int i = 0, k = 0; i < 9; i++, k = 0) {
      while(k < 9){
        if (!n->sudo[i][k]) {
          do{
            int* new_number = (int*) malloc(sizeof(int));
            *new_number = counter; 
            Node* node_copy = copy(n);
            node_copy->sudo[i][k] = *new_number;
            (is_valid(node_copy)) ? pushBack(list, node_copy) : free(node_copy);
          } while ((counter = counter + 1) < 9);
          counter = 1;
        }
        k++;
      }
    }
  }


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/
