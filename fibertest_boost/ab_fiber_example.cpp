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
        boost::fibers::fiber([&]() {
            do {
                print_a();
                i++;
            } while (i < 20);
            }).detach();

        boost::fibers::fiber([&]() {
            do {
                i++;
                print_b();
            } while (i < 20);
            }).detach();
        // fibers zijn nog niet gestart


        printf("End of RunExample\n"); // de main functie returned en dan word de join opgeroepen op alle fibers

        // start de fibers
        
        return 0;
	}
};