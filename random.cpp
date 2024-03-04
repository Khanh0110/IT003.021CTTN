#include<bits/stdc++.h>
using namespace std ; 
int main()
{
    srand(time(0)) ;
    for(int j = 1 ;  j < 11; j++)
    {
        string tenfile = "songaunhien_" + to_string(j)+".txt";
        ofstream outfile(tenfile);
        if(!outfile)
        {
            cout << "err" ;
            return 1;
        }
        for(int i = 0 ; i < 1000000 ; i++)
        {
            int randomnumber = rand() % 10000000 ;  
            outfile << randomnumber << " " ;
        } 
        outfile.close();
    }
    return 0 ;
}