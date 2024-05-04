//
//  main.cpp
//  PracticeCPlus
//
//  Created by 황재민 on 5/4/24.
//

#include <iostream>
using namespace std;
int* Sort(int nNum);

int main(int argc, const char * argv[]) {
    // insert code here...
    int nNum;
    cout << "배열 수를 입력해주세요\n";
    cin >> nNum;

    int* result = Sort(nNum);

    cout <<"정렬\n";
    for(int nIdx = 0 ; nIdx < nNum ; nIdx++){
      cout << *(result+nIdx) << ",";
    }
    
    cout << "\n종료\n";
}
