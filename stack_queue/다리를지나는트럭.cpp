#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
 int answer = 0;

int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int current_weight = 0;
    
    queue<int>truck_count;
    queue<int>distance_truck;
    
    while(1)
    {
            
        int size = distance_truck.size();
        for(int i = 0; i < size; i++)
        {
            int length = distance_truck.front();
            distance_truck.pop();
            
            if(length <= 1)
            {
                current_weight -= truck_count.front();
                truck_count.pop();
                continue;
            }
            distance_truck.push(length - 1);
        }
        
        if(truck_weights.size() > 0 &&  current_weight + truck_weights[0] <= weight)
        {
            truck_count.push(truck_weights[0]);
            current_weight = current_weight + truck_weights[0];
            distance_truck.push(bridge_length);
            truck_weights.erase(truck_weights.begin());
        }
        answer++;
        if(truck_weights.size() == 0 && distance_truck.size() == 0)
        {
            break;
        }
    }
    return answer;
}

