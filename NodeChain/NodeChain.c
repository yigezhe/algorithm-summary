#include<stdio.h>
typedef struct _NODE  
{  
    int data;  
    struct _NODE* next;  
}NODE; 
void print(const NODE* pNode)  
{  
    if(NULL == pNode)  
        return;  
  
    while(pNode){  
        printf("%d\n", pNode->data);  
        pNode = pNode->next;  
    }  
}  
void print(const NODE* pNode)  
{  
    if(NULL == pNode)  
        return;  
    else  
        printf("%d\n", pNode->data);  
      
    print(pNode->next);  
}  

int mian(){
//我先建立一个1234的node chain 然后再打印他们！
NODE n1=
}
