/******************************************************************************        
*  Author:           Mervyn Harp
*  Email:            mtharp0818@msutexas.edu
*  Label:            05-P03
*  Title:            Program 3 - Graphiz Class
*  Course:           CMPS 2143
*  Semester:         SPRING 2023
* 
*  Description:
*     []Program builds the base code that will be used by Graphiz libary (DOT- 
            syntax) in order to build a graph
*  Usage:
*     []class graph   ->   Please view the 'Constructors' section within the 
*                               class definitions to see each way a Vector can 
*                               be created
*  Files:            
*     [] test.out   :   Output file where results are printed
******************************************************************************/

#include <iostream>
#include <map> 
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <algorithm>

using namespace std;

/******************************************************************************        
* tolower(string &input):  
*
* Description: 
*       [] Accepts input string, then returns a copy of that string with all 
*           of its characters as lowercase.
*       [*] Will replace any '-' character with ' '
* Parameters:  
*       [] string &input    :   [] String to be copied               
* Returns:
*       [] string temp      :   [] Altered string                            */
string tolower(string &input){
    string temp;
    for(auto i = input.begin(); i != input.end(); i++)
        temp += ((*i=='-') ? ' ' : tolower(*i));
    return temp;
}
/******************************************************************************        
* tolower(string &input):  
*
* Description: 
*       [] Accepts input string, then returns a copy of that string with all 
*           of its characters as uppercase.
*       [*] Will replace any '-' character with ' '
* Parameters:  
*       [] string &input    :   [] String to be copied               
* Returns:
*       [] string temp      :   [] Altered string                            */
string toupper(string &input){
    string temp;
    for(auto i = input.begin(); i != input.end(); i++)
        temp += ((*i=='-') ? ' ' : toupper(*i));
    return temp;
}
/******************************************************************************        
* removeSpaces(string iinput):  
*
* Description: 
*       [] Accepts input string, then returns that string with all of its 
*           empty characters (ie ' ') removed.
* Parameters:  
*       [] string input    :   [] String to be altered               
* Returns:
*       [] string input    :   [] Altered string                            */
string removeSpaces(string input){
    remove(input.begin(), input.end(), ' ');
    input.pop_back();
    return input;
}
/******************************************************************************
* count(string input, string key):
*
* Description:
*       [] Accepts input string and checks to see if it contains the same value
*           as key. If so, return true. Otherwise return false
* Parameters:
*       [] string input     :   [] String to be checked
*       [] string key       :   [] String to be searched for within 'input'
* Returns:
*       [] bool             : True if 'key' is found with 'input'
*                           : False otherwise                                */
bool count(string input, string key){
    for(auto i : input){
        if (i==*(key.data()))
            return true;
    }
    return false;
}

