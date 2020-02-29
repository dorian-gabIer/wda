#include <iostream>
#include <string>
using namespace std;


bool add(string my_map[], string key){
    int h, hash, new_hash;
    h = 0;
    for(int i=0; i<key.length(); i++){
        h += int(key[i])*(i+1);
    }
    hash = (h*19)%101;
    // Check if duplicate value
    if(my_map[hash] == key){
        // Hash already added in first position
        return false;
    }
    // Check if hash added in any other position
    else{
        for(int j=1; j<=19; j++){
            new_hash = (hash+(23*j)+(j*j))%101;
            if(my_map[new_hash] == key){
                return false;
            }
        }
    }
    // It is not duplicate value, therefore ADD
    if(my_map[hash] == ""){
        my_map[hash] = key;
        return true;
    }
    for(int j=1; j<=19; j++){
        new_hash = (hash+(j*j)+(23*j))%101;
        //If new index is empty
        if(my_map[new_hash] == ""){
            my_map[new_hash] = key;
            return true;
        }
    }
    return false;
}

bool del(string my_map[], string key){
    for(int i=0; i<101; i++){
        // If the key was found, remove it
        if(my_map[i] == key){
            my_map[i] = "";
            return true;
        }
    }
    return false;
}


int main(){
    int N, m, number_of_entries;
    string op, key;
    string my_map[101];
    cin>>N;
    for(int testcase=0; testcase<N; testcase++){
        cin>>m;
        // Start from 0 for each testcase
        number_of_entries = 0;
        // Clear the map, for each testcase
        for(int i=0; i<101; i++){
            my_map[i] = "";
        }
        for(int operation=0; operation<m; operation++){
            cin>>op;
            // ADD operation
            if(op.substr(0,3) == "ADD"){
                key = op.substr(4);
                if(add(my_map, key)){
                    number_of_entries += 1;
                }
            }
            // DEL operation
            else if(op.substr(0,3) == "DEL"){
                key = op.substr(4);
                if(del(my_map, key)){
                    number_of_entries -= 1;
                }
            }
        }
        // Print number_of_entries and my_map
        cout<<number_of_entries<<"\n";
        for(int i=0; i<101; i++){
            if(my_map[i] != ""){
                cout<<i<<":"<<my_map[i]<<"\n";
            }
        }
    }
    return 0;
}
