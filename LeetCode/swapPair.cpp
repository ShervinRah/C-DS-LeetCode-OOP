#include <iostream>
#include <iomanip>

using namespace std;

class swapPair{

    public:
    int value;
    swapPair* next;

    swapPair(){

        value = 0;
        next = NULL;
    };

    swapPair(int value){

        this->value = value;
        this->next = NULL;
    }

    static void printSwap(swapPair* list){

        swapPair* result;
        result = returnPairSwap(list);
		
		while(result->next != NULL) {
			
			cout << result->value << " -> ";

			result = result->next;
		}
        cout << result->value;
        
    }
    static void show(swapPair* list){

        swapPair* lst = list;
		
		while(list->next != NULL) {
			
			cout << list->value << " -> ";

			list = list->next;
		}
        cout << list->value;
        
    }

    static swapPair* returnPairSwap(swapPair* list){

        swapPair* dummy_head = new swapPair(0);
        swapPair* prev = dummy_head;
        swapPair* curr = list;

        while(curr != NULL && curr->next != NULL){

            swapPair* nextPair = curr->next->next;
            swapPair* second = curr->next;

            second->next = curr;
            curr->next = nextPair;
            prev->next = second;

            prev = curr;
            curr = nextPair;

        }

        return dummy_head->next;
    }

};

int main(){

    swapPair* list = new swapPair(1);
    list->next = new swapPair(2);
    list->next->next = new swapPair(3);
    list->next->next->next = new swapPair(4);

    swapPair::show(list);
    cout<<endl;
    swapPair::printSwap(list);
}
