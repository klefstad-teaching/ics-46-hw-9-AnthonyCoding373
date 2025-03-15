#include "dijkstras.h"

int main(int argc, char *argv[])
{
    string filename = get_arg(argc, argv, "./small.txt");
    Graph G;
    file_to_graph(filename, G);

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);

    for (int i : previous)
    {
        print_path(previous, G.distances[i]);
    }
}