#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map <string,int> hash_map;
    
    for(vector <string> get_kinds : clothes)
    {
        //여기서 옷 종류를 계산한다. 
        hash_map[get_kinds[1]]++;
    }
    
    unordered_map <string,int>::iterator iter;
    for(iter = hash_map.begin(); iter != hash_map.end(); iter++)
    {
        //std::cout << iter->second << " " << std::endl;
        answer *= (iter->second+1);
    }

    return answer-1;
}