#include <bits/stdc++.h>
#include <unordered_map> 

using namespace std;

const int Max = 100000;

int Manhattan(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
	vector<vector<bool>> isVisited(Max, vector<bool>(Max, 0));
	map<pair<int, int>, int> sum;
	string firstWire;
	string secondWire;
	int curX = Max / 2; //central port x coordinate
	int curY = Max / 2; //central port y coordinate
	cin >> firstWire;
	istringstream iss(firstWire);
	string curStep;
	isVisited[curX][curY] = 1;
	
	while (std::getline(iss, curStep, ','))
    {
        char step = curStep[0];
        int dist = stoi(curStep.substr(1));
        if (step == 'L') {
        	for (int y = curY - 1; y >= curY - dist; --y) {
        		isVisited[curX][y] = 1;
        		sum[{curX, y}] = sum[{curX, y + 1}] + 1; 
        	}
        	curY = curY - dist;
        	
        } else if (step == 'R') {
        	for (int y = curY + 1; y <= curY + dist; ++y) {
        		isVisited[curX][y] = 1;
        		sum[{curX, y}] = sum[{curX, y - 1}] + 1; 
        	}
        	curY = curY + dist;
        } else if (step == 'D') {
        	for (int x = curX + 1; x <= curX + dist; ++x) {
        		isVisited[x][curY] = 1;
        		sum[{x, curY}] = sum[{x - 1, curY}] + 1;
        	}
        	curX = curX + dist;
        } else {
        	for (int x = curX - 1; x >= curX - dist; --x) {
        		isVisited[x][curY] = 1;
        		sum[{x, curY}] = sum[{x + 1, curY}] + 1;
        	}
        	curX = curX - dist;
        }
    }
    cin >> secondWire;
    istringstream iss2(secondWire);
    curX = Max / 2;
    curY = Max / 2;
    int no_steps = 0;
    int minSteps = 1e9;
    while (std::getline(iss2, curStep, ','))
    {
        char step = curStep[0];
        int dist = stoi(curStep.substr(1));
         if (step == 'L') {
        	for (int y = curY - 1; y >= curY - dist; --y) {
        		++no_steps;
        		if (isVisited[curX][y]) {
        			minSteps = min(minSteps, no_steps + sum[{curX, y}]);
        				
        		}
        	}
        	curY = curY - dist;
        	
        } else if (step == 'R') {
        	for (int y = curY + 1; y <= curY + dist; ++y) {
        		++no_steps;
        		if (isVisited[curX][y]) {
        			minSteps = min(minSteps, no_steps + sum[{curX, y}]);
        		}
        	}
        	curY = curY + dist;
        } else if (step == 'D') {
        	for (int x = curX + 1; x <= curX + dist; ++x) {
        		++no_steps;
        		if (isVisited[x][curY]){
        			minSteps = min(minSteps, no_steps + sum[{x, curY}]);
        		}
        	}
        	curX = curX + dist;
        } else {
        	for (int x = curX - 1; x >= curX - dist; --x) {
        		++no_steps;
        		if (isVisited[x][curY]){
        			minSteps = min(minSteps, no_steps + sum[{x, curY}]);
        		}
        	}
        	curX = curX - dist;
        }
    }
    cout << minSteps;
  
	return 0;
}