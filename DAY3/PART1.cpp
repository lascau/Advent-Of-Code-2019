#include <bits/stdc++.h>

using namespace std;

const int Max = 100000;

int Manhattan(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
int main() {
	vector<vector<bool>> isVisited(Max, vector<bool>(Max, 0));
	int minDist = 1e9;
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
        	}
        	curY = curY - dist;
        	
        } else if (step == 'R') {
        	for (int y = curY + 1; y <= curY + dist; ++y) {
        		isVisited[curX][y] = 1;
        	}
        	curY = curY + dist;
        } else if (step == 'D') {
        	for (int x = curX + 1; x <= curX + dist; ++x) {
        		isVisited[x][curY] = 1;
        	}
        	curX = curX + dist;
        } else {
        	for (int x = curX - 1; x >= curX - dist; --x) {
        		isVisited[x][curY] = 1;
        	}
        	curX = curX - dist;
        }
    }
    cin >> secondWire;
    istringstream iss2(secondWire);
    curX = Max / 2;
    curY = Max / 2;
    int nr = 0;
    while (std::getline(iss2, curStep, ','))
    {
        char step = curStep[0];
        int dist = stoi(curStep.substr(1));
    
         if (step == 'L') {
        	for (int y = curY - 1; y >= curY - dist; --y) {
        		if (isVisited[curX][y]) {
        			minDist = min(minDist, Manhattan(Max / 2,  Max / 2, curX, y));
        		}
        	}
        	curY = curY - dist;
        	
        } else if (step == 'R') {
        	for (int y = curY + 1; y <= curY + dist; ++y) {
        		if (isVisited[curX][y]) {
        			minDist = min(minDist, Manhattan(Max / 2, Max / 2, curX, y));
        		}
        	}
        	curY = curY + dist;
        } else if (step == 'D') {
        	for (int x = curX + 1; x <= curX + dist; ++x) {
        		if (isVisited[x][curY]){
        			minDist = min(minDist, Manhattan(Max / 2, Max / 2, x, curY));
        		}
        	}
        	curX = curX + dist;
        } else {
        	for (int x = curX - 1; x >= curX - dist; --x) {
        		if (isVisited[x][curY]){
        			minDist = min(minDist, Manhattan(Max / 2,  Max / 2, x, curY));
        		}
        	}
        	curX = curX - dist;
        }
    }
    cout << minDist;
	return 0;
}