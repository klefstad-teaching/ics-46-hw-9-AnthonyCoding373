#include "dijkstras.h"

int main(int argc, char *argv[])
{
    string filename = get_arg(argc, argv, "./small.txt");
    Graph G;
    file_to_graph(filename, G);

    vector<int> previous;
    vector<int> distances = dijkstra_shortest_path(G, 0, previous);

    int distance_size = distances.size();
    for (int i = 0; i < distance_size; ++i)
    {
        vector<int> shortestPath = extract_shortest_path(distances, previous, i);
        print_path(shortestPath, distances[i]);
    }
}