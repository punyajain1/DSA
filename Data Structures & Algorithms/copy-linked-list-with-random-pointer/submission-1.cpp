/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* temp = head;
        while(temp!=nullptr){
            Node* t = new Node(temp->val);
            t->next = temp->next;
            temp->next=t;
            temp=temp->next->next;
            //so here we created a new node t such that it is copy of org now org next = t and org will move to next in line (so every org next is now pointing to new node whose next is its copy)
            // org -> t(copy of org) -> org(next)
        }
        temp=head;
        while(temp){
            Node* t = temp->next;
            if(temp->random!= nullptr){
                t->random = temp->random->next;
                //here new node random is pointing to the copy of org random 
                // org -> t(copy of org) -> org(next)
            }
            temp = temp->next->next;
            // org -> t(copy of org) -> org(next)
        }
        temp=head;
        Node* nh = temp->next;
        while(temp!=nullptr){
            Node* t = temp->next;
            temp->next = t->next;
            
            if(temp->next){
                t->next = temp->next->next;
                // org -> t(copy of org) -> org(next) -> t(copy of org next)
                // and here we are doing - t1 -> t2 -> t3 ... (removing the org next from new node )
            }
            temp=temp->next;
        }
        return nh;
    }
};
