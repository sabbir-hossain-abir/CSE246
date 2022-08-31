#include <bits/stdc++.h>
using namespace std;

#define V 5

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
	for (int i = 0; i < V; i++)
		if (sptSet[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;
	return min_index;
}

void printPath(int parent[], int j)
{
	if (parent[j] == -1)
		return;
	printPath(parent, parent[j]);
	cout << j << " ";
}

int printSolution(int dist[], int n, int parent[])
{
	int src = 0;
	cout << "Vertex\t Distance\tPath";
	for (int i = 1; i < V; i++) {
		printf("\n%d -> %d \t\t %d\t\t%d ", src, i, dist[i],
			src);
		printPath(parent, i);
	}
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];

	bool sptSet[V] = { false };

	int parent[V] = { -1 };

	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {

		int u = minDistance(dist, sptSet);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			if (!sptSet[v] && graph[u][v]
				&& dist[u] + graph[u][v] < dist[v]) {
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}
	printSolution(dist, V, parent);
}


int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0},
						{ 4, 0, 8, 0, 0},
						{ 0, 8, 0, 7, 0},
						{ 0, 0, 7, 0, 9},
						{ 0, 0, 2, 0, 0} };
/*int path=5;
switch(path) {
    case 0:
        cout << "A";
        break;
    case 1:
        cout << "B";
        break;
    case 2:
        cout << "C";
        break;
    case 3:
        cout << "D";
        break;
    case 4:
        cout << "E";
        break;

}*/
    dijkstra(graph, 0);
 
    return 0;
}