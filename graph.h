#include "dslib.h"

class Vertex {
    friend ostream& operator << (ostream& os, Vertex& v);
    friend class Graph;
    typedef pair<int, Vertex*> ve;
    vector<ve> adj; //cost of edge, destination Vertex
    string name;
    bool is_visited;
    Vertex(const string& s) : name(s) {}
};

class Graph
{
public:
    typedef map<string, Vertex *> vmap;
    vmap work;
    Graph();
    void bfs(const string& v);
    void dfs(const string& v);
    void dfsUtil(const string& v);
    void addVertex(const string&);
    void addEdge(const string& from, const string& to, double cost);
};

