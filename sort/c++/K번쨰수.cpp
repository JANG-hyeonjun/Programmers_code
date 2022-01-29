#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    /*for(int i =0; i < array.size(); i++)
    {
        printf("%d\n",array[i]);
    }
    */
    vector<int> answer;
    for(int i =0; i < commands.size(); i++)
    {
       vector<int> temp = commands[i];
       vector<int> new_arr;
       int start = temp[0];
       int end = temp[1];
       int choice = temp[2];
       
       for(int j = start; j <= end; j++)
       {
          new_arr.push_back(array[j - 1]); 
       }
        sort(new_arr.begin(),new_arr.end());
       answer.push_back(new_arr[choice - 1]);   
    }
    return answer;
}