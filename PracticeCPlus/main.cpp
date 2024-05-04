//
//  main.cpp
//  PracticeCPlus
//
//  Created by 황재민 on 5/4/24.
//

#include <iostream>
#include <vector>
using namespace std;
int* Sort(int nNum);
void AddSum(int nCount, int nNum);
void CalcAverage();
int Gift(vector<string> friends, vector<string> gifts);
int CalcBandage(vector<int> bandage, int health, vector<vector<int>> attacks);

int main(int argc, const char * argv[]) {
    
    vector<int> bandage = {5, 1, 5};
    int health = 30;
    vector<vector<int>> attacks = {{2, 10}, {9, 15}, {10, 5}, {11, 5}};
    CalcBandage(bandage, 30, attacks);
}
