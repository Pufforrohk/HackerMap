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
    // Test on a few IP
    string unitn = "193.205.211.2";
    string avgn = "206.190.138.228";
    geo.messages.push(unitn);
    geo.messages.push(avgn);
    for(int i=0; i<2; i++) {
        auto mapping = queue.pop();
        auto coords = mapping.coords;
        cout<<mapping.address<<" "<<coords.latitude<<" "<<coords.longitude << endl;
    }
    geo.terminate();
    geo.join();
    return 0;
}
