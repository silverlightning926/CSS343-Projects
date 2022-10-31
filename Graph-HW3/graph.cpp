//
// Created by siddr on 10/26/2022.
//

#include "graph.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>

std::ostream &operator<<(std::ostream &out, const Graph &graph) {
  out << "    ";

  for (const std::string &vertex : graph.header_) {
    out << vertex << "   ";
  }

  out << std::endl << "    ";

  for (int i = 0; i < graph.header_.size(); ++i) {
    out << "-   ";
  }

  out << std::endl;

  for (int i = 0; i < graph.adjMatrix_.size(); ++i) {
    out << graph.header_[i] << " | ";

    for (int j = 0; j < graph.adjMatrix_[i].size(); ++j) {
      if (i == j)
        std::cout << "X   ";
      else if (graph.adjMatrix_[i][j] == -1)
        std::cout << "*   ";
      else
        std::cout << graph.adjMatrix_[i][j] << "   ";
    }

    out << std::endl;
  }

  return out;
}

bool Graph::readFile(const std::string &filePath) {
  std::ifstream graph_file(filePath);
  if (!graph_file.is_open()) {
    std::cerr << "Failed to open " << filePath << std::endl;
    return false;
  }
  int edges = 0;
  int weight = 0;
  std::string from_vertex;
  std::string to_vertex;
  graph_file >> edges;
  for (int i = 0; i < edges; ++i) {
    graph_file >> from_vertex >> to_vertex >> weight;
    connect(from_vertex, to_vertex, weight);
  }
  graph_file.close();
  return true;
}

bool Graph::connect(const std::string &startVertex,
                    const std::string &endVertex, int weight) {

  if (startVertex == endVertex)
    return false;

  int start_vertex_index = -1;
  int end_vertex_index = -1;

  for (int i = 0; i < header_.size(); ++i) {
    if (header_[i] == startVertex)
      start_vertex_index = i;

    if (header_[i] == endVertex)
      end_vertex_index = i;
  }

  if (start_vertex_index == -1) {
    header_.push_back(startVertex);

    for (std::vector<int> &row : adjMatrix_) {
      row.push_back(-1);
    }

    std::vector<int> new_vector;
    for (std::string vertex : header_) {
      new_vector.push_back(-1);
    }

    adjMatrix_.push_back(new_vector);

    start_vertex_index = header_.size() - 1;
  }

  if (end_vertex_index == -1) {
    header_.push_back(endVertex);

    for (std::vector<int> &row : adjMatrix_) {
      row.push_back(-1);
    }

    std::vector<int> new_vector;
    for (std::string vertex : header_) {
      new_vector.push_back(-1);
    }

    adjMatrix_.push_back(new_vector);

    end_vertex_index = header_.size() - 1;
  }

  adjMatrix_[start_vertex_index][end_vertex_index] = weight;

  return true;
}

int Graph::verticesSize() const { return header_.size(); }

int Graph::edgesSize() const {
  int count = 0;

  for (const std::vector<int> &row : adjMatrix_) {
    for (int weight : row) {
      if (weight != -1)
        count++;
    }
  }

  return count;
}

int Graph::vertexDegree(const std::string &label) const {
  int vertex_index = -1;

  for (int i = 0; i < header_.size(); ++i) {
    if (label == header_[i])
      vertex_index = i;
  }

  if (vertex_index == -1)
    return -1;

  int count = 0;

  for (int weight : adjMatrix_[vertex_index]) {
    if (weight != -1)
      count++;
  }

  return count;
}

std::string Graph::getEdgesAsString(const std::string &label) const {
  int vertex_index = -1;

  for (int i = 0; i < header_.size(); ++i) {
    if (label == header_[i])
      vertex_index = i;
  }

  if (vertex_index == -1)
    return "";

  std::string output;

  for (int i = 0; i < adjMatrix_[vertex_index].size(); ++i) {
    if (adjMatrix_[vertex_index][i] != -1)
      output += header_[i] + "(" + std::to_string(adjMatrix_[vertex_index][i]) +
                "), ";
  }

  return output;
}

std::vector<std::string> Graph::getEdgesAsList(const std::string &label) const {
  int vertex_index = -1;

  for (int i = 0; i < header_.size(); ++i) {
    if (label == header_[i])
      vertex_index = i;
  }

  std::vector<std::string> output;

  if (vertex_index == -1)
    return output;

  for (int i = 0; i < adjMatrix_[vertex_index].size(); ++i) {
    if (adjMatrix_[vertex_index][i] != -1)
      output.push_back(header_[i]);
  }

  return output;
}

std::map<std::string, int>
Graph::getEdgesAsMap(const std::string &label) const {
  int vertex_index = -1;

  for (int i = 0; i < header_.size(); ++i) {
    if (label == header_[i])
      vertex_index = i;
  }

  std::map<std::string, int> output;

  if (vertex_index == -1)
    return output;

  for (int i = 0; i < adjMatrix_[vertex_index].size(); ++i) {
    if (adjMatrix_[vertex_index][i] != -1)
      output.insert(
          std::pair<std::string, int>(header_[i], adjMatrix_[vertex_index][i]));
  }

  return output;
}

void Graph::dfs(const std::string &startLabel,
                void (*visit)(const std::string &)) {
  std::vector<std::string> visited;
  dfsHelper(startLabel, visit, visited);
}

void Graph::dfsHelper(const std::string &startLabel,
                      void (*visit)(const std::string &),
                      std::vector<std::string> &visited) {
  visit(startLabel);

  visited.push_back(startLabel);

  std::vector<std::string> adjacent_vertices = getEdgesAsList(startLabel);

  for (const std::string &vertex_label : adjacent_vertices) {
    bool vertex_visited = false;

    for (const std::string &visited_vertex : visited) {
      if (vertex_label == visited_vertex)
        vertex_visited = true;
    }

    if (!vertex_visited)
      dfsHelper(vertex_label, visit, visited);
  }
}

void Graph::bfs(const std::string &startLabel,
                void (*visit)(const std::string &)) const {
  std::vector<std::string> visited;
  std::queue<std::string> q;

  q.push(startLabel);

  visited.push_back(startLabel);

  while (!q.empty()) {
    visit(q.front());

    std::vector<std::string> adjacent_vertices = getEdgesAsList(q.front());

    q.pop();

    for (const std::string &vertex_label : adjacent_vertices) {
      bool vertex_visited = false;

      for (const std::string &visited_vertex : visited) {
        if (vertex_label == visited_vertex)
          vertex_visited = true;
      }

      if (!vertex_visited) {
        q.push(vertex_label);
        visited.push_back(vertex_label);
      }
    }
  }
}

bool Graph::contains(const std::string &label) const {
  return std::find(header_.begin(), header_.end(), label) != header_.end();
}

bool Graph::add(const std::string &label) {
  if (contains(label))
    return false;

  header_.push_back(label);

  for (std::vector<int> &row : adjMatrix_) {
    row.push_back(-1);
  }

  std::vector<int> new_vector;
  for (std::string vertex : header_) {
    new_vector.push_back(-1);
  }

  adjMatrix_.push_back(new_vector);

  return true;
}

bool Graph::disconnect(const std::string &from, const std::string &to) {
  if (from == to)
    return false;

  int from_index = -1;
  int to_index = -1;

  for (int i = 0; i < header_.size(); ++i) {
    if (header_[i] == from)
      from_index = i;
    if (header_[i] == to)
      to_index = i;
  }

  if (from_index == -1 || to_index == -1)
    return false;

  adjMatrix_[from_index][to_index] = -1;

  return true;
}