/******************************************************************************
* ALL of the following Vectors:
*
* Description:
*       [] Each of these serve as a repository of sorts that this program will
*           use within the function, 'dataValidation()' to make sure that each
*           value trying to be used is a valid input.
*       [*] Note: These vectors do NOT contain every color, node shape, 
*           arrowhead, etc. Please check to make sure each value you are trying
*           to use is found within these Vectors
* Parameters:
*       [] N/A
* Returns:
*       [] vector<string>   : Vector containing each valid input string      */
vector<string> colors(){
    return vector<string>{"black", "aqua", "aquamarine", "azure", "beige", 
    "bisque", "blue", "blueviolet", "brown", "cadetblue", "chartreuse", 
    "chocolate", "coral", "cornflowerblue", "cornsilk", "crimson", "cyan", 
    "darkblue", "darkcyan", "darkgoldenrod", "darkgray", "darkgreen", 
    "darkgrey", "darkkhaki", "darkmagenta", "darkolivegreen", "darkorange", 
    "darkorchid", "darkred", "darksalmon", "darkseagreen", "darkslateblue", 
        "darkslategray", "darkslategrey", "darkturquoise", "darkviolet", 
        "deeppink", "deepskyblue", "dimgray", "dimgrey", "dodgerblue", 
        "firebrick", "floralwhite", "forestgreen", "fuchsia", "gainsboro", 
        "ghostwhite", "gold", "goldenrod", "gray", "honeydew", "hotpink", 
        "indianred", "indigo", "invis", "ivory", "khaki", "lavender", 
        "lavenderblush", "lawngreen", "lemonchiffon", "lightblue", 
        "lightcoral", "lightcyan", "lightgoldenrod", "lightgoldenrodyellow", 
        "lightgray", "lightgreen", "lightgrey", "lightpink", "lightsalmon", 
        "lightseagreen", "lightskyblue", "lightslateblue", "lightslategray", 
        "lightslategrey", "lightsteelblue", "lightyellow", "lime", "limegreen", 
        "linen", "magenta", "maroon", "mediumaquamarine", "mediumblue", 
        "mediumorchid", "mediumpurple", "mediumseagreen", "mediumslateblue", 
        "mediumspringgreen", "mediumturquoise", "mediumvioletred", 
        "midnightblue", "mintcream", "mistyrose", "moccasin", "navajowhite", 
        "navy", "navyblue", "none", "oldlace", "olive", "olivedrab", "orange", 
        "orangered", "orchid", "palegoldenrod", "palegreen", "paleturquoise", 
        "palevioletred", "papayawhip", "peachpuff", "peru", "pink", "plum", 
        "powderblue", "purple", "rebeccapurple", "red", "rosybrown",
        "royalblue", "saddlebrown", "salmon", "sandybrown", "seagreen", 
        "seashell", "sienna", "silver", "skyblue", "slateblue", "slategray", 
        "slategrey", "snow", "springgreen", "steelblue", "tan", "teal", 
        "thistle", "tomato", "transparent", "turquoise", "violet", "violetred",
        "webgray", "webgreen", "webgrey", "webmaroon", "webpurple", "wheat",
        "white", "whitesmoke", "x11gray", "x11green", "x11grey", "x11maroon", 
        "x11purple"};
}
vector<string> nodeShapes(){
    return vector<string>{"record", "polygon","ellipse","oval","circle",
    "point", "plaintext","plain","diamond", "pentagon","hexagon","box", "rect",
    "rectangle","square","star","none","underline","box3d"};
}
vector<string> arrowheads(){
    return vector<string>{"normal", "inv", "dot", "invdot", "odot", "invodot", 
    "none", "tee", "empty", "invempty", "diamond", "odiamond", "ediamond", 
    "crow", "box", "obox", "open", "halfopen", "vee"};
}
vector<string> edgeDirs(){
    return vector<string>{"forward", "back", "both", "none"};
}
vector<string> graphTypes(){
    return vector<string>{"standard", "binary tree", "binarytree", 
    "linked list", "linkedlist", "doubly linked list", "doublylinkedlist"};
}
vector<string> validNodeAtt(){
    return vector<string>{"", "fillcolor","gradientangle","color","shape"};
}
vector<string> validEdgeAtt(){
    return vector<string>{"", "color","arrowhead","dir"};
}
vector<string> rankDirs(){
    return vector<string>{"LR","TB","BT","RL"};
}

/******************************************************************************
* string dataValidation(string data, const vector<string> &repo):
*
* Description:
*       [] Accepts input data and a corresponding Vector repository to check
*           data is within that particular repo. 
*       [] If data is not found, data is changed to the default value of each
*           Vector, which is whatever the first value is inside each Vector
* Parameters:
*       [] string data                  :   String to be checked
*       [] const vector<string> &repo   :   Vector to be searched through to 
*                                             find 'data'
* Returns:
*       [] string final     :   Returns 'data' if data was found within Repo
*                           :   ROtherwise, returns default of repo          */
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

/******************************************************************************
* struct edge:
*
* Description:
*       [] Creates and holds data for each edge used within graph class
* Usage(NEEDED PARAMETERS):
*   []  edge(int n1, int n2, string color, string arrowhead, string dir, 
*         float arrowSize)              :   ONLY constructor for edge struct
*   []  printEdge(const string &line)   :   Returns string with all of the 
*                                             info needed from edge          */
struct edge{
    string node1, node2;
    string ending;
    map<string, string> att;

    edge(int n1, int n2, string color, string arrowhead, string dir, 
            float arrowSize){
        node1 = 'N' + to_string(n1);
        node2 = ((n2==-1) ? "NULL" : 'N' + to_string(n2));
        float arrowsize = arrowSize;
        att["color"] = dataValidation(tolower(color), colors());
        att["arrowhead"] = dataValidation(tolower(arrowhead), arrowheads());
        att["dir"] = dataValidation(tolower(dir), edgeDirs());
    }
    
    string printEdge(const string &line, string node1Ref = "",
            string node1Loc = "", string node2Ref = "", string node2Loc = "") {
        string temp = "";
        temp += ("    " + node1 + ((node1Ref=="") ? "" : ":" + node1Ref + ":" 
                + node1Loc) + line);
        temp += (node2 + ((node2Ref=="") ? "" : ":" + node2Ref + ":" 
                + node2Loc));
        
        if(node2=="NULL"){
            temp += " [dir=\"forward\"]";
        }
        else{
            temp += " [";
            for(map<string,string>::iterator i = att.begin(); 
                    i!=(att.end());i++) {
                temp += (i->first + "=\"" + i->second + '\"');
                temp += ((i==--(att.end())) ? ']' : ',');
            }
        }
        temp += "\n";
        return temp;
    }
};

