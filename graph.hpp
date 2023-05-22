#pragma once
#include <iostream>
using namespace std;

// v: number of vertices
// e: number of edges
// A graph can be represented using 3 data structures: adjacency matrix, adjacency list and adjacency set

// Representation of a simple graph (Biểu diễn đơn đồ thị)
// Adjacency matrix without weights (Ma trận kề không trọng số)
void initializeGraph(bool **graph, const int &v)
{
    graph = new bool* [v];
    for (int i = 0; i < v; i++)
    {
        graph[i] = new bool [v];
        for (int j = 0; j < v; j++)
        {
            graph[i][j] = 0;
        }
    }
}
void inputGraph(bool **graph, const int &e)
{
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        // only line below if the graph is directed
        graph[x][y] = 1;
        // both lines above and below if the graph is undirected
        graph[y][x] = 1;
    }
}
bool isAdjacent(bool **graph, const int &firstVertex, const int &secondVertex)
{
    return graph[firstVertex][secondVertex] == 1;
}
void listAdjacentVertices(bool **graph, const int &v, const int &target)
{
    bool isAdjacent = false;

    for (int i = 0; i < v; i++)
    {
        if (graph[target][i] == 1)
        {
            isAdjacent = true;
            cout << i << ' ';
        }
    }

    if (!isAdjacent)
    {
        cout << "There's no adjacent vertex!\n";
    }
}

// Adjacency matrix with weights (Ma trận kề có trọng số)
void initializeGraph(int **graph, const int &v)
{
    graph = new int* [v];
    for (int i = 0; i < v; i++)
    {
        graph[i] = new int [v];
        for (int j = 0; j < v; j++)
        {
            graph[i][j] = 0;
        }
    }
}
void inputGraph(int **graph, const int &e)
{
    int x, y, weight;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> weight;
        // only line below if the graph is directed
        graph[x][y] = weight;
        // both lines above and below if the graph is undirected
        graph[y][x] = weight;
    }
}
bool isAdjacent(int **graph, const int &firstVertex, const int &secondVertex)
{
    return graph[firstVertex][secondVertex] != 0;
}
void listAdjacentVertices(int **graph, const int &v, const int &target)
{
    bool isAdjacent = false;

    for (int i = 0; i < v; i++)
    {
        if (graph[target][i] != 0)
        {
            isAdjacent = true;
            cout << i << ' ';
        }
    }

    if (!isAdjacent)
    {
        cout << "There's no adjacent vertex!\n";
    }
}