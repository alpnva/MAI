#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode TreeNode;
typedef double T;

struct TreeNode
{
    T data;
    TreeNode* l;
    TreeNode* r;
};

TreeNode* makeNode(double val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = val;
    node->l = NULL;
    node->r = NULL;
    return node;
}

void add(TreeNode* cur, TreeNode* newel) {
    if (newel->data < cur->data) {
        if (cur->l == NULL) {
            cur->l = newel;
            return;
        }
        add(cur->l, newel);
    }
    else {
        if (cur->r == NULL) {
            cur->r = newel;
            return;
        }
        add(cur->r, newel);
    }
}

TreeNode** find(TreeNode** cur, double val) {
    if (*cur == NULL) {
        return cur;
    }
    if (val < (*cur)->data) {
        return find(&((*cur)->l), val);
    } else if (val > (*cur)->data) {
        return find(&((*cur)->r), val);
    } else {
        return cur;
    }
}

void clearTree(TreeNode* cur) {
    if (cur->l != NULL) {
        clearTree(cur->l);
        free(cur->l);
    }
    if (cur->r != NULL) {
        clearTree(cur->r);
        free(cur->r);
    }
}

void printTree(TreeNode* cur, int d) {
    if (cur->r != NULL) {
        printTree(cur->r, d + 1);
    }
    printf("%*s%lf\n", 4 * d, " ", cur->data);
    if (cur->l != NULL) {
        printTree(cur->l, d + 1);
    }
}

TreeNode* Min(TreeNode* cur){
    if (cur->l->l == NULL){
        return cur;
    }
    return Min(cur->l);
}

void DeleteElem(TreeNode** cur, double val, TreeNode* par){
    if (val < (*cur)->data){
        DeleteElem(&((*cur)->l), val, *cur);        
    }
    else if (val > (*cur)->data){
        DeleteElem(&((*cur)->r), val, *cur);
    }
    else {
        if (((*cur)->l == NULL) && ((*cur)->r == NULL)) {
            if (par) {
                if (par->l) {
                    if (par->l->data == (*cur)->data) {
                        par->l = NULL;
                    }
                }
                if (par->r) {
                    if (par->r->data == (*cur)->data) {
                        par->r = NULL;
                    }
                }
            }
            free(*cur);
            *cur = NULL;
        } else if (((*cur)->l == NULL) || ((*cur)->r == NULL)) { 
            TreeNode* Help = NULL;
            if ((*cur)->l) {
                Help = (*cur)->l;
            } else {
                Help = (*cur)->r;
            }
            (*cur)->l = Help->l;
            (*cur)->r = Help->r;
            (*cur)->data = Help->data;
            free(Help);
        } else {
            if ((*cur)->r->l == NULL) { 
                (*cur)->data = (*cur)->r->data;
                TreeNode* rr = (*cur)->r->r;
                free((*cur)->r);
                (*cur)->r = rr;
            } else {
                TreeNode* Minpar = Min((*cur)->r);
                free(Minpar->l);
                Minpar->l = NULL;
            }
        }
    }
}

TreeNode* func(TreeNode* cur, double d){
    if(cur->data > d){
        return func(cur->l, d);
    }
    if(cur->data < d){
        return func(cur->r, d);
    }
    if(cur->data == d){
        if(d=2 && cur->l && cur->r){
            return cur;
        }
        if(d=1 && ((cur->l && !cur->r)||(cur->r && !cur->l))){
            return cur;
        }
        if(d=0 && cur->l==NULL && cur->r==NULL){
            return cur;
        } else{
        return NULL;
    } 
    } else{
        return NULL;
    }
}

T main() {
    int s = 1, n, d = 0;
    double c=0;
    TreeNode* root = NULL;
    double value;
    while (s != 0){
        printf("Menu option:\n");
        printf("1 - to stop\n");
        printf("2 - to add element in tree\n");
        printf("3 - to print tree\n");
        printf("4 - to delete element in tree\n");
        printf("5 - to do task #9\n");
        scanf("%d", &s);
        switch (s){
            case 1:
                if (root != NULL){
                    clearTree(root);
                }
                return 0;
            case 2:
                printf("Cardinality:");
                scanf("%d", &n);
                for (n; n > 0; n--) {
                    scanf("%lf", &value);
                    if (root == NULL) {
                        root = makeNode(value);
                    }else {
                        add(root, makeNode(value));
                    }
                }
                break;
            case 3:
                printf("Tree:\n");
                printTree(root, 0);
                break;
            case 4:
                if (root == NULL){
                    printf("Mistake!!! You must create the tree\n");
                }else {
                printf("Element:");
                scanf("%lf", &value);
                DeleteElem(&root, value, NULL);
                printf("Successfully deleted\n");
                }
                break;
            case 5:
                if (root == NULL){
                    printf("Mistake!!! You must create the tree\n");
                }else {
                    for(int f=0; f<=2; f++){
                        if(func(root, f)){
                            c++;
                        }
                    }
                }
                printf("Quantity:%lf\n", c);
                c=0;
                break;
        }
    }
    return 0;
}
