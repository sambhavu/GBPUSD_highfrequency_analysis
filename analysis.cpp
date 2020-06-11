#include<algorithm>
#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<iomanip>
using namespace std;


class analysis{
public:

    vector<double> gbpusd;
    void getdata();
    void analyze();


};

void analysis :: getdata()
{
    ifstream infile;
    infile.open("/users/satish/Desktop/gbpusd_seconds_q12020A.txt");
    double data;
    while(!infile.eof())
    {
        infile>>data;
        gbpusd.push_back(data);
    }
}


void analysis::analyze()
{
    int size;
    size = gbpusd.size();
    double change;
    double move;
    double totalchange;

    int up, down, unch;

    for(int i = 1; i<size; ++i)
    {
        change = gbpusd[i] - gbpusd[i-1];
        move += fabs(change);
        totalchange +=change;

        if(change>0)
        {
            up++;
        }
        else if(change<0)
        {
            down++;
        }
        else{
            unch++;
        }
    }
    move = move/(double)size;

    cout<<"Net Change: "<<std::fixed<<std::setprecision(10)<<totalchange;
    cout<<"\nAverage Move: "<<std::fixed<<std::setprecision(10)<<move;
    cout<<"\nUP Moves: "<<up;
    cout<<"\nDown Moves: "<<down;
    cout<<"\nUnch Moves: "<<unch;

}


int main()
{
    analysis forex;
    forex.getdata();
    forex.analyze();

    return 0;
}

/*
Net Change: -0.1370900000
Average Move: 0.0000232557
UP Moves: 892896
Down Moves: 910761
Unch Moves: 897168
Process finished with exit code 0
*/
