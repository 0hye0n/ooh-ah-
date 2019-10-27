#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <vector>

using namespace std;

//mutex mtx;

void solve(int &num, mutex &m)
{
    lock_guard<mutex> lock(m);
    for(int i = 0; i < 100; i++)
    {
        cout<<i<<"num == "<<num<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int cnt = 0;
    mutex mtx;
    vector<thread> threads;

    for(int i = 0; i < 10; i++)
    {
        threads.push_back(thread(solve, ref(cnt), ref(mtx)));
    }

    //for(auto p : threads) p.join();

    for(int i = 0; i < 10; i++)
    {
        threads[i].join();
    }

    cout<<"finishied"<<"\n";

    return 0;
}