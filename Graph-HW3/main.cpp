#include "graph.h"

#include <iostream>

void printVertex(const std::string &label) { std::cout << label << ", "; }

void testGraph0() {
  Graph graph0;

  if (!graph0.readFile("./graph0.txt")) {
    return;
  }

  std::cout << "Original Graph:" << std::endl << graph0 << std::endl;

  std::cout << "Amount Of Edges: " << graph0.edgesSize() << std::endl;
  std::cout << "Amount Of Vertices: " << graph0.verticesSize() << std::endl
            << std::endl;
  std::cout << "Degrees Of Vertex A: " << graph0.vertexDegree("A") << std::endl
            << std::endl;

  graph0.add("D");
  std::cout << "Adding Vertex D:" << std::endl << graph0 << std::endl;

  graph0.connect("D", "A", 3);
  std::cout << "Connecting D to A With a Weight of 3:" << std::endl
            << graph0 << std::endl;

  graph0.connect("D", "E", 7);
  std::cout << "Connecting D to E With a Weight of 7:" << std::endl
            << graph0 << std::endl;

  graph0.disconnect("A", "B");
  std::cout << "Disconnecting A and B:" << std::endl << graph0 << std::endl;

  std::cout << "Contains C: " << std::boolalpha << graph0.contains("C")
            << std::endl
            << std::endl;

  std::cout << "Edges Of A (As String): " << graph0.getEdgesAsString("A")
            << std::endl;

  std::vector<std::string> edge_list = graph0.getEdgesAsList("D");
  std::cout << "Edges Of D (As List): "
            << "[ ";
  for (const std::string &edge : edge_list)
    std::cout << edge << ", ";
  std::cout << "]" << std::endl;

  std::map<std::string, int> edge_map = graph0.getEdgesAsMap("D");
  std::cout << "Edges Of D (As Map): " << std::endl << "[ " << std::endl;
  for (std::pair<std::string, int> edge : edge_map)
    std::cout << "\t<Vertex: " << edge.first << ", Weight: " << edge.second
              << ">," << std::endl;
  std::cout << "]" << std::endl << std::endl;

  std::cout << "BFS Traversal From B: ";
  graph0.bfs("B", printVertex);
  std::cout << std::endl;

  std::cout << "DFS Traversal From A: ";
  graph0.dfs("A", printVertex);
  std::cout << std::endl << std::endl;
}

void testGraph1() {
  Graph graph1;

  if (!graph1.readFile("./graph1.txt")) {
    return;
  }

  std::cout << "Original Graph:" << std::endl << graph1 << std::endl;

  std::cout << "Amount Of Edges: " << graph1.edgesSize() << std::endl;
  std::cout << "Amount Of Vertices: " << graph1.verticesSize() << std::endl
            << std::endl;
  std::cout << "Degrees Of Vertex A: " << graph1.vertexDegree("A") << std::endl
            << std::endl;

  graph1.add("K");
  std::cout << "Adding Vertex K:" << std::endl << graph1 << std::endl;

  graph1.connect("A", "K", 3);
  std::cout << "Connecting A to K With a Weight of 3:" << std::endl
            << graph1 << std::endl;

  graph1.disconnect("C", "D");
  std::cout << "Disconnecting C and D:" << std::endl << graph1 << std::endl;

  std::cout << "Contains C: " << std::boolalpha << graph1.contains("C")
            << std::endl
            << std::endl;

  std::cout << "Edges Of A (As String): " << graph1.getEdgesAsString("A")
            << std::endl;

  std::vector<std::string> edge_list = graph1.getEdgesAsList("D");
  std::cout << "Edges Of D (As List): "
            << "[ ";
  for (const std::string &edge : edge_list)
    std::cout << edge << ", ";
  std::cout << "]" << std::endl;

  std::map<std::string, int> edge_map = graph1.getEdgesAsMap("D");
  std::cout << "Edges Of D (As Map): " << std::endl << "[ " << std::endl;
  for (std::pair<std::string, int> edge : edge_map)
    std::cout << "\t<Vertex: " << edge.first << ", Weight: " << edge.second
              << ">," << std::endl;
  std::cout << "]" << std::endl << std::endl;

  std::cout << "BFS Traversal From B: ";
  graph1.bfs("B", printVertex);
  std::cout << std::endl;

  std::cout << "DFS Traversal From A: ";
  graph1.dfs("A", printVertex);
  std::cout << std::endl << std::endl;
}

