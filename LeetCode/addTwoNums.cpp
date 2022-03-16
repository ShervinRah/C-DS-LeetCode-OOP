#include <iostream> 
#include <iomanip>
#include <string>

using namespace std; 

class ListNode{

    public:
    int value;
    ListNode* next;

    ListNode(){

        value = 0;
        next = NULL;
    }

    ListNode(int value){

        this->value = value;
        this->next = NULL;
    }

    static void printSum(ListNode* l1, ListNode* l2){

        ListNode* result;
        result = addTwoNums(l1,l2);
		
		while(result->next != NULL) {
			
			cout << result->value << " -> ";

			result = result->next;
		}
        cout << result->value;
        
    }
    static void show(ListNode* list){

        ListNode* lst = list;
		
		while(list->next != NULL) {
			
			cout << list->value << " -> ";

			list = list->next;
		}
        cout << list->value;
        
    }

    static ListNode* addTwoNums(ListNode* l1, ListNode* l2){

        ListNode* dummy = new ListNode(0);
        ListNode* list1 = l1;
        ListNode* list2 = l2; 
        ListNode* result = dummy;

        int carry = 0;

        while(list1 != NULL || list2 != NULL){
            
            int x = 0;
            int y = 0;
            if(list1 != NULL){

                x = list1->value;
            }
        
            if(list2 != NULL){

                y = list2->value;
            }
            int sum = x + y + carry;
            carry = sum / 10;
            result->next = new ListNode(sum % 10);
            result = result->next;
            

            if(list1 != NULL){

                list1 = list1->next;
            }
            if(list2 != NULL){

                list2 = list2->next;
            }
        }
        if(carry > 0){

            result->next = new ListNode(carry);
        }

        return dummy->next;


    }
};

int main(){

    ListNode* lst1 = new ListNode();
    lst1->value = 0;
    lst1->next = new ListNode();
    lst1->next->value = 9;
    lst1->next->next = new ListNode();
    lst1->next->next->value = 1;

    ListNode* lst2 = new ListNode();
    lst2->value = 0;
    lst2->next = new ListNode();
    lst2->next->value = 0;
    lst2->next->next = new ListNode();
    lst2->next->next->value = 9;
    ListNode::show(lst1);
    cout<<endl;
    ListNode::show(lst2);
    cout<<endl;
    ListNode::printSum(lst1,lst2);
    
  
    
}
