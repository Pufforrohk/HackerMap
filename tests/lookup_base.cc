#include <lookup.hh>

#include <iostream>
#include <thread>
#include <safequeue.hh>
using namespace std;

int main (int argc, char **argv)
{
    lookup::GeoIp geo("geoip.example.com");
    utils::SafeQueue<lookup::Mapping> queue;
    geo.set_output(&queue);
    geo.run();
    for(int i=0; i<10; i++) {
        geo.messages.push("173.194.32.55");
    }
    for(int i=0; i<10; i++) {
        auto mapping = queue.pop();
        auto coords = mapping.coords;
        cout << coords.longitude << ", " << coords.latitude << endl;
    }
    geo.terminate();
    geo.join();
    return 0;
}
