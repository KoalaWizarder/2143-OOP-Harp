/******************************************************************************              
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
*                               class definitions to see every way a Vector can 
*                               be created
*  Files:            
*     [] input.dat  :   Series of integers to be used in constructing a Vector
*     [] test.out   :   Output file where results are printed
*****************************************************************************/

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
    node(int n = NULL, node* _next = nullptr, node* _prev = nullptr){
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
*
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
*                                               of current Vector
*     []void    :   pushRear(int x)     ->  Pushes (x) to rear of Vector
*     []void    :   pushRear(Vector& V) ->  Pushes entire Vector (V) to end of
*                                               current Vector
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
*                                               (i)
*    --------------------------------------------------------------------------
*     []int     :   find(int x)         ->  Search Vector for value (x)
*                                             []If found, return index value
*                                             []If NOT found, return -1
*     []void    :   resize(int s, int x, int y)
*                                       ->  Resize Vector to (s) size
*                                       ->  If new size is smaller, nodes at
*                                               the end will be deleted to 
*                                               accomodate
*                                       ->  If new size is larger, new nodes 
*                                               will be filled with value (x)
*                                               [Default: 0] and the final
*                                               node will contain value (y) 
*                                               [Default: 0]
*     []void    :   print()             ->  Outputs Vectors to "test.out"    */
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
    void resize(int, int, int);

    void pushAt(int, int, int, node*); 
    void inOrderPush(int);

    void print();
};  

int main(){
    //Functions to clear output file before Vector::print() appends data to it
	ofstream outfile;
    outfile.open("test.out");
    outfile << "Mervyn Harp" << '\n';
    outfile << "05-FEB-2023" << '\n';
    outfile << "Spring 2143" << "\n\n";
    outfile.close();
    outfile.open("test.out", ios::app);

    int x = 0;

    Vector v1;
    v1.pushFront(18);
    v1.pushFront(20);
    v1.pushFront(25);
    v1.pushRear(18);
    v1.pushRear(20);
    v1.pushRear(25);
    v1.print();
    // [25, 20, 18, 18, 20, 25]

    int A[] = {11,25,33,47,51,65};
    Vector v2(A,5);
    v2.print();
    // [11, 25, 33, 47, 51]


    v2.pushFront(9);

    v2.inOrderPush(27);

    v2.pushRear(63);
    v2.print();
    // [9, 11, 25, 33, 47, 51, 63]

    v1.pushRear(v2);
    v1.print();
    // [25, 20, 18, 18, 20, 25, 9, 11, 25, 33, 47, 51, 63]

    x = v1.popFront();
    x = v1.popFront();
    x = v1.popFront();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 27, 33, 47, 51, 63]
    outfile<<x<<endl;
    // 18

    x = v1.popRear();
    x = v1.popRear();
    x = v1.popRear();
    v1.print();
    // [18, 20, 25, 9, 11, 25, 27, 33]
    outfile<<x<<endl;
    // 47

    x = v2.popAt(3);
    v2.print();
    // [9, 11, 25, 33, 47, 51, 63]
    outfile<<x<<endl;
    // 27

    x = v2.find(51);
    outfile<<x<<endl;
    // 5

    x = v2.find(99);
    outfile<<x<<endl;
    // -1

    Vector v3(v1);
    v3.print();
    // [18, 20, 25, 9, 11, 25, 27, 33]

    v3.pushFront(v2);
    v3.print();
    //[9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

    Vector v4("input.dat");
    v4.pushRear(v3);
    v4.print();
    // [56, 61, 97, 66, 83, 25, 26, 11, 53, 49, 62, 18, 10, 18, 14, 3, 4, 23, 18, 24, 26, 27, 54, 14, 12, 45, 65, 98, 56, 97, 15, 84, 98, 9, 11, 25, 33, 47, 51, 63, 18, 20, 25, 9, 11, 25, 27, 33]

}

Vector::Vector(){
    head = tail = NULL;
}
Vector::Vector(int arr[], int _size){
    head = tail = new node(arr[0]);     //Creates initial node, then ties head
                                        //  and tail to it
    vectSize++;                                 
    for(int i = 1; i < _size; i++){     //If arr[] has more than 1 value, loop
        pushRear(arr[i]);               //  through it, adding each value to 
                                        //  back of Vector  
    }
}
Vector::Vector(std::string file){
    ifstream infile;
    infile.open(file);
    int temp;
    infile >> temp;
    head = tail = new node(temp);       //Creates initial node with value from
                                        //  infile
    vectSize++;

    while(infile >> temp){              //Loop until all values in file are 
                pushRear(temp);         //  added to back of Vector
    }
    infile.close();
}
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

int Vector::getSize(){
    return vectSize;
}
int Vector::peekFront(){
    return head->data;
}
int Vector::peekRear(){
    return tail->data;
}
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
* Parameters:   [int] data      :   Value to be added to Vector   
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
void Vector::pushFront(Vector &v2){
    for(int i = v2.getSize()-1; i >= 0; i--){
        pushFront(v2.peekInd(i));
    }
}
/******************************************************************************
* Function:     pushFront(int data) 
* Parameters:   [int] data      :   Value to be added to Vector   
* Returns:      N/A                                                          */
void Vector::pushRear(int data){
    if(tail){
        node* temp = new node(data, NULL, tail);
        tail->next = temp;
        tail = temp;
    }
    else
        pushFront(data);

    vectSize++;
}
void Vector::pushRear(Vector &v2){
    for(int i = 0; i < v2.getSize(); i++){
        pushRear(v2.peekInd(i));
    }
}

int Vector::popFront(){
    int data;
    if(vectSize == 1){
        data = head->data;
        delete head;
        head = tail = NULL;
        vectSize--;
        return data;
    }
    else{
        data = head->data;
        node* temp = head;
        head = temp->next;
        head->prev = NULL;

        vectSize--;
        delete temp;
        return data;
    }
}
int Vector::popRear(){
    int data;
    if(vectSize == 1){
        data = tail->data;
        delete tail;
        head = tail = NULL;

        vectSize--;
        return data;
    }
    else{
        data = tail->data;
        node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;

        vectSize--;
        delete temp;
        return data;
    }
}
int Vector::popAt(int index){
    if(index==0){
        vectSize--;
        return popFront();
    }
    else if(index==vectSize-1){
        vectSize--;
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
void Vector::resize(int _size, int data = 0, int finalValue = 0){
    if(_size > vectSize){
        for(int i = 0; i < (_size - vectSize)-1;i++){
            pushRear(data);
        }
        pushRear(finalValue);
    }
    else if(_size < vectSize){
        int trash;
        for(int i = 0; i < (vectSize - _size);i++){
            trash = popRear();
        }
    }
}

void Vector::pushAt(int index, int data, int filData = 0, node* direct = NULL){
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
            resize(index+1,filData,data);
        }
        else{
            //traverse linked list to find location where node will be
            node* trav = head->next;
            for(int i = 1; i < index; i++){
                trav = trav->next;
            }
            //Create node and delete it
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

void Vector::print(){

    ofstream outfile;
    outfile.open("test.out", ios::app);

    node* trav = head;
    int _size = vectSize;
    outfile << '[';
    while(trav){
        outfile << trav->data;  
        trav = trav->next;
        if(_size-- == 1)
            outfile << "]\n";

        else
            outfile << ", ";
    }
}
