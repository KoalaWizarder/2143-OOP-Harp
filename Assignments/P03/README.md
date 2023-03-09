## P03 - Graphiz Class
### Mervyn Harp
### Description:
Program creates graphs with nodes and edges that can then be used by the Graphiz program 

### Needed Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [source.cpp](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P03/source.cpp)  | Main driver of project that contains all program functionality |
|   2   | [test.out](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P03/test.out)    | Output file where results are stored |


### Instructions
For the user, only a few commands are needed to actually create a graph class (must be used in main)
(Wherever `datatype` is used inline, it will dictate the type of data stored within the graph)
- `graph<datatype> foo` - Creates graph. Can use input parameters (detailed in [source.cpp](https://github.com/KoalaWizarder/2143-OOP-Harp/blob/main/Assignments/P03/source.cpp)) to assign various graph attributes.
- `updateNode(int &nodeID,datatype)` - Updates attributes within selected node
- `updateEdge(int &fromNodeID, int &toNodeID, datatype)` - Updates attributes within selected edge
- `addNode(datatype)` - Adds node containing data to graph
- `addEdge(int fromNodeId, int toNodeId)` - Adds edge between two nodes 
- `printGraph()` - Outputs entire graph to terminal AND output file ('test.out')
