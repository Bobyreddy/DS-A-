/*
 Design, Develop and Implement a menu driven Program in C for the following
operations on Binary Search Tree (BST) of Integers
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the BST in Inorder, Preorder and Post Order
c. Search the BST for a given element (KEY) and report the appropriate message
d. Delete an element(ELEM) from BST
e. Exit
*/

#include<stdio.h>
#include<stdlib.h>
struct node {
    int value;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;

struct node* insert(struct node* r, int data);
void inorder(struct node* r);
void preorder(struct node* r);
void postorder(struct node* r);
struct node* search(struct node ** tree, int val);
struct node* delete1(struct node* root, int key);

void main(){
   int choice,key,i;
   struct node* tmp;
   int n, v;
   printf("\n Program For Binary Search Tree ");
   printf("\n How many data's do you want to insert :\n");
   scanf("%d", &n);
   while(1){
      printf("\n 1. Create \n 2. Search \n 3. Recursive Traversals \n 4. Delete \n 5. Exit \n Enter your choice: ");
      scanf(" %d", &choice);
      switch (choice){
      case 1:
        for(i=1; i<=n; i++){
		printf("Data %d: ", i);
		scanf("%d", &v);
		root = insert(root, v);
	    }
	break;
      case 2:
         printf("\nEnter Element to be searched :");
         scanf("%d", &key);
	 tmp = search(&root, key);
	 if (tmp){
		printf("Searched node=%d\n", tmp->value);
	 }
	 else{
		printf("Data Not found in tree.\n");
	 }
         break;
      case 3:
         if(root == NULL)
            printf("Tree Is Not Created");
         else{
            printf("\nThe Inorder display : ");
            inorder(root);
            printf("\nThe Preorder display : ");
            preorder(root);
            printf("\nThe Postorder display : ");
            postorder(root);
         }
         break;
     case 4:printf("\nEnter Element to be deleted :");
        scanf("%d", &key);
	tmp=delete1(root, key);
	if (tmp){
		printf("deleted node=%d\n", tmp->value);
	}
	else{
		printf("Data Not found in tree.\n");
        }
        break;
     default: exit(0);
     }
   }
}              

struct node* insert(struct node* r, int data){
    if(r==NULL){
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if(data < r->value){
        r->left = insert(r->left, data);
    }
    else{
        r->right = insert(r->right, data);
    }
    return r;
}

struct node* search(struct node ** tree, int val){
    if(!(*tree)){
        return NULL;
    }
    if(val < (*tree)->value){
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->value){
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->value){
        return *tree;
    }
}

void inorder(struct node* r){
    if(r!=NULL){
        inorder(r->left);
        printf("%d ", r->value);
        inorder(r->right);
    }
}

void preorder(struct node* r){
    if(r!=NULL){
        printf("%d ", r->value);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node* r){
    if(r!=NULL){
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->value);

    }
}
struct node * minValueNode(struct node* node){
    struct node* current = node;

       while (current->left != NULL)
        current = current->left;

    return current;
}   

struct node* delete1(struct node* root, int key) {
    if (root == NULL) return root;

    if (key < root->value)
        root->left = delete1(root->left, key);

    else if (key > root->value)
        root->right = delete1(root->right, key);

    else {
        if (root->left == NULL){
            struct node *temp = root->right;
              return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
             return temp;
        }
	struct node* temp = minValueNode(root->right);

        root->value = temp->value;

        root->right = delete1(root->right, temp->value);
   }
   return root;
}
