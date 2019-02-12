#include <cstddef>
#include "SimpleACS.h"
#include <iostream>

using namespace std;


ACS::ACS ()
{
    head = NULL;
    name =  " ";
    topic = " ";
    trackCount = 0;

}
ACS::~ACS ()
{
    TrackNode* current = head;

    while(current != NULL)
    {
        TrackNode* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
}
ACS::ACS (const ACS& acsToCopy)
{
    if(acsToCopy.head == NULL)
        head = NULL;
    else
    {
        head  = new TrackNode;
        head->t = acsToCopy.head->t;
        TrackNode *newNode = head;
        TrackNode *original = acsToCopy.head->next;
        while(newNode != NULL)
        {
            newNode->next = new TrackNode;
            newNode = newNode ->next;
            newNode->t = original->t;
        }
        newNode->next = NULL;
    }
}
void ACS:: operator=(const ACS& right)
{
    if(right.head == NULL)
        head = NULL;
    else
    {
        head  = new TrackNode;
        head->t = right.head->t;
        TrackNode *newNode = head;
        TrackNode *original = right.head->next;
        while(newNode != NULL)
        {
            newNode->next = new TrackNode;
            newNode = newNode ->next;
            newNode->t = original->t;
        }
        newNode->next = NULL;
    }
}
bool ACS:: addTrack(const string trackName)
{
    TrackNode *temp = new TrackNode;
    (temp->t).setTrackName(trackName);
    TrackNode* current = head;
    bool state = false;
    bool added = false;
    if(current == NULL)
    {
        temp->next = head;
        head = temp;
        added = true;
    }
    else
    {
        while(current != NULL)
        {
            if(current->t.getTrackName() == trackName)
            {
                state = true;
                break;
            }
            current = current-> next;
        }
        if(state)
        {
            added = false;
        }
        else
        {
            current = head;
            while(current->next != NULL)
            {
                current = current-> next;
            }
            temp-> next = current-> next;
            current->next = temp;
            added = true;
        }
    }
    return added;
}

bool ACS:: removeTrack (const string trackName)
{
    TrackNode* current = head;
    bool removed = false;
    if(head == NULL)
    {
        removed = false;
    }
    else
    {
        TrackNode* found = findTrack(trackName);
        if(found != NULL)
        {
            if(head == found)
            {
                TrackNode* temp = head;
                head = head->next;
                delete temp;
                removed = true;
            }
            else
            {
                TrackNode* prev = current;
                while(current != found)
                {
                    prev = current;
                    current = current->next;
                }
                prev->next = current->next;
                delete current;
                removed = true;
            }
        }
        else
            removed = false;
    }
    return removed;
}
void ACS:: displayTracks()
{
    TrackNode* current = head;
    if(current == NULL)
    {
        cout<< "EMPTY" << endl;
    }
    while( current != NULL)
    {
        cout<<"TrackName  " << current ->t.getTrackName() << endl;
        current = current-> next;
    }
}

ACS::TrackNode *ACS::findTrack(string trackName)
{
    TrackNode* searched = NULL;
    TrackNode* current = head;

    if(current == NULL)
        return searched;
    else
    {
        Track x = current ->t;
        while( current != NULL)
        {
            if(x.getTrackName() == trackName)
            {
                searched = current;
                break;
            }
            current = current->next;
            x = current->t;
        }
    }
    return searched;
}
