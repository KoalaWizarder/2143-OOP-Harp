/******************************************************************************
*                    
*  Author:           Mervyn Harp
*  Email:            mtharp0818@msutexas.edu
*  Label:            04-P01
*  Title:            Program 1 - Vector Class
*  Course:           CMPS 2143
*  Semester:         SPRING 2023
* 
*  Description:
*     []Program is my own defined Vector class. Implements classic Vector usage
*     []'Vector' allows for dynamic storage of integers that implements various
*           ease-of-use functions
*  Usage:
*     []class Vector   ->   Please view the 'Constructors' section within the 
*                               class definitions to see each way a Vector can 
*                               be created
*  Files:            
*     [] input.dat  :   Series of integers to be used in constructing a Vector
*     [] test.out   :   Output file where results are printed
******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/******************************************************************************
* node
*
*   Description:
*     []This struct is used as a container for data that is then linked 
*           together within the 'Vector' class
*     []Is NOT used anywhere outside of 'Vector'                             */
struct node{
    int data;               //Holds data for node
    node* next;             //Hold pointer to next node for use in Vector class
    node* prev;             //Hold pointer to prev node for use in Vector class

    //Default constructor for node. Allows for easy pass-in of next/prev
    node(int n, node* _next = nullptr, node* _prev = nullptr){
        data = n;
        next = _next;
        prev = _prev;
    }
};

