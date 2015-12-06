#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct tagNode {
    int value;
    struct tagNode* left;
    struct tagNode* right;
} treeNode;

//打印数组
void displayArray(int array[],int size) {
    printf("the array is:");
    int i;
    for(i=0; i<size; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");
}

//按左中右顺序遍历树
void displayTree(treeNode* node) {
    if(node == NULL) return;

    if(node->left != NULL) {
        displayTree(node->left);
    }

    printf("%d ",node->value);

    if(node->right != NULL) {
        displayTree(node->right);
    }
}

//查找以node为节点的树中上是否存在vlaue的节点
treeNode* searchTree(treeNode* node, int value) {
    if(node->value == value) {
        return node;
    } else if(node->value > value) {
        if(node->left != NULL) {
            return searchTree(node->left, value);
        } else {
            return NULL;
        }
    } else {
        if(node->right != NULL) {
            return searchTree(node->right, value);
        } else {
            return NULL;
        }
    }
}

//查找以node为节点的树中上是否存在vlaue的节点,parent为查找到的节点的父节点。
//dir为1表示parent节点的左节点为查找结果
//dir为2表示parent节点的右节点为查找结果
treeNode* searchTreeWithParent(treeNode* node, treeNode** parent, int* dir, int value) {
    if(node->value == value) {
        return node;
    } else if(node->value > value) {
        if(node->left != NULL) {
            *dir = 1;
            *parent = node;
            return searchTreeWithParent(node->left, parent, dir, value);
        } else {
            return NULL;
        }
    } else {
        if(node->right != NULL) {
            *dir = 2;
            *parent = node;
            return searchTreeWithParent(node->right, parent, dir, value);
        } else {
            return NULL;
        }
    }
}

//将iNode插入到以node为根节点的树中
void insertNode(treeNode* node, treeNode* iNode) {
    if(iNode->value >= node->value && node->right != NULL) {
        insertNode(node->right, iNode);
        return;
    }

    if(iNode->value < node->value && node->left != NULL) {
        insertNode(node->left, iNode);
        return;
    }

    if(iNode->value >= node->value && node->right == NULL) {
        node->right = iNode;
    }

    if(iNode->value < node->value && node->left == NULL) {
        node->left = iNode;
    }
}

//从以root为根节点的树中删除值为value的节点
void deleteNode(treeNode** root, int value) {
    treeNode* parent = NULL;
    int dir = -1;
    treeNode* deleteNode = searchTreeWithParent(*root,&parent,&dir,value);
    if(deleteNode == NULL) {
        printf("%s\n", "node not found");
    } else {
        if(deleteNode->left == NULL && deleteNode->right == NULL) {
            //对应说明中的a
            if(parent != NULL) {
                if(dir == 1)
                    parent->left = NULL;
                else
                    parent->right = NULL;
            } else { //对应说明中的b
                *root = NULL;
            }
        } else if(deleteNode->left != NULL && deleteNode->right == NULL) {
            //对应说明中的c
            if(parent != NULL) {
                if(dir == 1)
                    parent->left = deleteNode->left;
                else
                    parent->right = deleteNode->left;
            } else { //对应说明中的d
                *root = deleteNode->left;
            }
        } else if(deleteNode->left == NULL && deleteNode->right != NULL) {
            //对应说明中的e
            if(parent != NULL) {
                if(dir == 1)
                    parent->left = deleteNode->right;
                else
                    parent->right = deleteNode->right;
            } else { //对应说明中的f
                *root = deleteNode->right;
            }
        } else {
            insertNode(deleteNode->left,deleteNode->right);
            //对应说明中的g
            if(parent != NULL) {
                if(dir == 1)
                    parent->left = deleteNode->left;
                else
                    parent->right = deleteNode->left;
            } else { //对应说明中的h
                *root = deleteNode->left;
            }
        }
        free(deleteNode);
        deleteNode = NULL;
    }
}

//使用array数组中的数，创建以root为根节点的树，
void createTree(treeNode** root, int array[], int size) {
    int i;

    *root = (treeNode*)malloc(sizeof(treeNode));
    (*root)->value = array[0];
    (*root)->left = NULL;
    (*root)->right = NULL;

    for(i=1; i<size; i++) {
        treeNode* child = (treeNode*)malloc(sizeof(treeNode));
        child->value = array[i];
        child->left = NULL;
        child->right = NULL;
        insertNode(*root, child);
    }
}

//删除以node为根节点的树
void deleteTree(treeNode* node) {
    if(node == NULL) return;

    if(node->left != NULL) {
        deleteTree(node->left);
    }

    if(node->right != NULL) {
        deleteTree(node->right);
    }

    if(node->left == NULL && node->right == NULL) {
        free(node);
        node = NULL;
    }
}

int main(int argc, char* argv[]) {

    int array[SIZE] = {4,1,45,78,345,23,12,3,6,21};
    displayArray(array,SIZE);

    treeNode *root = NULL;

    createTree(&root, array, SIZE);

    printf("the tree is(left->middle->right):");
    displayTree(root);
    printf("\n");

    int value = atoi(argv[1]);
    treeNode* parent = NULL;
    int dir = -1;
    printf("search value %d:",value);
    if(searchTree(root,value) != NULL) {
        printf("%s\n","exist");
    } else {
        printf("%s\n","not exist");
    }

    printf("delete value:%d ",value);
    deleteNode(&root,value);
    printf("\n");
    printf("the tree is(left->middle->right):");
    displayTree(root);
    printf("\n");

    deleteTree(root);
    return 0;
}

