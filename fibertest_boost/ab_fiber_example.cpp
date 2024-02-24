#include <iostream>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <boost/fiber/all.hpp>
using namespace std;

class AbFiberExample {
private:
    static void print_a()
    {
        cout << "a";
        boost::this_fiber::yield();
    }

    static void print_b()
    {
        cout << "b";
        boost::this_fiber::yield();
    }
public: 
	static int RunExample() {
        int i = 0;
        boost::fibers::fiber fiberA([&]() {
            do {
                print_a();
                i++;
            } while (i < 20);
            });

        boost::fibers::fiber fiberB([&]() {
            do {
                i++;
                print_b();
            } while (i < 20);
            });
        // fibers zijn nog niet gestart

        fiberA.join();
        fiberB.join();


        printf("End of RunExample\n"); // de main functie returned en dan word de join opgeroepen op alle      
        return 0;
	}
};

// Lijkt erop dat je geen fibers gewoon kan aanmaken in een functie zonder ze detachen en ze dan niet de joinen.
// Als je ze niet joint moet je detachend en andersom.