/******************************************************************************
* Vector
* 
*->Description:
*     []This class uses node structs to store a series of integers
*     []Every node is created dynamically and is appended to the corresponding
*           index within the Vector
*->Constructors:
*     []Vector()                        ->  Basic constructor that builds a 
*                                               NULL vector
*     []Vector(int arr[], int _size)    ->  Builds Vector based off array. 
*     []Vector(std::string file)        ->  Builds Vector based on input from 
*                                               file
*     []Vector(Vector& v2)              ->  Builds Vector by copying another
*->Public Methods
*     ReturnType:   name                ->  Description/Usage
*    --------------------------------------------------------------------------
*     []int     :   getSize()           ->  Returns size of Vector
*     []int     :   peekFront()         ->  Returns data in front of Vector
*     []int     :   peekRear()          ->  Returns data in back of Vector
*     []int     :   peekInd(int n)      ->  Returns data at (n) index
*    --------------------------------------------------------------------------
*     []void    :   pushFront(int x)    ->  Pushes (x) to front of Vector
*     []void    :   pushFront(Vector& V)->  Pushes entire Vector (V) to front 
*                                             of current Vector
*     []void    :   pushRear(int x)     ->  Pushes (x) to rear of Vector
*     []void    :   pushRear(Vector& V) ->  Pushes entire Vector (V) to end of
*                                             current Vector
*     []void    :   pushAt(int i, int x, int y, node* N)
*                                       ->  Pushes (x) onto Vector at index (i)
*                                             []Will resize if (i) is larger or
*                                                 smaller than current size
*                                             []If resized to larger Vector, 
*                                                 extra slots are filled with 
*                                                 value (y) [Default: 0]
*     []void    :   inOrderPush(int x)  ->  Checks to see if Vector is in 
*                                               ascending or descending order,
*                                               then adds value (x) to the
*                                               sorted slot
*    --------------------------------------------------------------------------
*     []int     :   popFront()          ->  Return AND Delete first value
*     []int     :   popRear()           ->  Return AND Delete last value
*     []int     :   popAt(int i)        ->  Return AND Delete value at index 
*                                             (i)
*    --------------------------------------------------------------------------
*     []int     :   find(int x)         ->  Search Vector for value (x)
*                                             []If found, return index value
*                                             []If NOT found, return -1
*     []void    :   resize(int s, int x, int y)
*                                       ->  Resize Vector to (s) size
*                                             []If new size is smaller, nodes
*                                                 at the end will be deleted to 
*                                                 accomodate
*                                             []If new size is larger, the 
*                                                 final node will contain 
*                                                 each newly-created node 
*                                                 before it will be populated 
*                                                 with integer (y) [Default: 0]
*     []void    :   print()             ->  Outputs Vectors to "test.out"    
*    --------------------------------------------------------------------------
*->Overloaded Operators:
*     Operator  :   Common In-Line Use  ->  Description 
*                                             [*]Unless stated, Overloaded 
*                                                 Operators will NOT alter 
*                                                 values within Vectors   
*       '+'     :   |----------------|  ->  Will Return a Vector whose values 
*                   |v1 = {1,2,3,4,5}|          equal the Sum of each matching
*                   |v2 = {1,2,3,4,5}|          index within the two Vectors
*                   |   (v1 + v2)    |          being considered
*                   |    Returns     |        
*                   |  {2,4,6,8,10}  |            
*                   |----------------|        
*       '-'     :   |----------------|  ->  Will Return a Vector whose values
*                   |v1 = {1,3,5,7,9}|          equal the Difference of each
*                   |v2 = {1,2,3,4,5}|          matching index within the two
*                   |   (v1 - v2)    |          Vectors being considered
*                   |    Returns     |       
*                   |  {0,1,2,3,4}   |            
*                   |----------------|                                                    
*       '*'     :   |----------------|  ->  Will Return a Vector whose values 
*                   |v1 = {1,2,3,4,5}|          equal the Product of each 
*                   |v2 = {1,2,3,4,5}|          matching index within the two 
*                   |   (v1 * v2)    |          Vectors being considered
*                   |    Returns     |            
*                   | {1,4,9,16,25}  |           
*                   |----------------|                                                        
*       '/'     :   |----------------|  ->  Will Return a Vector whose values 
*                   |v1 = {1,2,6,8,9}|          equal the Quotient of each
*                   |v2 = {1,1,3,2,3}|          matching index within the two  
*                   |   (v1 / v2)    |          Vectors being considered
*                   |    Returns     |            
*                   |  {1,2,2,4,3}   |            
*                   |----------------|  
*       '='    :    |----------------|  ->  Will assign whatever values are in
*                   |v1 = {0,1,2}    |          v2 to v1; essentially over-
*                   |v2 = {3,4,5,6,7}|          writing whatever v1 had in it
*                   |   (v1 = v2)    |          previously
*                   | Transforms v1: |        [*]Will also delete values if v2
*                   |  {3,4,5,6,7}   |            is smaller in size than v1
*                   |----------------|                                                                                                          
*       '=='    :   |----------------|  ->  Will Return a boolean value after
*                   |v1 = {1,2,3,4,5}|          comparing each matching index
*                   |v2 = {1,2,3,4,5}|          pair within the Vectors
*                   |   (v1 == v2)   |        []If each pair is equal to one-
*                   |    Returns     |            another, return TRUE
*                   |    (True)      |        []If pairs are not all equal, 
*                   |----------------|            return FALSE
*       '[]'    :   |----------------|  ->  Allows for array-like notation when
*                   |v1 = {6,7,8,9,0}|          using Vectors
*                   | int x = v1[2]  |        []The number within the square 
*                   |                |            brackets serves as the index
*                   |     x = 8      |            number
*                   |----------------|        [*]Vectors are 0-indexed                                                     
*ostream'<<'    :   |----------------|  ->  Allows for easy printing of Vectors
*                   |v1 = {1,2,3,4,5}|          to the terminal through  
*                   |   cout << v1;  |          standard ostream formatting
*                   |    Terminal    |       
*                   |     Output:    |            
*                   |  {1,2,3,4,5}   |      
*                   |----------------|            
*ofstream'<<'   :   |----------------|  ->  Allows for easy printing of Vectors
*                   |v1 = {1,2,3,4,5}|          to output file through standard
*                   | outfile << v1; |          ofstream formatting     
*                   |  File Output:  |            
*                   |  {1,2,3,4,5}   |      
*                   |----------------|                                       */
class Vector{
private:
    node* head;                     //node pointer for front of Vector
    node* tail;                     //node pointer for end of Vector
    int vectSize = 0;               //Will hold size of Vector

public:
    Vector();                   
    Vector(int[], int);
    Vector(std::string);     
    Vector(Vector&);    
    Vector(int);

