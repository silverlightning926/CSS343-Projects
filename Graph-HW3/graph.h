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
  Graph() = default;

  Graph(const Graph &other) = delete;

  Graph(Graph &&other) = delete;

  Graph &operator=(const Graph &other) = delete;

  Graph &operator=(Graph &&other) = delete;

  friend std::ostream &operator<<(std::ostream &out, const Graph &graph);

  bool readFile(const std::string &filePath);

  bool contains(const std::string &label) const;

  int verticesSize() const;

  int edgesSize() const;

  int vertexDegree(const std::string &label) const;

  std::string getEdgesAsString(const std::string &label) const;

  std::vector<std::string> getEdgesAsList(const std::string &label) const;

  std::map<std::string, int> getEdgesAsMap(const std::string &label) const;

  bool connect(const std::string &startVertex, const std::string &endVertex,
               int weight);

  void dfs(const std::string &startLabel, void visit(const std::string &label));

  void bfs(const std::string &startLabel,
           void visit(const std::string &label)) const;

  bool add(const std::string &label);

  bool disconnect(const std::string &from, const std::string &to);

private:
  std::vector<std::string> header_;
  std::vector<std::vector<int>> adjMatrix_;

  void dfsHelper(const std::string &startLabel,
                 void visit(const std::string &label),
                 std::vector<std::string> &visited);
};

#endif // GRAPH_P3_GRAPH_H