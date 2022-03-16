#include <iostream> 
#include <vector> 
#include <string> 
#include <map> 
#include <array>

using namespace std; 

vector<int> twoSum(vector<int> nums, int target) {

    vector<int> res;
    for (int i= 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j<nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                return res;
            }
        }
    }
    
    return res;
}

vector<int> twoSumHash(vector<int> &nums, int target){

    vector<int> res;
    map<int,int> hash_map;

    for(int i = 0; i < nums.size(); i++){

        hash_map[nums[i]] = i;

    }
    for(int i = 0; i < nums.size(); i++){

        int complement = target - nums[i];

        if(hash_map.find(complement) != hash_map.end()){

            res.push_back(i);
            res.push_back(hash_map[complement]);
            
            return res;
        }

    }

    return res;

}


int main(){
 
    int items1 [] = {3, 5, 6, 9, 12};
    vector<int> items2 (items1, items1 + sizeof(items1) / sizeof(int));
    int target = 11;

    /*items2.push_back(3);
    items2.push_back(5);
    items2.push_back(6);
    items2.push_back(9);
    items2.push_back(12);*/

    vector<int> sums1 = twoSum(items2,target);
    vector<int> sums2 = twoSumHash(items2,target);
    array<string, 5> arr = {"Shervin", "Erika", "Lilly", "Angelo", "Tadeh"};


    for(int i = 0; i < sums1.size(); i++){

        if(i != sums1.size() - 1) {

            cout << sums1.at(i) <<  ",";
        }
        else{

            cout << sums1.at(i) << endl;
        }
        
    }

    for(int i = 0; i < sums2.size(); i++){

        if(i != sums2.size() - 1) {

            cout << sums2.at(i) <<  ",";
        }
        else{

            cout << sums2.at(i) << endl;
        }
        
    }

    /*()
    int sizeArr = sizeof(items1)/sizeof(items1[0]);

    cout << sizeArr << endl; 

    for(int i = 0; i < sizeArr; i++){

        if(i != sizeArr - 1){

            cout << items1[i] << ",";
        }
        else{

            cout << items1[i] << endl;
        }
        

    }

    for(int i = 0; i < items2.size(); i++){

        if(i != items2.size() - 1) {

            cout << items2.at(i) <<  ",";
        }
        else{

            cout << items2.at(i) << endl;
        }
        
    }*/






    return 0; 
}