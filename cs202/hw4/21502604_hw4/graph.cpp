
/** @file Graph.cpp
 * An adjacency list representation of an undirected graph.
*/
/*
* Title : Hash Tables, Graphs
* Author : Asuman Aydin
* ID : 21502604
* Section : 01
* Assignment : 4
* Description :
*/
#include "graph.h"
/*Do not add new libraries or files*/

Graph::Graph()
{
    performerCount = 0;
}  // end constructor

void Graph::addPerformer(string performerName)
{
    /*YOUR IMPLEMENTATION*/
    list<node> performer;

    performerCount++;
}  // end addPerformer

void Graph::addEdge(string movieTitle, string performer1, string performer2, string director)
{
    /*YOUR IMPLEMENTATION*/
    node* newEdge = new node;
    newEdge->director = director;
    newEdge->movie = movieTitle;



}  // end addEdge

list<string> Graph::getMovies(string performerName)
{
    /*YOUR IMPLEMENTATION*/



}  // end getMovies

list<string> Graph::deletePerformers()
{
    /*YOUR IMPLEMENTATION*/



}  // end deletePerformers

map<string, int> Graph::getMostActivePerformers()
{
    /*YOUR IMPLEMENTATION*/



}  // end getMostActivePerformers

map<string, int> Graph::getPerformerNumber(string performerName)
{
    /*YOUR IMPLEMENTATION*/



}  // end getPerformerNumber

map<string, int> Graph::getFrequentPartner(string performerName)
{
    /*YOUR IMPLEMENTATION*/



}  // end getFrequentPartner

map<string, int> Graph::getFrequentDirector(string performerName)
{
    /*YOUR IMPLEMENTATION*/



}  // end getFrequentDirector


