#include <bits/stdc++.h>
using namespace std;

const int NO_PARENT = -1;

void tracePath(int currentNode, const unordered_map<int, int>& parentNodes) {
    if (currentNode == NO_PARENT) {
        return;
    }
    tracePath(parentNodes.at(currentNode), parentNodes);
    cout << char('A' + currentNode) << " ";  // Display nodes as A, B, C, etc.
}

void outputResults(int startNode, int endNode, const unordered_map<int, int>& distances, const unordered_map<int, int>& parentNodes) {
    cout << "\nThe cost of the shortest path from " << char('A' + startNode) << " to " << char('A' + endNode) << " is " << distances.at(endNode) << ".\n";
    cout << "The shortest path is: ";
    tracePath(endNode, parentNodes);
    cout << "\n";
}

void dijkstra(const unordered_map<string, unordered_map<string, int>>& graph, int startNode, int endNode) {
    int totalNodes = graph.size();
    unordered_map<int, int> shortestDistances;
    unordered_map<int, bool> processedNodes;
    unordered_map<int, int> parentNodes;

    for (int i = 0; i < totalNodes; i++) {
        shortestDistances[i] = INT_MAX;
        processedNodes[i] = false;
    }

    shortestDistances[startNode] = 0;
    parentNodes[startNode] = NO_PARENT;

    for (int i = 0; i < totalNodes - 1; i++) {
        int nearestNode = -1;
        int minDistance = INT_MAX;

        for (int nodeIndex = 0; nodeIndex < totalNodes; nodeIndex++) {
            if (!processedNodes[nodeIndex] && shortestDistances[nodeIndex] < minDistance) {
                nearestNode = nodeIndex;
                minDistance = shortestDistances[nodeIndex];
            }
        }

        processedNodes[nearestNode] = true;

        // Convert nearestNode to string for graph access
        string nearestNodeStr(1, 'A' + nearestNode);

        for (const auto& [neighbor, edgeCost] : graph.at(nearestNodeStr)) {
            int neighborIndex = neighbor[0] - 'A';  // Convert string key to index (e.g., "B" -> 1)
            if (!processedNodes[neighborIndex]) {
                int newDistance = shortestDistances[nearestNode] + edgeCost;
                if (newDistance < shortestDistances[neighborIndex]) {
                    shortestDistances[neighborIndex] = newDistance;
                    parentNodes[neighborIndex] = nearestNode;
                }
            }
        }
    }

    outputResults(startNode, endNode, shortestDistances, parentNodes);
}

int main() {
    unordered_map<string, unordered_map<string, int>> graph = {
        {"A", {{"B", 10}, {"E", 3}}},
        {"B", {{"E", 4}, {"C", 2}}},
        {"C", {{"D", 9}}},
        {"D", {{"C", 7}}},
        {"E", {{"B", 1}, {"D", 2}, {"C", 8}}}
    };

    char startChar, endChar;
    cout << "Enter the starting node: ";
    cin >> startChar;
    cout << "Enter the ending node: ";
    cin >> endChar;

    int startNode = startChar - 'A';  // Convert char to index
    int endNode = endChar - 'A';

    dijkstra(graph, startNode, endNode);

    return 0;
}
