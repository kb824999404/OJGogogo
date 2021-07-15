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


bool isPalindrome(ListNode* head) {
    ListNode* p=head;
    int index = 0;
    while(p!=nullptr){
        p=p->next;
        index++;
    }
    int count = index,compare_count=floor(count/2),start1=1,start2;
    if(count<2) return true;
    if(count%2==0){
        start2=compare_count+1;
    }
    else{
        start2=compare_count+2;
    }

    ListNode *head1=head,*head2,*firstNode,*lastNode;
    index=1;
    p=head;
    while(p!=nullptr){
        if(index==start2) firstNode = p;
        if(index==start2+compare_count-1) lastNode = p;
        p=p->next;
        index++;
    }
    lastNode->next=nullptr;
    head2 = reverse(firstNode,nullptr);
    for(int i=0;i<compare_count;i++){
        if(head1->val!=head2->val) return false;
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;

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
    cout << isPalindrome(head);
    return 0;
}