
#ifndef __SIMPLE_ACS_H
#define __SIMPLE_ACS_H

#include <string>
using namespace std;
#include "SimpleTrack.h"

class ACS
{
public:
    ACS ();
    ~ACS ();
    ACS (const ACS& acsToCopy);
    void operator=(const ACS& right);
    bool addTrack(const string trackName);
    bool removeTrack (const string trackName);
    void displayTracks();



private:
    struct TrackNode
    {
        Track t;
        TrackNode* next;
    };
    TrackNode *head;
    string name;
    string topic;
    int trackCount;
    TrackNode* findTrack(string trackName);
};
#endif
