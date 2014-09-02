#include <lookup.hh>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

namespace lookup
{

    Mapping::Mapping(const std::string& _address, Coords _coords)
        : address(_address), coords(_coords)
    {
    }

    Coords::Coords(double lt, double lg)
        : longitude(lg),
          latitude(lt)
    {
    }

    GeoIp::GeoIp(const std::string &srv)
        : server(srv)
    {
    }

    Coords GeoIp::lookup(const std::string &address)
    {
        // Horrible temporary version
        // For each address, new query to the server
        // It also depends on wget
        FILE* f = popen(("wget -q -O - freegeoip.net/csv/" + address).c_str(),"r");
        char buffer[1024];
        if(fgets(buffer,1024,f)==NULL)
            ;
        std::string s(buffer);
        std::vector<std::string> parsed;
        int cur = 0;
        for(int i=0; i<10; i++) {
            int next = s.find(",",cur);
            parsed.push_back(s.substr(cur+1,next-cur-2));
            cur = next+1;
        }
        // Format is: ip,countrycode,countryname,regioncode,regionname,city,zipcode,lat,long,metrocode,areacode
        double latitude = stod(parsed[7]);
        double longitude = stod(parsed[8]);
        fclose(f);
        return Coords(latitude, longitude);
    }

    void GeoIp::run()
    {
        assert(output);
        my_thread = std::thread([this]() {
            bool active = true;
            while(active) {
                try {
                    std::string address = messages.pop();
                    output->push(Mapping(address,lookup(address)));
                } catch(utils::Terminated &t) {
                    active=false;
                }
            }
        });
    }
    void GeoIp::terminate()
    {
        messages.terminate();
    }

    void GeoIp::set_output(utils::SafeQueue<Mapping>* output_queue)
    {
        output=output_queue;
    }
    void GeoIp::join()
    {
        my_thread.join();
    }
}