void testGraph2() {
  Graph graph2;

  if (!graph2.readFile("./graph2.txt")) {
    return;
  }

  std::cout << "Original Graph:" << std::endl << graph2 << std::endl;

  std::cout << "Amount Of Edges: " << graph2.edgesSize() << std::endl;
  std::cout << "Amount Of Vertices: " << graph2.verticesSize() << std::endl
            << std::endl;
  std::cout << "Degrees Of Vertex A: " << graph2.vertexDegree("A") << std::endl
            << std::endl;

  graph2.add("V");
  std::cout << "Adding Vertex V:" << std::endl << graph2 << std::endl;

  graph2.connect("A", "V", 3);
  std::cout << "Connecting A to V With a Weight of 3:" << std::endl
            << graph2 << std::endl;

  graph2.disconnect("C", "D");
  std::cout << "Disconnecting C and D:" << std::endl << graph2 << std::endl;

  std::cout << "Contains C: " << std::boolalpha << graph2.contains("C")
            << std::endl
            << std::endl;

  std::cout << "Edges Of A (As String): " << graph2.getEdgesAsString("A")
            << std::endl;

  std::vector<std::string> edge_list = graph2.getEdgesAsList("D");
  std::cout << "Edges Of D (As List): "
            << "[ ";
  for (const std::string &edge : edge_list)
    std::cout << edge << ", ";
  std::cout << "]" << std::endl;

  std::map<std::string, int> edge_map = graph2.getEdgesAsMap("D");
  std::cout << "Edges Of D (As Map): " << std::endl << "[ " << std::endl;
  for (std::pair<std::string, int> edge : edge_map)
    std::cout << "\t<Vertex: " << edge.first << ", Weight: " << edge.second
              << ">," << std::endl;
  std::cout << "]" << std::endl << std::endl;

  std::cout << "BFS Traversal From B: ";
  graph2.bfs("B", printVertex);
  std::cout << std::endl;

  std::cout << "DFS Traversal From A: ";
  graph2.dfs("A", printVertex);
  std::cout << std::endl << std::endl;
}

void testGraph3() {
  Graph graph3;

  if (!graph3.readFile("./graph3.txt")) {
    return;
  }

  std::cout << "Original Graph:" << std::endl << graph3 << std::endl;

  std::cout << "Amount Of Edges: " << graph3.edgesSize() << std::endl;
  std::cout << "Amount Of Vertices: " << graph3.verticesSize() << std::endl
            << std::endl;
  std::cout << "Degrees Of Vertex A: " << graph3.vertexDegree("A") << std::endl
            << std::endl;

  graph3.add("V");
  std::cout << "Adding Vertex V:" << std::endl << graph3 << std::endl;

  graph3.connect("A", "V", 3);
  std::cout << "Connecting A to V With a Weight of 3:" << std::endl
            << graph3 << std::endl;

  graph3.disconnect("C", "D");
  std::cout << "Disconnecting C and D:" << std::endl << graph3 << std::endl;

  std::cout << "Contains C: " << std::boolalpha << graph3.contains("C")
            << std::endl
            << std::endl;

  std::cout << "Edges Of A (As String): " << graph3.getEdgesAsString("A")
            << std::endl;

  std::vector<std::string> edge_list = graph3.getEdgesAsList("D");
  std::cout << "Edges Of D (As List): "
            << "[ ";
  for (const std::string &edge : edge_list)
    std::cout << edge << ", ";
  std::cout << "]" << std::endl;

  std::map<std::string, int> edge_map = graph3.getEdgesAsMap("D");
  std::cout << "Edges Of D (As Map): " << std::endl << "[ " << std::endl;
  for (std::pair<std::string, int> edge : edge_map)
    std::cout << "\t<Vertex: " << edge.first << ", Weight: " << edge.second
              << ">," << std::endl;
  std::cout << "]" << std::endl << std::endl;

  std::cout << "BFS Traversal From B: ";
  graph3.bfs("B", printVertex);
  std::cout << std::endl;

  std::cout << "DFS Traversal From A: ";
  graph3.dfs("A", printVertex);
  std::cout << std::endl << std::endl;
}

