// CS311 Yoshii F23 - HW5 Priority Queue Implementation File
// Complete all ** parts and give good comments
// ** NEVER delete my comments.

// =================================================
// HW5 Priority Printer Queue 
// YOUR NAME: Kayla Le
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// constructor
pqueue::pqueue()
{  count = 0;  // no jobs yet
}

// destructor does nothing
pqueue::~pqueue() {}

// Purpose: to add a job to a right place in the Pqueue
// Argument: j is the job priority number
// Remember that the current last job is in slot count-1.
void pqueue::insertjob(int j)
{
  cout << "Adding: " << j << endl;
  //  add the job j at the rear (and update count)
  //    if impossible else display error message. 
  if(count != MAX){//count is not at  MAX
    Q[count] = j;//add job j to rear
    count++; //update count
  }
  else{ cout << "Error: Queue is Full" << endl;   }//notify user that queue is full 
  trickleup(); // moves the job to the right place
}

// Purpose: to print a job and reheapify the Pqueue
void pqueue::printjob()
{
  cout << "Printing: " << Q[0] <<endl;//print first job
  reheapify(); //call reheapify to trickle down
}

// Purpose: to display all jobs
void pqueue::displayAll()
{ cout << "Jobs: " ;
  // loop to display jobs from slot 0 to slot count-1 horizontally. No need to show a tree format.
 for(int i = 0;i < count;i++){
   cout << Q[i] << "  "; 
}
cout << endl; 
}

// Utility functions follow: ------------------
//PURPOSE: swapping 2 jobs with each other 
//PARA: the location of the 2 jobs
void pqueue::swap(int loc1, int loc2)
{
  //  simply swap the values in these locations in Q
  int val1 = Q[loc1];//getting vallue from loc1 in Q

  Q[loc1] = Q[loc2];//storing value of loc2 to loc1
  Q[loc2] = val1;//stroiing value of loc1 to loc2
}

// Purpose: to make the very last job trickle up to the right location.
// Never do X--. 
void pqueue::trickleup()
{ 
  int x = count-1;  // the very last job's location
 
  //  While x is > 0   
  //    compare Q[x] with the parent value (*)
  //    and if the parent value is bigger call swap & update x 
  //    to be the parent location. Otherwise stop the loop.
  // (*) Call getParent to get the location of the parent
  //            based on the child's location.
  while(x > 0){
   int Ploc = getParent(x);//get Parent location
   if(Q[x] < Q[Ploc]){//if parent is greater swap
      swap(x,Ploc);//swapping
      x = Ploc;//updating to parent location
   }
  else{break;} //if parent is less break out of loop
  }
 
}

// Purpose: find the location of the parent 
// PARA: The child location is given.  Need to call even.
int pqueue::getParent(int childloc)
{   //  return the parent location based on the child loc

if(even(childloc))//if child is the RC subtract 2 and then divide by 2
 return ((childloc-2)/2);
else//if child is the LC subtract one and divide by 2
 return ((childloc-1)/2);
  
}

// Purpose: is location i even? Important in finding its parent location
// PARA: int you what to see is even - true if even, false if odd
bool pqueue::even(int i)
{
  if ((i % 2) ==  0) return true; else return false; }




// Purpose: to reheapify the Pqueue after printing
//  This trickles down.  Never do X++.
void pqueue::reheapify()
{ int X;   // the current location
  Q[0] = Q[count-1];  // move the last job to the front

  count--;//update count
  //  Start X at 0 (the root)
  X = 0;//root
  //  While X is within the array (the used portion):
  //       Find the location of the smaller child by calling getSmallerchild.
  //       (if the location of both children are off the tree, stop the loop).
  //       If the smaller child is smaller than the parent value,
  //          call swap and X becomes the smaller child's location.
  //       else no swaps so stop to loop.
while(X < count ){//if X is less tahn count (in range)
    int smallChildloc = getSmallerchild(X); //get location of smallerChild
   if(smallChildloc == 11)//special vallue (no children), break loop
       break;
  else if(Q[smallChildloc] < Q[X]){//if the smallerChild is less than Parent, swap
      swap(X,smallChildloc);//swapping 
      X = smallChildloc;//make X(parent)  = smallerChildLocation 
   }
   else
    break;//if Parent is less than smallerChild, break loop
 }  
}

// Purpose: to find the location of the smaller child
// where children are at locations 2*i+1 and 2*i+2
// PARA: location of parent 
int pqueue::getSmallerchild(int i)
{ int LC, RC; // locations of children
  LC = 2*i+1;RC = 2*i+2; // set LC and RC first.
//    return the location of the smaller child

//    Be careful because one or both of them may be
//    //    beyond count-1 or just the RC is beyond count-1.
//    //    Check LC and RC against boundaries before you
//    //    compare Q contents!!!!
//    //    If both are beyond count-1, you want to return a special value.

if(LC > count -1 && RC >count -1)//if LC and RC are out of bounds return 11
 return  11;//special value
else if(RC > count - 1)//if RC is out of bounds (not exist) return LC 
  return LC;


if(Q[LC] < Q[RC])//if LC is less than RC return LC, else return RC
 return LC;
else 
 return RC;

}
// NEVER GO TO UNUSED PART OF THE ARRAY 
