#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std ;
void bfs(string p ,int l, vector<int> &dis, vector<int>v[] , int s)
{

    dis[s] = 0 ;
    list<int>q ;
    q.push_back(s) ;
    while(!q.empty())
    {
        s=q.front() ;
        q.pop_front();
        for(auto x:v[p[s]-'0'])
        {

            if(dis[x]==-1)
            {

                dis[x] = dis[s]+1 ;
                q.push_back(x) ;

            }
        }

    if(s-1 >=0 && dis[s-1]==-1)
    {

        dis[s-1]=dis[s]+1 ;
        q.push_back(s-1) ;
    }
    if(s+1 <=l && dis[s+1]==-1)
    {

        dis[s+1]=dis[s]+1 ;
        q.push_back(s+1) ;
    }
    }

}




int main()
{
    string s ;
    cin>>s ;
    int l = s.length() ;
    vector<int>v[l] ;
    for(int i=0  ; i<l ; i++)
    {
       v[int(s[i])-'0'].push_back(i) ;

    }

    vector<int>dis(l);
    for(int i=0 ; i<l ; i++)
        dis[i]=-1 ;
    bfs(s,l , dis , v , int(s[0])-'0') ;
    cout<<dis[l-1] ;
    return 0 ;
}
