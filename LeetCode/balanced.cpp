#include <iostream>
#include <string>
#include <stack> 

using namespace std;

bool isValid(string pattern){

    stack<char> str;

    if(pattern.length() % 2 != 0){

        return false;
    }

    for(int i = 0; i < pattern.length(); i++){

        if(pattern[i] == '[' || pattern[i] == '{' || pattern[i] == '('){

            str.push(pattern[i]);
        }
        if(pattern[i] == ']' || pattern[i] == '}' || pattern[i] == ')'){
            
            char tmp = str.top();
            str.pop();
            if ((tmp == '{' && pattern[i] != '}') || (tmp == '(' && pattern[i] != ')') || (tmp == '[' && pattern[i] != ']')){

                return false;
            }
            
        }

    }
    return true;

}


int main(){

    string pattern = "{[{()}]}";

    bool result = isValid(pattern);
    if(result == 0){

        cout << "False" << endl;
    }
    else{
        
        cout << "True" << endl;
    }

    return 0;
}