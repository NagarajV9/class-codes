#include<iostream>
#include<vector>
using namespace std;



int main()
{
        vector<int> cont;
        cont.push_back(3);
        cont.push_back(5);
        cont.push_back(1);
        cont.push_back(8);
        cont.push_back(10);
        vector<int>::iterator i;
        int t;
        int ele=8;
        for(t=0,i=cont.begin();i!=cont.end();i++,t++)
        {
             if(*i==ele)
               {

                  cout<<t<<endl;
                  break;
                 }
       }
       for(t=0,i=cont.begin();i!=cont.end();i++)
       {
             if(*i==ele)
               t++;
       }
       cout<<t<<endl;
        return 0;
}
