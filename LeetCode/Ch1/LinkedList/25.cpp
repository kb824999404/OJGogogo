#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* head,ListNode* nextNode){
    ListNode* node = head->next;
    head->next = nextNode;
    if(!node) return head;
    else return reverse(node,head);
}
ListNode* reverseKGroup(ListNode* head, int k){
    if(head==nullptr) return nullptr;
    int i=1;
    ListNode* p = head;
    ListNode* firstNode=p;
    ListNode* lastNode,*nextNode;
    while(p!=nullptr){
        if(i==k){
            cout<<p->val<<endl;
            lastNode=p;
            nextNode=p->next;
            nextNode = reverseKGroup(nextNode,k);
            lastNode->next = nullptr;
            return reverse(firstNode,nextNode);
        }
        p = p->next;
        i++;
    }
    return head;
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i=2;i<=5;i++){
        ListNode* node = new ListNode(i);
        p->next = node;
        p = node;
    }
    reverseKGroup(head,3);
    return 0;
}