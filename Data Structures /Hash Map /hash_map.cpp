#include <map> 
#include <unordered_map> 
#include <iostream>
#include <string> 
#include <array> 



using namespace std; 

int main(){

    array <string, 5> arr_str = {"Shervin", "Shima", "Angelo", "Tadeh", "Erika"};
    array <int, 5> arr_int = {5, 6, 8, 2, 4};
    map<string,int> hash_map; 
    unordered_map<int,string> hash_unordered; 

    for(int i = 0; i < arr_str.size(); i++){

        hash_map[arr_str[i]] = arr_int[i];
    }

    for(int i = 0; i < arr_int.size(); i++){

        hash_unordered[arr_int[i]] = arr_str[i];
    }

    for(auto i = hash_map.begin(); i != hash_map.end(); i++){

        cout << i -> first << " : " << i -> second << "\n" << endl;
    }

    for(auto i = hash_unordered.begin(); i != hash_unordered.end(); i++){

        cout << i -> first << " : " << i -> second << "\n" << endl;
    }


    

    

    return 0;
}

