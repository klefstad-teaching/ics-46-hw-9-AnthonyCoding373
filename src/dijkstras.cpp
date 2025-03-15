#include "dijkstras.h"

string get_arg(int argc, char *argv[], string def)
{
    if (argc > 1)
    {
        return argv[1];
    }

    return def;
}

vector<int> dijkstra_shortest_path(Graph& G, int source, vector<int>& previous)
{
    int n = G.numVertices;

    G.distances.resize(n, INF);
    vector<int> prev(n, -1);
    previous = prev;
    G.visited.resize(n, false);

    priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
    pq.push(Vertex(source, 0));
    G.distances[source] = 0;

    while (!pq.empty())
    {
        int current_node = pq.top().vertex;
        pq.pop();

        if (G.visited[current_node]) continue;

        G.visited[current_node] = true;

        for (Edge &e : G[current_node])
        {
            int vertex = e.dst;
            int weight = e.weight;

            if (!G.visited[vertex] && G.distances[current_node] + weight < G.distances[vertex])
            {
                G.distances[vertex] = G.distances[current_node] + weight;
                previous[vertex] = current_node;
                pq.push(Vertex(vertex, G.distances[vertex]));
            }
        }        
    }

    return G.distances;
}

vector<int> extract_shortest_path(const vector<int>& previous, int destination)
{
    stack<int> path;
    int parent = previous[destination];
    path.push(destination);
    while (parent >= 0)
    {
        path.push(parent);
        parent = previous[parent];
    }

    vector<int> actual_path;
    while (!path.empty())
    {
        int top = path.top();
        path.pop();
        actual_path.push_back(top);
    }
    return actual_path;
}

void print_path(const vector<int>& v, int total)
{
    for (auto &s : v)
    {
        cout << s << " ";
    }

    cout << endl;

    cout << "Total cost is " << total << endl;
}