void testGraph4() {
  Graph graph4;

  if (!graph4.readFile("./graph4.txt")) {
    return;
  }

  std::cout << "Original Graph:" << std::endl << graph4 << std::endl;

  std::cout << "Amount Of Edges: " << graph4.edgesSize() << std::endl;
  std::cout << "Amount Of Vertices: " << graph4.verticesSize() << std::endl
            << std::endl;
  std::cout << "Degrees Of Vertex A: " << graph4.vertexDegree("A") << std::endl
            << std::endl;

  graph4.add("V");
  std::cout << "Adding Vertex V:" << std::endl << graph4 << std::endl;

  graph4.connect("A", "V", 3);
  std::cout << "Connecting A to V With a Weight of 3:" << std::endl
            << graph4 << std::endl;

  graph4.disconnect("C", "D");
  std::cout << "Disconnecting C and D:" << std::endl << graph4 << std::endl;

  std::cout << "Contains C: " << std::boolalpha << graph4.contains("C")
            << std::endl
            << std::endl;

  std::cout << "Edges Of A (As String): " << graph4.getEdgesAsString("A")
            << std::endl;

  std::vector<std::string> edge_list = graph4.getEdgesAsList("D");
  std::cout << "Edges Of D (As List): "
            << "[ ";
  for (const std::string &edge : edge_list)
    std::cout << edge << ", ";
  std::cout << "]" << std::endl;

  std::map<std::string, int> edge_map = graph4.getEdgesAsMap("D");
  std::cout << "Edges Of D (As Map): " << std::endl << "[ " << std::endl;
  for (std::pair<std::string, int> edge : edge_map)
    std::cout << "\t<Vertex: " << edge.first << ", Weight: " << edge.second
              << ">," << std::endl;
  std::cout << "]" << std::endl << std::endl;

  std::cout << "BFS Traversal From B: ";
  graph4.bfs("B", printVertex);
  std::cout << std::endl;

  std::cout << "DFS Traversal From A: ";
  graph4.dfs("A", printVertex);
  std::cout << std::endl << std::endl;
}

void additionalTests() {
  Graph graph;

  if (!graph.readFile("./graph0.txt")) {
    return;
  }

  std::cout << "Connecting A to A: " << std::boolalpha
            << graph.connect("A", "A", 9) << std::endl;
  std::cout << "Disconnecting A and A: " << std::boolalpha
            << graph.disconnect("A", "A") << std::endl;
  std::cout << "Disconnecting F and G: " << std::boolalpha
            << graph.disconnect("F", "G") << std::endl;
  std::cout << "Contains L: " << std::boolalpha << graph.contains("L")
            << std::endl;
  graph.dfs("L", printVertex);
  graph.bfs("L", printVertex);
  graph.vertexDegree("L");
  std::cout << "Adding Vertex A: " << std::boolalpha << graph.add("A")
            << std::endl;

  if (!graph.readFile("./nonExistentFile.txt")) {
    return;
  }
}

int main() {
  testGraph0();
  testGraph1();
  testGraph2();
  testGraph3();
  testGraph4();
  additionalTests();
  return 0;
}