/******************************************************************************
* <typename T> struct node:
*
* Description:
*       [] Creates and holds data for each node used within graph class
*       [*] Typeneame 'T' determines the data type held within each node
* Usage:
*       [] node(int _id, const T &d, string color, string shape, 
*           string gradAngle)   :   ONLY Constructor for node struct         */
template <typename T> struct node{
    int id;
    T data;
    map<string, string> att;

    node(int _id, const T &d, string color, string shape, string gradAngle){
        id = _id;
        data = d;
        if(color.find(':') != string::npos){
            att["style"] = "filled";
            att["fillcolor"] = dataValidation(tolower(color), colors());
            att["gradientangle"] = gradAngle;
        }
        else{
            att["color"] = dataValidation(tolower(color), colors());
        }
        att["shape"] = dataValidation(tolower(shape), nodeShapes());
    }

    void updateAtt(const string &key, string value){
        if(key=="gradientangle")
            att["gradientangle"] = value;
        else{    
            vector<string> temp = ((key=="fillcolor" || key=="color") ? 
                    colors() : nodeShapes() );
            if(key=="fillcolor" && (att.count("color"))) {
                att.erase("color");
                att["gradientangle"] = "0";
                att["style"] = "filled";
            }
            else if(key=="color" && (att.count("fillcolor"))){
                att.erase("fillcolor");
                att.erase("style");
                att.erase("gradientangle");
            }
            att[key] = dataValidation(tolower(value), temp);
        }
    }
    void updateValue(const T &newData){
        data = newData;
    }
};

