#include "circuit.h"
#include<chrono>
using namespace std::chrono;

int main()
{
    Circuit qc(4);

    auto start = high_resolution_clock::now();

    qc.apply(H(), {0});

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout<<"Gate application time: "<< duration.count() << " miliseconds" << '\n';

    qc.apply(H(), {1});
    qc.apply(H(), {2});
    qc.apply(H(), {3});
    //qc.printStateVector();
    // measurement test
    std::cout<<"Starting measurement\n";
    start = high_resolution_clock::now();
    std::vector<int> outcomes = qc.measureAll();
    std::cout<<"Measurement outcome:\n";
    for (int a:outcomes)
    {
        std::cout << a;
    }
    std::cout<<'\n';
    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);

    std::cout<<"Measurement time: "<<duration.count()<<'\n';
    std::cout<<"After measurement\n";
    qc.printStateVector();
}
