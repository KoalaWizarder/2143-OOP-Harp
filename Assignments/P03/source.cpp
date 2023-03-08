#include <iostream>
#include <map> 
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string tolower(string &input){
    string temp;
    for(auto i = input.begin(); i != input.end(); i++)
        if(*i == ':')
            temp += ':';
        else
            temp += tolower(*i);

    return temp;
}

vector<string> colors(){
    return vector<string>{"black", "aqua", "aquamarine", "azure", "beige", "bisque", "blue", 
        "blueviolet", "brown", "cadetblue", "chartreuse", "chocolate", "coral", "cornflowerblue", 
        "cornsilk", "crimson", "cyan", "darkblue", "darkcyan", "darkgoldenrod", "darkgray", "darkgreen", 
        "darkgrey", "darkkhaki", "darkmagenta", "darkolivegreen", "darkorange", "darkorchid", "darkred", 
        "darksalmon", "darkseagreen", "darkslateblue", "darkslategray", "darkslategrey", "darkturquoise", 
        "darkviolet", "deeppink", "deepskyblue", "dimgray", "dimgrey", "dodgerblue", "firebrick", 
        "floralwhite", "forestgreen", "fuchsia", "gainsboro", "ghostwhite", "gold", "goldenrod", "gray", 
        "honeydew", "hotpink", "indianred", "indigo", "invis", "ivory", "khaki", "lavender", "lavenderblush", 
        "lawngreen", "lemonchiffon", "lightblue", "lightcoral", "lightcyan", "lightgoldenrod", 
        "lightgoldenrodyellow", "lightgray", "lightgreen", "lightgrey", "lightpink", "lightsalmon", 
        "lightseagreen", "lightskyblue", "lightslateblue", "lightslategray", "lightslategrey", "lightsteelblue", 
        "lightyellow", "lime", "limegreen", "linen", "magenta", "maroon", "mediumaquamarine", "mediumblue", 
        "mediumorchid", "mediumpurple", "mediumseagreen", "mediumslateblue", "mediumspringgreen", 
        "mediumturquoise", "mediumvioletred", "midnightblue", "mintcream", "mistyrose", "moccasin", 
        "navajowhite", "navy", "navyblue", "none", "oldlace", "olive", "olivedrab", "orange", "orangered", 
        "orchid", "palegoldenrod", "palegreen", "paleturquoise", "palevioletred", "papayawhip", "peachpuff", 
        "peru", "pink", "plum", "powderblue", "purple", "rebeccapurple", "red", "rosybrown", "royalblue", 
        "saddlebrown", "salmon", "sandybrown", "seagreen", "seashell", "sienna", "silver", "skyblue", 
        "slateblue", "slategray", "slategrey", "snow", "springgreen", "steelblue", "tan", "teal", "thistle", 
        "tomato", "transparent", "turquoise", "violet", "violetred", "webgray", "webgreen", "webgrey", 
        "webmaroon", "webpurple", "wheat", "white", "whitesmoke", "x11gray", "x11green", "x11grey", 
        "x11maroon", "x11purple"};
}

vector<string> nodeShapes(){
    return vector<string>{"box", "polygon","ellipse","oval","circle","point","plaintext","plain","diamond",
        "pentagon","hexagon","record", "rect","rectangle","square","star","none","underline","box3d"};
}

string dataValidation(string data, const vector<string> &repo){
    vector<string> temp;
    string final;
    data += ":";
    bool flag = false;
    size_t pos = 0;
    //->Separates string into single words (deliminator is':') that are then 
    //      checked against the approved words for its category. 
    //->If word is NOT found in list, set to default value of the list
    while((pos = data.find(':')) != string::npos){
        temp.push_back(data.substr(0,pos));
        data.erase(0, pos + 1);
    }
    for(vector<string>::iterator i = temp.begin(); i != temp.end(); i++){
        for(auto j : repo){
            if (*i == j){
                final += *i += ((i == --(temp.end())) ? "" : ":");
                flag = true;
                break;
            }
        }
        if(!flag){
            final += repo[0];
            final += ((i == --(temp.end())) ? "" : ":");
        }
    }
    return final;
}

struct edge{
    string node1, node2;
    string ending;
    map<string, string> att;

    edge(int n1, int n2, string color, string shape){
        node1 = 'N' + to_string(n1);
        node2 = 'N' + to_string(n2);
        att["color"] = dataValidation(tolower(color), colors());
        att["arrowType"] = shape;
    }
    edge(int n1, string _ending, string color, string shape){
        node1 = 'N' + to_string(n1);
        ending = _ending;
        att["color"] = dataValidation(tolower(color), colors());
        att["arrowType"] = shape;
    }
};

template <typename T> struct node{
    int id;
    T data;
    map<string, string> att;

    node(int _id, const T &d, string color, string shape, string gradAngle){
        id = _id;
        data = d;
        if(color.find(':') != string::npos){
            att["fillcolor"] = dataValidation(tolower(color), colors());
            att["gradientangle"] = gradAngle;
        }
        else{
            att["color"] = dataValidation(tolower(color), colors());
        }
        att["shape"] = dataValidation(tolower(shape), nodeShapes());
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


    void addNode(const T &data, string color = "black", string shape = "box", string gradAngle = "0") {
        nodes.push_back(node<T>(nodes.size(),data,color,shape, gradAngle));
    }

    void addEdge(int fromNodeID, int toNodeID, string color = "black", string arrowhead = "normal"){
        if(nodeCheck(fromNodeID) && nodeCheck(toNodeID))
            edges.push_back(edge(fromNodeID,toNodeID,color,arrowhead));
        else
            cout << "ERROR! Target node not found!\n";

    }
    void addEdge(int fromNodeID, string end = "NULL", string color = "black", string arrowhead = "normal"){
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
            cout << tab << 'N' << i.id;
            cout << " [label=" << '\"' << i.data << "\", ";
            if(i.att.count("gradientangle")){
                cout << "style=filled, ";
            }
            for(map<string,string>::iterator j = i.att.begin(); j != (i.att.end()); j++ ){
                cout << j->first << "=\"" << j->second << "\""
                     << ((j == --(i.att.end())) ? "];\n" : ", ");
            }
        }
        for(auto i : edges) {
            cout << tab << i.node1 
                 << ((directed) ? " -- " : " -> ") 
                 << ((i.ending.empty()) ? i.node2 : i.ending) << '\n';
        }
        cout << "}\n";
    }
};

int main(){
    graph<int> temp1;

    for(int i = 1; i <= 5; i++){
        temp1.addNode(i);
    }

    temp1.addNode(1,"Red:black","star","45");

    temp1.addNode(3,"orange","gooply-gook");
    temp1.addEdge(1,6);
    temp1.addEdge(3,10);
    temp1.addEdge(4,5);
    temp1.addEdge(6);
    temp1.addEdge(0,1);
    temp1.addEdge(5,4);
    temp1.addNode(100,"pissyellow:orange");

    temp1.printGraph();

    // cout << dataValidation <string, vector<string>> ("red", nodeColor());


}