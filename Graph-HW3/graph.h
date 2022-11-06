//
// Created by siddr on 10/26/2022.
//

#ifndef GRAPH_P3_GRAPH_H
#define GRAPH_P3_GRAPH_H

#include <map>
#include <string>
#include <vector>

class Graph {
public:

  // Sets empty constructor to default
  Graph() = default;

  // Deletes extra constructors
  Graph(const Graph &other) = delete;

  // Deletes extra constructor
  Graph(Graph &&other) = delete;

  // Deletes extra constructor
  Graph &operator=(const Graph &other) = delete;

  // Deletes extra constructor
  Graph &operator=(Graph &&other) = delete;

  // Print operator overloading
  friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

  // Reads and parses a file and creates a graph from the file
  bool readFile(const std::string &filePath);

  // Checks if given label is contained in the graph
  bool contains(const std::string &label) const;

  // Returns the amount of vertices in the graph
  int verticesSize() const;

  // Returns the amount of edges in the graph
  int edgesSize() const;

  // Returns how many vertices are connected to a vertex
  int vertexDegree(const std::string &label) const;

  // Returns edges connected to vertex as a string with weight
  std::string getEdgesAsString(const std::string &label) const;

  // Get edges connected to vertex as a list
  std::vector<std::string> getEdgesAsList(const std::string &label) const;

  // Get edges connected to vertex as map with weight
  std::map<std::string, int> getEdgesAsMap(const std::string &label) const;

  // Connects 2 vertices, creates vertices if needed
  bool connect(const std::string &startVertex, const std::string &endVertex,
               int weight);

  // DFS traversal of a graph, visit function is called on each node
  void dfs(const std::string &startLabel, void visit(const std::string &label));

  // BFS traversal of a graph, visit function is called on each node
  void bfs(const std::string &startLabel,
           void visit(const std::string &label)) const;

  // Adds a new vertex
  bool add(const std::string &label);

  // Disconnects 2 vertices
  bool disconnect(const std::string &from, const std::string &to);

private:

  // Header list that keeps track of vertex labels
  std::vector<std::string> header_;

  // 2D List that keeps track of connections between vertices and weights
  std::vector<std::vector<int>> adjMatrix_;

  // Helper function for recursive DFS traversal
  void dfsHelper(const std::string &startLabel,
                 void visit(const std::string &label),
                 std::vector<std::string> &visited);
};

#endif // GRAPH_P3_GRAPH_H