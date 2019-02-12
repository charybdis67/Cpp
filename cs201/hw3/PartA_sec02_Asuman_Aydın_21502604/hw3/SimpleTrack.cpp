
#include "SimpleTrack.h"
#include <string>

using namespace std;

Track::Track(string name)

{
       trackName = name;
}
Track::~Track ()
{}
Track::Track (const Track &trackToCopy)
{

    trackName = trackToCopy.trackName;
}
void Track::operator=(const Track &right)
{

    trackName = right.trackName;

}
string Track:: getTrackName()
{
    return trackName;
}
void Track:: setTrackName(string setName)
{
    trackName = setName;
}
