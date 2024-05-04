//
//  bandage.cpp
//  PracticeCPlus
//
//  Created by 황재민 on 5/4/24.
//

#include <string>
#include <vector>

using namespace std;

int CalcBandage(vector<int> bandage, int health, vector<vector<int>> attacks){
    int nSecond = bandage[0];
    int nPerHeal = bandage[1];
    int nTotalHeal = bandage[2];
    int nCurrent = 0;
    int nCurrentHealth = health;
    
    unsigned long nSize = attacks.size();
    int nLastTime = attacks[nSize-1][0];
    
    for(int nTime = 1 ; nTime <= nLastTime ; nTime++){
        if(attacks.size() == 0 || nCurrentHealth <= 0)
            break;
        
        vector<int> monster = attacks[0];
        if(nTime == monster[0])
        {
            nCurrent = 0;
            nCurrentHealth -= monster[1];
            attacks.erase(attacks.begin());
        }
        
        else
        {
            ++nCurrent;
            if(nCurrentHealth + nPerHeal >= health)
                nCurrentHealth = health;
            else
                nCurrentHealth += nPerHeal;
            
            if(nCurrent == nSecond)
            {
                if(nCurrentHealth + nTotalHeal >= health)
                    nCurrentHealth = health;
                else
                    nCurrentHealth += nTotalHeal;
                nCurrent = 0;
            }
        }
    }
    
    
    if(nCurrentHealth <= 0)
        return -1;
    else
        return nCurrentHealth;
}

