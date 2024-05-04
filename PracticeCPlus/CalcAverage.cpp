//
//  CalcAverage.cpp
//  PracticeCPlus
//
//  Created by 황재민 on 5/4/24.
//

#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

void CalcAverage(){
    
    double dTotal = 0;
    double dAverage;
    int nCount;
    
    /**
     * cin 입력시 enter키 버퍼에 남아, 다음 cin호출시 넘어갈 수 있음.
     * cin.ignore()를 통해 버퍼를 지워주자.
     */
    cout << "과목 수를 입력하세요\n";
    cin >> nCount;
    cin.ignore();
    
    int* nArr = new int[nCount];
    string strScores;
    
    
    cout << "성적을 입력하세요\n";
    getline(cin, strScores);
    
    /**
     * 공백 분리하기.
     */
    stringstream ss(strScores);
    string strScore;
    

    
    int nMax = 0;
    int nSearch = 0;
    while(ss >> strScore){
        int nScore = stoi(strScore);
        if(nMax < nScore)
        {
            nMax = nScore;
        }
        
        nArr[nSearch] = nScore;
        nSearch++;
    }
    
    for(int nIdx = 0 ; nIdx < nCount ; nIdx++){
        dTotal += nArr[nIdx];
    }
    
    cout << "Total : " << dTotal << "\n";
    cout << "nMax : " << nMax << "\n";
    dAverage = dTotal * 100 / (double)nMax / (double)nCount;
    cout << "\n" << dAverage << "\n";
}
