
#ifndef __SIMPLE_TRACK_H
#define __SIMPLE_TRACK_H
#include <string>
using namespace std;
class Track
{
public:
    Track(const string tname = "");
    ~Track ();
    Track (const Track &trackToCopy);
    void operator=(const Track &right);
    string getTrackName();
    void  setTrackName(string setName);
private:
    string trackName;
};
#endif