/******************************************************************************
* <typename T> class graph:
*
* Description:
*       [] Creates and holds data for the graph itself, as well as containing 
*           the Vector of nodes and Vector of edges that make up each graph
*       [*] Typeneame 'T' determines the data type held within the graph
* Usage:
*       [] graph(string _graphType = "standard", string _rankdir = "LR", 
*           bool _directed = false)   :   ONLY Constructor(is considered default) 
*                                           for graph class       

*       [] void updateNode(const int &nodeID, const string &key, 
*           const string &value)      :   Searches node for 'key', then updates
*                                           corresponding value to new 'value' 

*       [] void updateEdge(const int &nodeID, const string &key, 
*           const string &value)      :   Searches edge for 'key', then updates
*                                           corresponding value to new 'value'

*       [] void addNode(const T &data, string color = "black", 
*           string shape = "record", string gradAngle = "0")
*                                     :   Adds node to graph

*       [] void addEdge(void addEdge(int fromNodeID, int toNodeID = -1, 
*           string color = "black", string arrowhead = "normal", 
*           string direction = "forward", float arrowSize = 1)      
                                      : Adds edge to graph

*       [] void printGraph()          : Outputs entire graph to terminal AND 'test.out'*/
template <typename T> class graph {
private:
    vector<node<T>> nodes;
    vector<edge> edges;
    bool directed;
    map<string,string> graphAtt;
    string type;

public:
    graph(string _graphType = "standard", string _rankdir = "LR", 
            bool _directed = false){
        directed=_directed;
        graphAtt["type"] = ((count(graphAtt["type"]," ")) ? 
                removeSpaces(dataValidation(tolower(_graphType), graphTypes())) 
                : dataValidation(tolower(_graphType), graphTypes()));

        string temp = dataValidation(tolower(_rankdir), rankDirs());

        graphAtt["rankdir"] = dataValidation(toupper(temp), rankDirs());

    }

    bool nodeCheck(int nodeIndex){
        if(nodes.size() > 0 && nodeIndex >= 0 && nodeIndex <= nodes.size()-1)
            return true;
        else;
            return false;
    }

    void updateNode(const int &nodeID, const string &key, const string &value){
        nodes[nodeID].updateAtt(dataValidation(key,validNodeAtt()), value);
    }
    void updateEdge(const int &nodeID, const string &key, const string &value){
        nodes[nodeID].updateAtt(dataValidation(key,validNodeAtt()), value);
    }

    void addNode(const T &data, string color = "black", 
            string shape = "record", string gradAngle = "0") {
        if(graphAtt["type"]=="linkedlist"||
                graphAtt["type"]=="doublylinkedlist"){
            shape = "record";
        }
        
        nodes.push_back(node<T>(nodes.size(),data,color,shape, gradAngle));
    }

    void addEdge(int fromNodeID, int toNodeID = -1, string color = "black", 
            string arrowhead = "normal", string direction = "forward",
            float arrowSize = 1){   
        if(nodeCheck(fromNodeID) && ((toNodeID == -1) ? true : 
                nodeCheck(toNodeID)))
            edges.push_back(edge(fromNodeID,toNodeID,color,arrowhead, 
                    direction, arrowSize));
        else 
            cout << "ERROR! SOURCE/TARGET NODE(S) NOT FOUND\n";
    }


    void printGraph(){
        ofstream fout;
        fout.open("test.out");
        
        string line = ((directed) ? " -- " : " -> ");
        string tab = "    ";
        string open = "";
        string close = "";
        if (graphAtt["type"]=="linkedlist"||
                graphAtt["type"]=="doublylinkedlist"){
            open = "{";
            close = "}";
        }
        vector<edge> temp;

        cout << ((directed) ? "graph " : "digraph ") << graphAtt["type"] 
             << " {\n";
        fout << ((directed) ? "graph " : "digraph ") << graphAtt["type"] 
             << " {\n";
        for(auto i : graphAtt) {
            if(i.first!="type"){
                cout << tab << i.first << '=' << i.second << ";\n";
                fout << tab << i.first << '=' << i.second << ";\n";
            }
        }
        for(auto i : nodes) {
            cout << tab << 'N' << i.id;
            fout << tab << 'N' << i.id;
            cout << " [label=\"" << open << ((graphAtt["type"] == "linkedlist")
                 ? "<data>"+to_string(i.data) + " | <next>" : to_string(i.data)) 
                 << close << "\", "; 
            fout << " [label=\"" << open << ((graphAtt["type"] == "linkedlist")
                 ? "<data>"+to_string(i.data) + " | <next>" : to_string(i.data)) 
                 << close << "\", "; 
        
            for(map<string,string>::iterator j = i.att.begin(); 
            j != (i.att.end()); j++ ){
                cout << j->first << "=\"" << j->second << "\""
                     << ((j == --(i.att.end())) ? "];\n" : ", ");
                fout << j->first << "=\"" << j->second << "\""
                     << ((j == --(i.att.end())) ? "];\n" : ", ");
            }
        }


        if(graphAtt["type"] == "binarytree"){
            int count = 1;
            vector<edge> temp;
            for(int i = 0; i < nodes.size()/2; i++){
                for(int j = count;j<count+2;j++){
                    temp.push_back(edge(i,j,"black","normal","forward", 1));
                }
                count+=2;
            }
            for(auto i : temp){
                cout << i.printEdge(line);
                fout << i.printEdge(line);
            }
        }
        else if(graphAtt["type"] == "linkedlist"){
            cout << tab << "NULL [shape=\"plaintext\"]\n\n"
                 << tab << "edge [tailclip=\"false\", arrowtail=dot, dir=both]"
                 << "\n";
            fout << tab << "NULL [shape=\"plaintext\"]\n\n"
                 << tab << "edge [tailclip=\"false\", arrowtail=dot, dir=both]"
                 << "\n";
            vector<edge> temp;

            for(int i = 0; i < nodes.size()-1;i++){
                temp.push_back(edge(i,i+1,"black","normal","forward", 1));
            }
            temp.push_back(edge(nodes.size()-1,-1,"black","normal",
                    "forward", 1));
            for(auto i : temp){
                cout << i.printEdge(line,"next","1");
                fout << i.printEdge(line,"next","1");
            }
        }
        else if(graphAtt["type"] == "doublylinkedlist"){
            cout << tab << "NULL [shape=\"plaintext\"]\n\n";
            fout << tab << "NULL [shape=\"plaintext\"]\n\n";
            cout << tab << "edge [dir=both]\n";
            fout << tab << "edge [dir=both]\n";
            vector<edge> temp;

            for(int i = 0; i < nodes.size()-1;i++){
                temp.push_back(edge(i,i+1,"black","normal","both", 1));
            }
            temp.push_back(edge(nodes.size()-1,-1,"black","normal","both", 1));
            for(auto i : temp){
                i.printEdge(line);
            }
        }
        else {
            for(auto i : edges) {
                cout << tab << i.node1 
                    << line
                    << ((i.ending.empty()) ? i.node2 : i.ending) << '\n';
                fout << tab << i.node1 
                    << line
                    << ((i.ending.empty()) ? i.node2 : i.ending) << '\n';
            }
        }
        cout << "}\n";
        fout << "}\n";
    }
};

int main(){
    graph<int> temp1("standard", "TD");

    for(int i = 1; i <= 10; i++){
        temp1.addNode(i);
    }

    temp1.addEdge(0, 5, "red:yellow");
    temp1.printGraph();
}
