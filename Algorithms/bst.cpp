#include <iostream>
#include <iomanip>
using namespace std;

class bstNode{

public:
    int value;
    bstNode* left;
    bstNode* right;

    ~bstNode(){};
    bstNode(){

        this->value = 0;
        this->left = NULL;
        this->right = NULL;
    }

    bstNode(int value){

        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }

    bstNode(int value, bstNode* left, bstNode* right){

        this->value = value;
        this->left = left;
        this->right = right;
    }

    bstNode* root;

    void addNode(int value){

        if (root == NULL){

            bstNode* node = new bstNode(value);
            root = node;
        }
        else{

            bstNode* focusNode = root;
            bstNode* parent;

            while(true){

                if(value > focusNode->value){
                    
                    if(focusNode->right == NULL){

                        focusNode->right = new bstNode(value);
                        return;
                    }
                    else{
                        focusNode = focusNode->right;
                    }
                
                }
                else{

                    if(focusNode->left == NULL){

                        focusNode->left = new bstNode(value);
                        return;
                    }
                    else{

                        focusNode = focusNode->left;
                    }
                }

            }
        
        }


    }

    static void printBST(bstNode* node){

        if(node != NULL){

            printBST(node->left);
            cout << node->value << " ";
            printBST(node->right);
        }
        
    }

};

int main(){

        bstNode* node = new bstNode();
        node->addNode(7);
        node->addNode(2);
        node->addNode(18);
        node->addNode(6);
        node->addNode(4);
        node->addNode(23);
        node->addNode(20);
        node->addNode(17);
        node->addNode(1);

        bstNode::printBST(node->root);

        return 0;

}