#include<bits/stdc++.h>
using namespace std ; 

int main()
{
    ifstream  input("songaunhien_1.txt") ;
    ofstream output("tangdan.txt") ;
    if(!input.is_open() || !output.is_open())
    {
        cout <<"err" ; 
        return 1;
    }
    vector<int> reads;
    int read ;
    while(input >> read)
    {
        reads.push_back(read) ;
    }
    sort(reads.begin(), reads.end());
    for(int i : reads)
    {
        output << i << " " ;
    }

    input.close();
    output.close() ;

return 0 ;
}