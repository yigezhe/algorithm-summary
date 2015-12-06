#include<iostream>
#include<stdio.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//定义链表节点
class Solution {
  public:
    ListNode *sortList(ListNode *head) {
        if(!head) {
            return nullptr;
        }
        return MergeSort(head);
    }
    void printList(ListNode *head) {
        ListNode *p=head;

        while(p) {
            printf(" %d",p->val);
            p=p->next;
        }
        printf("\n");

    }


  private:
    //获取中点前一个元素，因为要截断链表
    ListNode *GetMidNodePre(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        ListNode *k = q;
        while(p) {
            p = p->next;
            if(p) {
                p = p->next;
            }
            k = q;
            q = q->next;
        }
        return k;
    }

    //归并排序过程
    ListNode* MergeSort(ListNode *head) {
        //只有一个元素的情况下，返回
        if(!head->next) {
            return head;
        }
        //分隔节点
        ListNode *midNodePre = GetMidNodePre(head);
        ListNode *midNode = midNodePre->next;
        midNodePre->next = nullptr;

        ListNode *head1 = MergeSort(head);
        ListNode *head2 = MergeSort(midNode);
        //归并过程
        head1 = MergeList(head1, head2);

        return head1;
    }
    ListNode *MergeList(ListNode *head1, ListNode *head2) {
        ListNode *p = head1;
        ListNode *q = head2;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        while(p && q) {
            if(p->val < q->val) {
                if(!tail) {
                    head = p;
                    tail = p;
                    p = p->next;
                } else {
                    tail->next = p;
                    tail = tail->next;
                    p = p->next;
                }
            } else {
                if(!tail) {
                    head = q;
                    tail = q;
                    q = q->next;
                } else {
                    tail->next = q;
                    tail = tail->next;
                    q = q->next;
                }
            }
        }
        if(p) {
            tail->next = p;
        }
        if(q) {
            tail->next = q;
        }
        return head;
    }
};


int main() {

    ListNode a(2);
    ListNode b(4);
    ListNode c(1);
    ListNode d(3);
    ListNode e(5);

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;

    Solution solution;
    solution.printList(&a);
    solution.sortList(&a);
    solution.printList(&a);

    return 0;
}
