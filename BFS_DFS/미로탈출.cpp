#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool checkMap[101][101];

struct Point
{
    int y;
    int x;
    int cost;
};

int BFS(vector<string>& maps, int y,int x)
{
    int M = maps.size();
    int N = maps[0].size();
    
    int dy[4] = {1,-1,0,0};
    int dx[4] = {0,0,1,-1};
   
    queue<Point>Queue;
    
    Point reverFoundPoint;
    reverFoundPoint.cost = -1;
    
    Point finalFoundPoint;
    
    checkMap[y][x] = true;
    Queue.push({y,x,0});
    
    while(!Queue.empty())
    {
        Point curPoint = Queue.front();
        Queue.pop();
        
        int curY = curPoint.y;
        int curX = curPoint.x;
        int curCost = curPoint.cost;
        
        if(maps[curY][curX] == 'L')
        {
            reverFoundPoint = curPoint;
            finalFoundPoint.cost = reverFoundPoint.cost;
            break;
        }
        
        for(int k =0; k < 4; k++)
        {
            int nextY = curY + dy[k];
            int nextX = curX + dx[k];
            
            if(nextY < 0 || nextX < 0 || nextY >= M || nextX >= N  || maps[nextY][nextX] == 'X')
                continue;
            
            if(!checkMap[nextY][nextX])
            {
                Queue.push({nextY,nextX,curCost + 1});
                checkMap[nextY][nextX] = true;
            }
        }
    }
    
    if(reverFoundPoint.cost == -1)
        return -1;
    
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            checkMap[i][j] = false;
        }
    }
    
    while(!Queue.empty())
     Queue.pop();
    
    checkMap[reverFoundPoint.y][reverFoundPoint.x] = true;
    Queue.push({reverFoundPoint.y,reverFoundPoint.x,reverFoundPoint.cost});
    
    while(!Queue.empty())
    {
        Point curPoint = Queue.front();
        Queue.pop();
        
        int curY = curPoint.y;
        int curX = curPoint.x;
        int curCost = curPoint.cost;
        
        if(maps[curY][curX] == 'E')
        {
            reverFoundPoint = curPoint;
            break;
        }
        
        for(int k =0; k < 4; k++)
        {
            int nextY = curY + dy[k];
            int nextX = curX + dx[k];
            
            if(nextY < 0 || nextX < 0 || nextY >= M || nextX >= N  || maps[nextY][nextX] == 'X')
                continue;
            
            if(!checkMap[nextY][nextX])
            {
                Queue.push({nextY,nextX,curCost + 1});
                checkMap[nextY][nextX] = true;
            }
        }
    }
    
    if(reverFoundPoint.cost == finalFoundPoint.cost)
        reverFoundPoint.cost = -1;
    
    return reverFoundPoint.cost;
}

int solution(vector<string> maps) 
{
    int answer = 0;
    
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[i].size(); ++j)
        {
            if(maps[i][j] == 'S')
            {
                answer = BFS(maps,i,j);
            }
        }
    }
    
    return answer;
}