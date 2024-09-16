#include "heatNode.h"
#include "heatNode.cpp"
#include "heatStack.h"
#include "heatStack.cpp"
#include "msgNode.h"
#include "msgNode.cpp"
#include "msgQueue.h"
#include "msgQueue.cpp"
#include<iostream>
using namespace std;

int main()
{
    cout<<"\nMSGNODEMSGNODEMSGNODEMSGNODEMSGNODEMSGNODEMSGNODEnMSGNODEMSGNODEMSGNODE\n";
    
    msgNode<string> *A = new msgNode<string>("Animal",4);
    msgNode<string> *B = new msgNode<string>("Bear",5);
    msgNode<string> *C = new msgNode<string>("Cat",6);
    msgNode<string> *D = new msgNode<string>("Dog",7);
    msgNode<string> *E = new msgNode<string>("Elephant",8);
    msgNode<string> *F = new msgNode<string>("Frog",9);
    
    msgQueue<string> myQueue;
    
    cout<<"\n-----------------------------------------------------------------enqueue(t)\n";
    myQueue.enqueue(A);
    myQueue.enqueue(B);
    myQueue.enqueue(C);
    myQueue.enqueue(D);
    myQueue.enqueue(E);
    myQueue.print();
    
    cout<<"\n-----------------------------------------------------------------compileMessageData()\n";
    myQueue.compileMessageData();
    
    cout<<"\n-----------------------------------------------------------------peek()\n";
    msgNode<string> *G = myQueue.peek();
    cout << G->getMessage()<<endl;
    cout << G->getSize()<<endl;
    
    cout<<"\n-----------------------------------------------------------------dequeue()\n";
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.print();
    
    cout<<"\n-----------------------------------------------------------------compileMessageData()\n";
    myQueue.compileMessageData();
    
    cout<<"\n-----------------------------------------------------------------\n";
    cout<<"\nHEATNODEHEATNODEHEATNODEnHEATNODEHEATNODEHEATNODEHEATNODEHEATNODEHEATNODE\n";
    
    heatNode<double> *a = new heatNode<double>(2.5,2);
    heatNode<double> *b = new heatNode<double>(3,29);
    heatNode<double> *c = new heatNode<double>(3.5,5);
    heatNode<double> *d = new heatNode<double>(4,4);
    heatNode<double> *e = new heatNode<double>(4.5,245);
    heatNode<double> *f = new heatNode<double>(5.5,1);
    
    heatStack<double> mystack;
    
    cout<<"\n-----------------------------------------------------------------push(t)\n";
    mystack.push(a);
    mystack.push(b);
    mystack.push(c);
    mystack.push(d);
    mystack.push(e);
    mystack.push(f);
    
    mystack.print();
    
    cout<<"\n-----------------------------------------------------------------validateCooling(t)\n";
    int *heat = new int(6);
    for(int i=0  ;  i<6  ;  i++)
        heat[i] = i+1;
    
    if(mystack.validateCooling(heat, 6) == 0 )
        cout<<"false\n";
    else
        cout<<"true\n";
    
    
    cout<<"\n-----------------------------------------------------------------peek()\n";
    heatNode<double> *g = mystack.peek();
    cout << g->getCoolantLevel()<<endl;
    cout << g->getPower()<<endl;
    
    
    cout<<"\n-----------------------------------------------------------------pop()\n";
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    mystack.pop();
    
    mystack.pop();
    mystack.pop();
    
    mystack.print();
    
    cout<<"\n-----------------------------------------------------------------end\n";
    
    return 0;
}