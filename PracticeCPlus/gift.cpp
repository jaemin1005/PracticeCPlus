//
//  gift.cpp
//  PracticeCPlus
//
//  Created by 황재민 on 5/4/24.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int Gift(vector<string> friends, vector<string> gifts) {
    
    vector<string>::iterator iter;
    int nSize = (int)friends.size();
    
    int** npArr = new int*[nSize];

    for(int i = 0 ; i < nSize ; i++)
    {
         npArr[i] = new int[nSize];
    }
    
    
    for(iter = gifts.begin() ; iter < gifts.end() ; iter++)
    {
        stringstream ss(*iter);
        string strArr[2];
        string strSplit;
        int nArrIdx[2];
        int nIdx = 0;
        while(ss >> strSplit){
            strArr[nIdx] = strSplit;
            nIdx++;
        }
        
        for(int i = 0 ; i < 2 ; i++)
        {
            string strFindValue = strArr[i];
            vector<string>::iterator iter2 = find(friends.begin(), friends.end(), strFindValue);
            int nFindIdx = (int)std::distance(friends.begin(), iter2);
            nArrIdx[i] = nFindIdx;
        }
        
        npArr[nArrIdx[0]][nArrIdx[1]] = npArr[nArrIdx[0]][nArrIdx[1]] + 1;
    }
    
    for(int i = 0 ; i < nSize ; i++)
    {
        for(int j = 0 ; j < nSize ; j++)
        {
            cout << npArr[i][j] << " ";
        }
        cout << "\n";
    }
            
    int *npGiftCount = new int[nSize];
    for(int i = 0 ; i < nSize ; i++)
    {
        int nGiveCount = 0;
        int nReceiveCount = 0;
        for(int j = 0 ; j < nSize ; j++)
        {
            nGiveCount += npArr[i][j]; // i가 j에게 준 선물의 수
            nReceiveCount += npArr[j][i]; // j가 i에게 준 선물의 수
        }
        npGiftCount[i] = nGiveCount - nReceiveCount; // 선물 지수 계산
    }
    
    for(int i = 0 ; i < nSize ; i++)
        cout << npGiftCount[i] << " ";
    cout << "\n";
    
    int *npAmountGift = new int[nSize];
    for(int i = 0 ; i < nSize ; i++)
    {
        int nGiftCount = 0;
        for(int j = 0 ; j < nSize ; j++)
        {
            if(npArr[i][j] > npArr[j][i])
                nGiftCount += 1;
            else if(npArr[i][j] == npArr[j][i])
            {
                if(npGiftCount[i] > npGiftCount[j])
                    nGiftCount += 1;
            }
            
            else
                nGiftCount -= 1;
        }
        
        npAmountGift[i] = nGiftCount;
    }

    
    
    int answer = 0;
    for(int i = 0 ; i < nSize ; i++){
        if(answer < npAmountGift[i])
            answer = npAmountGift[i];
    }
    
    return answer;
}


