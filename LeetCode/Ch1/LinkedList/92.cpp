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

ListNode* reverseBetween(ListNode* head, int left, int right) {
    int i=1;
    ListNode* leftNode=nullptr;
    ListNode* rightNode=nullptr;
    ListNode* preNode=nullptr;
    ListNode* nextNode=nullptr;
    ListNode* p=head;
    while(p!=nullptr){
        if(i==left) leftNode = p;
        if(i==right) rightNode = p;
        if(i==left-1) preNode = p;
        if(i==right+1) nextNode = p;
        p = p->next;
        i++;
    }
    rightNode->next = nullptr;
    ListNode* reverseHead = reverse(leftNode,nextNode);
    if(preNode==nullptr)
        return reverseHead;
    else{
        preNode->next = reverseHead;
        return head;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);

    ListNode* head = new ListNode(1);
    ListNode* p = head;
    for(int i=2;i<=5;i++){
    head->next = new ListNode(2);
        ListNode* node = new ListNode(i);
        p->next = node;
        p = node;
    }
    reverseBetween(head,2,4);
    return 0;
}