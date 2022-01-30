#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    /*
    for (auto iter : participant)
    {
        auto get = find(completion.begin(),completion.end(),iter);
        if(get == completion.end())
        {
            //std::cout << iter << "는 찾지 못해습니다" << std::endl;
            answer = iter;
            break;
        }
        else
        {
            //std:: cout << iter <<" 를 찾았습니다!" << std::endl;
            auto idx = get - completion.begin();
            completion.erase(completion.begin() + idx);
        }
    }
    */
    //아무래도 일일히 비교하는게 시간복잡도를 많이 잡아 먹으니 
    //정렬해서 비교하고 아니면 탈출 
    /*for(int i =0; i < participant.size(); i++)
    {
        std::cout << participant[i] << std::endl;
    }
    */
    sort(participant.begin(),participant.end());
    // a m m s
    // a m s "" 
    sort(completion.begin(),completion.end());
    completion.push_back(" ");
    int idx = 0;
    for(auto iter : participant)
    {
        if(iter != completion[idx])
        {
            answer = iter;
            break;
        }
        idx++;
    }
    
    return answer;
}