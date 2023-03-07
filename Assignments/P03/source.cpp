#include <iostream>
#include <map> 
#include <vector>
#include <string>

using namespace std;

struct edge{
    string node1, node2;
    string ending;
    map<string, string> att;

    edge(int n1, int n2, string color, string shape){
        node1 = 'N' + to_string(n1);
        node2 = 'N' + to_string(n2);
        att["color"] = color;
        att["arrowType"] = shape;
    }
    edge(int n1, string _ending, string color, string shape){
        node1 = 'N' + to_string(n1);
        ending = _ending;
        att["color"] = color;
        att["arrowType"] = shape;
    }
};

template <typename T> struct node{
    int id;
    T data;
    map<string, string> att;

    node(int _id, const T &d, string color, string shape){
        id = _id;
        data = d;
        att["color"] = color;
        att["shape"] = shape;
    }
};

template <typename T> class graph {
private:
    vector<node<T>> nodes;
    vector<edge> edges;
    bool directed;

public:
    graph(bool _directed = false){
        directed=_directed;
    }

    bool nodeCheck(int nodeIndex){
        if(nodes.size() > 0 && nodeIndex >= 0 && nodeIndex <= nodes.size()-1)
            return true;
        else;
            return false;
    }


    void addNode(const T &data, string color = "black", string shape = "box") {
        nodes.push_back(node<T>(nodes.size(),data,color,shape));
    }

    void addEdge(int fromNodeID, int toNodeID, string color = "black", string arrowhead = "normal"){
        if(nodeCheck(fromNodeID) && nodeCheck(toNodeID))
            edges.push_back(edge(fromNodeID,toNodeID,color,arrowhead));
        else
            cout << "ERROR! Target node not found!\n";

    }
    void addEndEdge(int fromNodeID, string end = "NULL", string color = "black", string arrowhead = "normal"){
        if(nodeCheck(fromNodeID)){
            edges.push_back(edge(fromNodeID, end, color, arrowhead));
        }

    }

    void editNodeData(const node<T> &n){

    }

    void printGraph(){
        string tab = "    ";
        cout << ((directed) ? "graph " : "digraph ") << "{\n";
        for(auto i : nodes) {
            cout << tab << 'N' << i.id 
                 << " [label= \"" << i.data << "\","
                 << "color= \"" << i.att["color"] << "\","
                 << "shape= \"" << i.att["shape"] << "\"];\n";
        }
        for(auto i : edges) {
            cout << tab << i.node1 
                 << ((directed) ? " -- " : " -> ") 
                 << ((i.ending.empty()) ? i.node2 : i.ending) << '\n';
        }
        cout << '}';
    }
};

int main(){
    graph<int> temp1;

    for(int i = 1; i <= 5; i++){
        temp1.addNode(i);
    }

    temp1.addNode(1,"Red");
    temp1.addNode(3,"Orange","Record");
    temp1.addEdge(1,6);
    temp1.addEdge(3,10);
    temp1.addEdge(4,5);
    temp1.addEndEdge(6);
    temp1.addEdge(0,1);
    temp1.addEdge(5,4);

    temp1.printGraph();


}