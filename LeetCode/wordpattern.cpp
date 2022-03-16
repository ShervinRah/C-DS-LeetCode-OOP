#include <iostream> 
#include <string> 
#include <array> 
#include <vector> 
#include <sstream> 
#include <unordered_map> 

using namespace std;

vector<string> split(string str, char empt_space){

    vector<string> new_str;
    stringstream split_str(str);
    string token;

    while(getline(split_str,token,empt_space)) {

            new_str.push_back(token);
    }

    return new_str;

}
bool wordPattern(string pattern, string str) {
        unordered_map<char, string> dict_pattern;
        unordered_map<string, char> dict_string;
        
        int len = pattern.size();
        vector<string> strs = split(str, ' ');
        
        if (len != strs.size()) return false;
        
        for(int i=0; i<len; i++) {
            char& ch = pattern[i];
            string& s = strs[i];
            
            if ( dict_pattern.find(ch) == dict_pattern.end() ) {
                dict_pattern[ch] = s;
            }
            
            if ( dict_string.find(s) == dict_string.end() ) {
                dict_string[s] = ch;
            }
            
            if ( dict_pattern[ch] != s || dict_string[s] != ch ) {
                return false;
            }
            
        }
        return true;
    }
/*
bool isPattern(string pattern, string words){

    if(pattern.size() != words.size()){

        return false;
    }
    unordered_map<char,string> char_map;
    unordered_map<string,char> str_map;
    vector<string> str_words = split(words, ' ');

    for(int i = 0; i < pattern.size(); i++){

        char curr_char = pattern[i];
        
        if(char_map.find(curr_char) != char_map.end()){

            if(char_map[curr_char] != str_words[i]){

                return false;
            }

        }
        if(str_map.find(str_words[i]) != str_map.end()){

            if(str_map[str_words[i]] != curr_char){

                return false;
            }
        }

        char_map[curr_char] = str_words[i];
        //str_map[str_words[i]] = curr_char;
        
    }

    return true;
  
}
*/

int main(){

    /*

    a -> dog 
    b -> cat 
    b -> cat 
    a -> dog 

    dog -> a 
    cat -> b
    cat -> b
    dog -> a

    */

    string pattern = "absba";
    string str = "dog cat cat dog";
    char tok = ' ';
    
    //cout << wordPattern(pattern, str);

    if (wordPattern(pattern,str) == 1){

        cout << "True" << endl;
    }
    else{

        cout << "False" << endl;
    }

    /*
    vector<string> result = split(str,tok);
    
    for(int i = 0; i < result.size(); i++){

        cout << result[i] << endl;
    }*/



}