    int getSize();                
    int peekFront();         
    int peekRear();            
    int peekInd(int);             

    void pushFront(int);    
    void pushFront(Vector&);
    void pushRear(int);     
    void pushRear(Vector&);
    
    int popFront();            
    int popRear();             
    int popAt(int);         

    int find(int);          
    void resize(int, int = 0, int = 0);

    void pushAt(int, int, int = 0, node* = NULL); 
    void inOrderPush(int);

    void print();

    Vector operator+(const Vector&);
    Vector operator-(const Vector&);
    Vector operator*(const Vector&);
    Vector operator/(const Vector&);

    void operator=(const Vector&);

    bool operator==(const Vector&);

    friend ostream &operator<<(ostream &cout, const Vector &V);
    /**************************************************************************
    * Overloaded Operator: (ofstream)'<<'         std::outfile << (Vector);
    * Use:  []Allows for easy outputting of Vectors to an outfile stream 
    *       []Iterates through the Vector, outputting each value before 
    *           surrounding them with "{}"                                   */
    friend ofstream &operator<<(ofstream &outfile, const Vector &V){
        if(!V.head)
            outfile << "{}";
        else{
            node* trav = V.head;
            outfile << '{';
            while(trav){
                outfile << trav->data << ((trav->next) ? ", " : "}");
                trav = trav->next;
            }
        }
        return outfile;
    }
    /**************************************************************************
    * Overloaded Operator: '[]'           int num = (Vector)v1[(int)x];
    * Use:  []Allows for array-like functionality within a Vector 
    *       []The number within the brackets serves as the index number within
    *           the Vector  
    *         -Note: Vectors are 0-indexed
    *       [](Vector)v1[2] would return whatever data is in the THIRD node of
    *           the Vector                                                   */
    int &operator[](int index){
        node * temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
};  

int main(){
    int a1[] = { 1, 2, 3, 4, 5 };
    int a2[] = { 10, 20, 30 };

    Vector v1(a1,5);
    Vector v2(a2,3);

    ofstream fout;
    fout.open("output.txt");

    cout << v1[2] << endl;
    // writes out 3

    v1[4] = 9;
    // v1 now = [1,2,3,4,9]

    cout << v1 << endl;
    // writes out [1,2,3,4,9] to console.

    fout << v1 << endl;
    // writes out [1,2,3,4,9] to your output file.

    Vector v3 = v1 + v2;
    cout << v3 << endl;
    // writes out [11,22,33,4,9] to console.

    v3 = v1 - v2;
    cout << v3 << endl;
    // writes out [-9,-18,-27,4,9] to console.

    v3 = v2 - v1;
    cout << v3 << endl;
    // writes out [9,18,27,4,9] to console.

    v3 = v2 * v1;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.

    v3 = v1 * v2;
    cout << v3 << endl;
    // writes out [10,40,90,4,9] to console.

    v3 = v1 / v2;
    cout << v3 << endl;
    // writes out [0,0,0,4,9] to console.

    v3 = v2 / v1;
    cout << v3 << endl;
    // writes out [10,10,10,4,9] to console.

    cout << (v2 == v1) << endl;
    // writes 0 to console (false) .

    Vector v4 = v1;
    cout << (v4 == v1) << endl;
    // writes 1 to console (true) .
}

/******************************************************************************
* Constructor:  Vector() 
* Usage:        Default constructor for Vector. Will NOT initialize any data
* Parameters:   N/A                                                          */
Vector::Vector(){
    head = tail = NULL;
}
/******************************************************************************
* Constructor:  Vector(int arr[], int initSize) 
* Usage:        Builds Vector that will be an exact copy of the array that is
*                 passed in.
* Parameters:   int arr[]       :   Base array that will be used 
*               int initSize    :   Size of array passed in to be used in a
*                                     for-loop                               */
Vector::Vector(int arr[], int initSize){
    head = tail = new node(arr[0]);     //Creates initial node, then ties head
                                        //  and tail to it
    vectSize++;                                 
    for(int i = 1; i < initSize; i++){  //If arr[] has more than 1 value, loop
        pushRear(arr[i]);               //  through it, adding each value to 
                                        //  back of Vector  
    }
}
/******************************************************************************
* Constructor:  Vector(std::string file) 
* Usage:        Builds Vector based on numbers from an input file. 
*                 -Numbers MUST be separated by either a line break or a Space
* Parameters:   std::string file:   Name of file to be used                  */
Vector::Vector(std::string file){
    ifstream infile;
    infile.open(file);
    int temp;
    infile >> temp;
    head = tail = new node(temp);       //Creates initial node with value from
                                        //  infile
    vectSize++;

    while(infile >> temp){              //Loop until all values in file are 
        pushRear(temp);                 //  added to back of Vector
    }
    infile.close();
}
/******************************************************************************
* Constructor:  Vector(Vector &v2) 
* Usage:        Builds Vector that is an exact deep-copy of whatever Vector is 
*                 passed in
* Parameters:   Vector &v2      :   Vector to be copied                      */
Vector::Vector(Vector& v2){
    head = tail = new node(v2.peekFront());     //Create initial node, then tie
    vectSize++;                                 //  head and tail to it

    if(v2.getSize() > 1){                       //If copied vector has >1 value
        for(int i = 1; i < v2.getSize(); i++){  //  traverse through it, adding
            pushRear(v2.peekInd(i));            //  each value to the end of
                                                //  Vector
        }
    }
}
/******************************************************************************
* Constructor:  Vector(int data) 
* Usage:        Builds Vector with 'data' as the only member
* Parameters:   int data        :   Single integer to be placed in Vector    */
Vector::Vector(int data){
    pushFront(data);
}

/******************************************************************************
* Function:     getSize()
* Parameters:   N/A  
* Returns:      [int] vectSize  :   Number of values in current Vector       */
int Vector::getSize(){
    return vectSize;
}
/******************************************************************************
* Function:     peekFront() 
* Parameters:   N/A  
* Returns:      [int] data      :   Value at front of Vector                 */
int Vector::peekFront(){
    return head->data;
}
/******************************************************************************
* Function:     peekRear()
* Parameters:   N/A  
* Returns:      [int] data      :   Value at back of Vector                  */
int Vector::peekRear(){
    return tail->data;
}
/******************************************************************************
* Function:     getInd(int index) 
* Parameters:   [int] index     :   Index within the Vector
* Returns:      [int] data      :   Value at (index)                         */
int Vector::peekInd(int index){
    if(index == 0)
        return peekFront();
    else if(index == vectSize-1)
        return peekRear();
    else{
        node* temp = head->next;
        for(int i = 1; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
}

/******************************************************************************
* Function:     pushFront(int data) 
* Parameters:   [int] data      :   Value to be added to front of Vector   
* Returns:      N/A                                                          */
void Vector::pushFront(int data){
    node* temp = new node(data, head);

    if(head)
        head->prev = temp;
    else
        tail = temp;        //sets tail to temp if it is first node 
    head = temp;
    vectSize++;
}
/******************************************************************************
* Function:     pushFront(Vector &v2) 
* Parameters:   [Vector&] v2    :   Vector to be copied and added to front of
*                                       current Vector   
* Returns:      N/A                                                          */
void Vector::pushFront(Vector &v2){
    node* trav = v2.head;
    while(trav){
        pushFront(trav->data);
        trav = trav->next;
    }
}
/******************************************************************************
* Function:     pushRear(int data) 
* Parameters:   [int] data      :   Value to be added to rear of Vector 
* Returns:      N/A                                                          */
void Vector::pushRear(int data){
    if(tail){
        node* temp = new node(data, NULL, tail);
        tail->next = temp;
        tail = temp;
        vectSize++;
    }
    else
        pushFront(data);
    
}
/******************************************************************************
* Function:     pushRear(Vector &v2) 
* Parameters:   [Vector&] v2    :   Vector to be copied and added to end of 
*                                       current Vector
* Returns:      N/A                                                          */
void Vector::pushRear(Vector &v2){
    for(int i = 0; i < v2.getSize(); i++){
        pushRear(v2.peekInd(i));
    }
}

/******************************************************************************
* Function:     popFront() 
* Parameters:   N/A 
* Returns:      [int] data      :   Value stored at front of Vector
*                                       (Also deletes value from Vector)     */
int Vector::popFront(){
    int data;
    if(vectSize == 1){
        data = head->data;
        delete head;
        head = tail = NULL;
    }
    else{
        data = head->data;
        node* temp = head;
        head = temp->next;
        head->prev = NULL;

        delete temp;
    }
    vectSize--;
    return data;
}
/******************************************************************************
* Function:     popRear() 
* Parameters:   N/A 
* Returns:      [int] data      :   Value stored at end of Vector
*                                       (Also deletes value from Vector)     */
int Vector::popRear(){
    int data;
    if(vectSize == 1){
        data = tail->data;
        delete tail;
        head = tail = NULL;
    }
    else{
        data = tail->data;
        node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;

        delete temp;
    }
    vectSize--;
    return data;
}
/******************************************************************************
* Function:     popAt() 
* Parameters:   [int] index     :   Index where desired value is at
* Returns:      [int] data      :   Value stored at front of Vector
*                                       (Also deletes value from Vector)     */
int Vector::popAt(int index){
    if(index==0){
        return popFront();
    }
    else if(index==vectSize-1){
        return popRear();
    }
    else{
        node* temp = head->next;
        for(int i = 1;i<index;i++){
            temp = temp->next;
        }
        int data = temp->data;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        vectSize--;
        delete temp;
        return data;
    }
}

/******************************************************************************
* Function:     find(int value) 
* Parameters:   [int] value     :   Value to be found in Vector
* Returns:      [int] data      :   Index where value was found
*                                       ([-1] if NOT found)                  */
int Vector::find(int value){
    if(head->data == value){
        return 0;
    }
    else if(tail->data == value){
        return vectSize-1;
    }
    else{
        int index = 1;
        node* trav = head->next;
        while(trav){
            if(trav->data == value)
                return index;
            else{
                index++;
                trav = trav->next;
            }
        }
    }
    return -1;
}
/******************************************************************************
* Function:     resize(int _size, int data, int finalValue) 
* Parameters:   [int] _size     :   Desired new size of Vector
*               [int] finalValue:   Value that will be at end of Vector if 
*                                       (_size) is larger than previous size 
*               [int] data      :   Value that will fill Vector if (_size) is 
*                                       larger than previous size          
* Returns:      N/A                                                          */
void Vector::resize(int _size, int finalValue, int _filData){
    int tempSize = vectSize;        //Had to set tempSize as vectSize changes
    if(_size > vectSize){           //  during method runtime
        for(int i = 0; i < ((_size - tempSize)-1);i++){
            pushRear(_filData);
        }
        pushRear(finalValue);
    }
    else if(_size < tempSize){
        int trash;
        for(int i = 0; i < (tempSize - _size);i++){
            trash = popRear();
        }
    }
}

/******************************************************************************
* Function:     pushAt(int index, int data, int filData, node* direct) 
* Parameters:   [int] index     :   Index where desired value is at
*                                       (Will resize larger if index is outside
*                                        of current bounds)
*               [int] data      :   Value to be pushed onto Vector at [index]
*               [int] filData   :   Value to fill Vector if resizing is needed
*               [node*] direct  :   Pointer to a node used by inOrderPush()
*                                       to directly append a node that has been
*                                       created in another method            
* Returns:      N/A                                                          */
void Vector::pushAt(int index, int data, int filData, node* direct){
    if(!direct){
        //if insert at beginning index, just use pushFront method
        if(index == 0){
            pushFront(data);
        }
        //if insert at end index, just use pushRear method
        else if(index == vectSize){
            pushRear(data);
        }
        else if(index > vectSize){
            resize(index+1,data,filData);
        }
        else{
            //traverse linked list to find location where node will be
            node* trav = head->next;
            for(int i = 1; i < index; i++){
                trav = trav->next;
            }
            //Create node and stitch it in
            node* temp = new node(data, trav, trav->prev);
            trav->prev = temp;
            temp->prev->next = temp;
            vectSize++;
        }
    }
    else{
        node* temp = new node(data, direct, direct->prev);
        direct->prev = temp;
        temp->prev->next = temp;
        vectSize++;
    }
}
/******************************************************************************
* Function:     inOrderPush(int _data) 
* Parameters:   [int] _data     :   Data to be inserted in either ascending or
*                                       descending order, which is decided by
*                                       the method
* Returns:      N/A                                                          */
void Vector::inOrderPush(int _data){
    if(!head||(head->data == tail->data)){
        pushFront(_data);
    }
    else if(head->data < tail->data){

        if(_data <= head->data){
            pushFront(_data);
        }
        else if(_data >= tail->data){
            pushRear(_data);
        }
        else{
            int index = 1;
            node* trav = head->next;
            while(trav){
                if(trav->data >= _data && trav->prev->data < _data){
                    pushAt(index, _data, 0, trav);
                    return;
                }
                else{
                    trav = trav->next;
                    index++;
                }
            }
        }
    }
    else if(head->data > tail->data){

        if(head->data <= _data){
            pushFront(_data);
        }
        else if(tail->data >= _data){
            pushRear(_data);
        }
        else{
            int index = 1;
            node* trav = head->next;
            while(trav){
                if(trav->data <= _data && trav->prev->data > _data){
                    pushAt(index, _data, 0, trav);
                    return;
                }
                else{
                    trav = trav->next;
                    index++;
                }
            }
        }
    }
}

/******************************************************************************
* Function:     print() 
* Parameters:   N/A
* Returns:      N/A                                                          */
void Vector::print(){
    ofstream outfile;
    outfile.open("test.out", ios::app);

    node* trav = head;
    outfile << '[';
    while(trav){
        outfile << trav->data << ((trav->next) ? ", " : "]\n");  
        trav = trav->next;
    }
}

/******************************************************************************
* Overloaded Operator: '+'     (Vector) = (Vector)v1 + (Vector)v2;
* Use:  []Adds together corresponding values in v1 with v2
*         -Note: "Corresponding" refers to matching indices within both Vectors
*       []Initializes and returns a Vector with the updated values
*       []If either v1 or v2 is larger than the other, the extra indices will 
*           not be affected                                                  */
Vector Vector::operator+(const Vector &rhs){
    node* v1 = this->head;
    node* v2 = rhs.head;
    Vector newV;
    
    while(v1 && v2){
        newV.pushRear((v1->data)+(v2->data));
        v1 = v1->next;
        v2 = v2->next;
    }
    while(v1){
        newV.pushRear(v1->data);
        v1 = v1->next;
    }
    while(v2){
        newV.pushRear(v2->data);
        v2 = v2->next;
    }
    
    return newV;
}
/******************************************************************************
* Overloaded Operator: '-'     (Vector) = (Vector)v1 - (Vector)v2;
* Use:  []Subtracts the values in v2 from their corresponding value in v1.
*         -Note: "Corresponding" refers to matching indices within both Vectors
*       []Initializes and returns a Vector with the updated values
*       []If either v1 or v2 is larger than the other, the extra values will 
*           not be affected                                                  */
Vector Vector::operator-(const Vector &rhs){
    node* v1 = this->head;
    node* v2 = rhs.head;
    Vector newV;

    while(v1 && v2){
        newV.pushRear((v1->data)-(v2->data));
        v1 = v1->next;
        v2 = v2->next;
    }
    while(v1){
        newV.pushRear(v1->data);
        v1 = v1->next;
    }
    while(v2){
        newV.pushRear(v2->data);
        v2 = v2->next;
    }
    
    return newV;
}
/******************************************************************************
* Overloaded Operator: '*'     (Vector) = (Vector)v1 * (Vector)v2;
* Use:  []Multiplies together each value in v1 to its corresponding value in v2
*         -Note: "Corresponding" refers to matching indices within both Vectors
*       []Initializes and returns a Vector with the updated values
*       []If either v1 or v2 is larger than the other, the extra values will 
*           not be affected                                                  */
Vector Vector::operator*(const Vector &rhs){
    node* v1 = this->head;
    node* v2 = rhs.head;
    Vector newV;

    while(v1 && v2){
        newV.pushRear((v1->data)*(v2->data));
        v1 = v1->next;
        v2 = v2->next;
    }
    while(v1){
        newV.pushRear(v1->data);
        v1 = v1->next;
    }
    while(v2){
        newV.pushRear(v2->data);
        v2 = v2->next;
    }
    
    return newV;
}
/******************************************************************************
* Overloaded Operator: '/'     (Vector) = (Vector)v1 / (Vector)v2;
* Use:  []Performs integer division through dividing the values in v1 by the 
*           corresponding values in v2
*         -Note: "Corresponding" refers to matching indices within both Vectors
*       []Initializes and returns a Vector with the updated values
*       []If either v1 or v2 is larger than the other, the extra values will 
*           not be affected                                                  */
Vector Vector::operator/(const Vector &rhs){
    node* v1 = this->head;
    node* v2 = rhs.head;
    Vector newV;

    while(v1 && v2){
        newV.pushRear((v1->data)/(v2->data));
        v1 = v1->next;
        v2 = v2->next;
    }
    while(v1){
        newV.pushRear(v1->data);
        v1 = v1->next;
    }
    while(v2){
        newV.pushRear(v2->data);
        v2 = v2->next;
    }
    
    return newV;
}
/******************************************************************************
* Overloaded Operator: '='     (Vector)v1 = (Vector)v2;
* Use:  []Copies and assigns to v1 whatever values are in v2.
*       []If any values were previously in v1, they will be overwriten
*       []If v1 was a different size than v2, v1 will automatically resize   */
void Vector::operator=(const Vector &rhs){
    if(this->head == rhs.head)
        return;
    node* trav = rhs.head;
    if(vectSize)
        this->resize(0);
    while(trav){
        this->pushRear(trav->data);
        trav = trav->next;
    }
}
/******************************************************************************
* Overloaded Operator: '=='     (bool) = ((Vector)v1 == (Vector)v2);
* Use:  []Iterates through v1 and v2, checking to see if each corresponding 
*           value is equal to one another
*       []If all values ARE equal, returns TRUE
*       []If all values are NOT equal, returns FALSE                         */
bool Vector::operator==(const Vector &rhs){
    node* v1 = this->head;
    node* v2 = rhs.head;
    bool isTrueFlag;
    while(v1 && v2){
        if(v1->data != v2->data)
            return false;
        v1 = v1->next;
        v2 = v2->next;
    }
    return true;
}

/******************************************************************************
* Overloaded Operator: (ostream)'<<'         std::cout << (Vector);
* Use:  []Allows for easy printing of Vectors to the console 
*       []Iterates through the Vector, outputting each value before 
*           surrounding them with "{}"                                       */
inline ostream &operator<<(ostream &cout, const Vector &V){
    if(!V.head)
        cout << "{}";
    else{
        node* trav = V.head;
        cout << '{';
        while(trav){
            cout << trav->data << ((trav->next) ? ", " : "}");
            trav = trav->next;
        }
    }
    return cout;
}
