//  NOT A GOOD SOLUTION : SPACE= O(2n) TIME: O(3n)
// IDEAL SOLUTION SHOULD BE : SPACE= O(1) TIME: O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode* > v;
        ListNode* temp=head;
        
        if(temp!=NULL){
        while(temp!=NULL)
        {
            v.push_back(temp);
            temp=temp->next;
        }
        vector<ListNode* > v1(v.size());
        int i=0;
        int j=v.size()-1;
        bool flag=true;
        int k=0;
        while(i<=j)
        {
            if(flag==true)
            {
                v1[k]=v[i];
                i++;
                flag=false;
            }
            else
            {
                v1[k]=v[j];
                j--;
                flag=true;
            }
            k++;
        }
        
        for(i=0;i<v1.size()-1;i++)
        {
            temp=v1[i];
            temp->next=v1[i+1];
        }
        temp=v1[i];
        temp->next=NULL;
        }
    }
};
