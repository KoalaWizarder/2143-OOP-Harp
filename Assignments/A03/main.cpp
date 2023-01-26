/*****************************************************************************
*                    
*  Author:           Mervyn Harp
*  Email:            tylerharp98@gmail.com
*  Label:            A03 
*  Title:            Basic Project Organization
*  Course:           CMPS 2143
*  Semester:         Spring 2023
* 
*  Description:
*        -Program uses CircularArrayQue (class object defined below) to implement 
*           a queue (FIFO) system. If size of queue is not chosen at initialization,
*           default size of 10 will be chosen.
*        -The queue will NOT resize if attempting to push a new value onto it while
*           it is full.
*           
* 
*  Usage:
*        -Initialize queue object:
*               CircularArrayQue name;
*          OR:
*               CircularArrayQue name(int);      (int will determine size)
*
*        -Add items to end of queue:
*               name.push(int);                  (int = data to be stored)
*        -Return/Delete first item in queue:
*               name.pop();
* 
*  Files:
*        N/A
*****************************************************************************/
#include <iostream>

using namespace std;

/**
 * Circular Array Que
 * 
 * Description:
 *      Class creates a dynamic 1D array of n size, where n is set at each
 *        creation of CircularQueArray object by using parameters. If no size
 *        is chosen, n(size) defaults to 0
 * 
 * Public Methods:
 *                  CircularArrayQue()
 *                  CircularArrayQue(int size)
 *      void        Push(int item)
 *      int         Pop()
 * 
 * Private Methods:
 *      void        init(int size = 0)
 *      bool        Full()
 * 
 * Usage: 
 *      CircularArrayQue name;         // Create an object of this class(default size=10)
 *      CircularArrayQue name(int n)   // Create an object of this class(size = n)
 *      Push(int item)                 // Push data(item) onto top of queue. Will NOT resize queue
 *      Pop()                          // Returns and then deletes the first item in queue
 *      
 */
class CircularArrayQue {
private:
    int *Container;
    int Front;
    int Rear;
    int QueSize; // items in the queue
    int CurrentSize;
     /**
     * Private: init(int size = 0)
     * 
     * Description:
     *      Is used by the class constructor to set the size of array
     *        -Also sets front/rear/CurrentSize to 0 for use by Push/Pop methods later
     * 
     * Params:
     *      int size     Sets size of array. Defaults to 0
     * 
     * Returns:
     *      void
     */
    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    /**
     * Private: Full()
     * 
     * Description:
     *      Checks to see if que is full
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      bool  : True if Que is full
     */
    bool Full() {
        return CurrentSize == QueSize;
    }

public:
    /**
     * Public: CircularArrayQue()
     * 
     * Description:
     *      Default constructor for class
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      N/A
     */
    CircularArrayQue() {
        Container = new int[10];           // container now points to an empty array of size(10)
        init(10);                          // Initializes Front/Rear/CurrentSize to 0 
    }


    /**
     * Public: CircularArrayQue(int size)
     * 
     * Description:
     *      Constructor for class that allows different size parameter
     * 
     * Params:
     *      int size  :  Total size of array
     * 
     * Returns:
     *      N/A
     */
    CircularArrayQue(int size) {
        Container = new int[size];         // container now points to an empty array of size(size)
        init(size);                        // Initializes Front/Rear/CurrentSize to 0 
    }
    /**
     * Public: Push(int item)
     * 
     * Description:
     *      Adds item to end of que if not full
     *        -if full, print error message
     * 
     * Params:
     *      int size  :  Total size of array
     * 
     * Returns:
     *      N/A
     */
    void Push(int item) {
        if (!Full()) {                
            Container[Rear] = item;        // If que isnt full, push incoming data to back of queue
            Rear = (Rear + 1) % QueSize;   // Move Rear to new data location
            CurrentSize++;                 // Increase internal queue size by 1
        } else {
            cout << "FULL!!!!" << endl; 
        }
    }
    /**
     * Public: Pop()
     * 
     * Description:
     *      Returns first item in queue
     *      -Then deletes that item, thereby moving front to the next item
     * 
     * Params:
     *      N/A
     * 
     * Returns:
     *      int : Returns the int stored at front of queue
     */
    int Pop() {
        int temp = Container[Front];      // temp variable to hold front
        Front = (Front + 1) % QueSize;    // Moves front to next item in queue
        CurrentSize--;                    // Reduces total size
        return temp; 
    }
                                          // Allows overloader operator '<<' (defined on ln 169)
                                          //   to be used by class
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other);
};

/**
 * Overloading Operatior '<<'
 * 
 * Description:
 *      Allows for easy cout statements when wanting to output the full array
 *        -By sending in the output stream and the array address as parameters,
 *           the function iterates through the array, outputting each point of data
 *
 * Parameters:
 *      ostream &                 :  Send OS(usually console) to allow printing to said location
 *      const CircularArrayQue &  :  CircularArrayQue object to be printed
 * 
 *      
 */
ostream &operator<<(ostream &os, const CircularArrayQue &other) {

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);
    C1.Push(2);
    C1.Push(3);
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;

    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}
