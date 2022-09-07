// 튜플.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    
    vector<int> answer;
    vector<pair<int, vector<int>>> parsing_str;
    vector<int> RestoreNumber;
    int string_size = s.size();
    
    string Temp_Restore = "";
    
    for (int i = 1; i < string_size - 1; i++)
    {
        if (s[i] == '{')
        {
            continue;
        }
        else if (s[i] == '}')
        {
            //그동안의 사이즈를 parsing_str 담고 
            //그와 함께 vector를 담는다. 
            RestoreNumber.push_back(stoi(Temp_Restore));
            Temp_Restore.clear();
            parsing_str.push_back(make_pair(RestoreNumber.size(), RestoreNumber));
            RestoreNumber.clear();
        }
        else
        {
            //여기는 이제 문자로 이루어진 숫자가 들어왔다. 
            //쉼표를 만나기 전까지 문자를 더해주다가 쉽표를 만나면 그때 인티저로 변경. 
            if (s[i] == ',')
            {
                if (s[i-1] == '}')
                    continue;

                int Change_Integer = stoi(Temp_Restore);
                RestoreNumber.push_back(Change_Integer);
                Temp_Restore.clear();
            }
            else
            {
                Temp_Restore += s[i];
            }
        }
    }


    sort(parsing_str.begin(), parsing_str.end());

    answer.push_back(parsing_str[0].second[0]);

    for (vector<pair<int, vector<int>>>::iterator itr = parsing_str.begin(); itr != parsing_str.end(); itr++)
    {
       
        for (vector<int>::iterator itr2 = itr->second.begin(); itr2 != itr->second.end(); itr2++)
        {
            auto it = find(answer.begin(), answer.end(), *itr2);

            if (it == answer.end())
            {
                answer.push_back(*itr2);
            }
            else
            {
                continue;
            }
        }
        
    }

    return answer;
}


int main()
{
     vector<int> result = solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
     for (vector<int>::iterator itr = result.begin(); itr != result.end(); itr++)
     {
         std::cout << *itr << " ";
     }
     std::cout << std::endl;
    return 0;
}