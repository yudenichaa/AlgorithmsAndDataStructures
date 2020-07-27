#pragma once
#include <cstdint>
#include <unordered_map>
#include <vector>

class Graph {
public:
    Graph();
    void addEdge(uint64_t u, uint64_t v, int64_t d);
    void addUnorderedEdge(uint64_t u, uint64_t v, int64_t d);
    std::vector<uint64_t> DFS(int64_t u) const;
    std::vector<uint64_t> BFS(uint64_t u) const;
    void DijkstraAlgorithm(uint64_t startVertex, std::vector<uint64_t> &distance, std::vector<uint64_t> &parent) const;
    static std::vector<uint64_t> restoreTheWay(uint64_t u, uint64_t v, const std::vector<uint64_t> &parent);
    std::vector<std::vector<uint64_t>> connectedComponents() const;

private:
    void DFS(std::vector<uint64_t> &vertexOrder, uint64_t u, std::vector<bool>& visited) const;
    std::vector<uint64_t> BFS(uint64_t u, std::vector<bool>& visited) const;

    struct AdjacentVertex {
        uint64_t vertex;
        int64_t distance;
    };

private:
    std::unordered_map<uint64_t, std::vector<AdjacentVertex>> adjacencyLists;
};

