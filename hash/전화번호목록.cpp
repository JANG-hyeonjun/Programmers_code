#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string,int> hash_map;
    
    for(int i =0; i < phone_book.size(); i++)
    {
        hash_map[phone_book[i]] = 1;
    }
    
    for(int i =0; i <phone_book.size(); i++)
    {
        string phone_number = "";
        for(int j =0; j < phone_book[i].size(); j++)
        {
            phone_number += phone_book[i][j];
            //예를 들자면 "1234"가 있으면 "1" ,"12","123","1234" 가 unordered_map에 있는지 확인하고 있으면 false 없으면 true인 것이다.
           //std::cout << phone_number << std::endl;
            if(hash_map[phone_number] && phone_number != phone_book[i]) //hash_map 에도 있고 자기 자신이 아닌 다른 전화번호이다.
                return false;
        }
    }
    return answer;
}