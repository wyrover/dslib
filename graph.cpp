#include "graph.h"
#include "dslib.h"

Vertex::Vertex(const string& name )
{


}

void Graph::addVertex(const string &name)
{
    vmap::iterator itr = work.find(name);
    if (itr == work.end())
    {
        Vertex *v;
        v = new Vertex(name);
        work[name] = v;
        return;
    }
    cout << "\nVertex already exists!";
}

void Graph::addedge(const string& from, const string& to, double cost)
{
    Vertex *f = (work.find(from)->second);
    Vertex *t = (work.find(to)->second);
    pair<int, Vertex *> edge = make_pair(cost, t);
    f->adj.push_back(edge);
}

Graph::Graph()
{


}

void Graph::dfs(const string& start_vert)
{




}

void Graph::bfs(const string& start_vert)
{
    Vertex* f = work.find(start_vert)->second;

    queue<Vertex> bfs_q;

    bfs_q.push(*f);
    while (!bfs_q.empty()) {


    }

}
