#include "DynamicList.h"

using namespace std;

template <class T>
DynamicList<T>::DynamicList(){
    this->head = NULL;
}

template <class T>
DynamicList<T>::~DynamicList(){
    Node<T>* temp = this->head;
    while(temp != NULL){
        temp = temp->next;
        delete head;
        head = temp;
    }
}

template <class T>
int DynamicList<T>::getSize() const{
    if(this->head == NULL)
        return 0;
    
    else{
        int count = 0;
        Node<T>* current = this->head;

        while(current != NULL){
            count++;
            current = current->next;
        }
        return count;
    }
}

template <class T>
Node<T>* DynamicList<T>::getHeadNode(){
    return this->head;
}

template <class T>
void  DynamicList<T>::operator+=(const T val){
    Node<T>* nodePtr;
    Node<T>* newNode;
    newNode = new Node<T>(val);

    if(this->head == NULL){
        newNode->next = newNode;
        newNode->prev = newNode;
        this->head = newNode;
    }

    else{
        nodePtr = head->prev;
        nodePtr->next = newNode;
        newNode->prev = nodePtr;
        newNode->next = this->head;
        this->head->prev = newNode;
    }
}

template <class T>
void DynamicList<T>::operator+=(const DynamicList<T>& list){
   if(list.head == NULL) return;
   else{
       Node<T>* nodePtr = list.head;
       int i = 0;

       while(i < list.getSize()){
           this->operator+=(*(nodePtr->value));
           nodePtr = nodePtr->next;
           i++;
       }
   }
}

template <class T>
T DynamicList<T>::operator[](const int index){
    const int size = getSize();
    if(!this->head || index < 0) return -1;

    else if(index == (size - 1)) return *(this->head->prev->value);

    else if(index == 0) return *(this->head->value);

    else{
        Node<T>* nodePtr = this->head;
        int i = 0;
        while(i < index){
            nodePtr = nodePtr->next;
            i++;
        }
        return *(nodePtr->value);
    }
}

template <class T>
bool DynamicList<T>::insertNodeAt(const int index, const T val){
    Node<T>* newNode = new Node<T>(val);
    Node<T>* nodePtr = this->head;
    int i = 1;

    if(index > this->getSize() && index < 0) return false;

    else{
        if(index == 0){
            this->head->prev->next = newNode;
            newNode->next = this->head;
            newNode->prev = this->head->prev;
            this->head->prev = newNode;
            this->head = newNode;
            return true;
        }

        else if(!this->head){
            this->head = newNode;
            newNode->next = newNode->prev;
            newNode->prev = newNode;
            return true;
        }

        else{
            while(i < index){
                nodePtr = nodePtr->next;
                i++;
            }
            newNode->next = nodePtr->next;
            newNode->next->prev = newNode;
            newNode->prev = nodePtr;
            nodePtr->next = newNode;
            return true;
        }
    }
    return false;
}

template <typename T>
bool DynamicList<T>::deleteNode(T value){

    
    Node<T>* nodePtr;
    Node<T>* preNode;

    bool status;

    if(this->head != NULL)
    {
        if(this->head->value == value)
        {
            nodePtr = this->head->next;
            preNode = this->head->prev;
            delete this->head;
            this->head = nodePtr;
            this->head->prev = preNode;
            status = true;
        }
        else{
            nodePtr = head;
            Node<T>* temp;
            Node<T>* temp2;

            for(int x = 0; x < this->getSize(); x++)
            {
                if(nodePtr == value)
                {
                    temp = nodePtr->next;
                    temp2 = nodePtr->prev;
                    delete nodePtr;
                    nodePtr->prev->next = temp;
                    nodePtr->next->prev = temp2;
                }
                nodePtr = nodePtr->next;
            }
            status = true;
        }
    }
    else    status = false;

    return status;
}

template <typename T>
bool DynamicList<T>::operator ==(const DynamicList<T>& list){
    Node<T>* firstNode = list.head;
    Node<T>* secondNode = this->head;
	bool status = true;
    int listNodeSize = list.getSize(), NodeSize = this->getSize(), i = 0;

	if(listNodeSize == NodeSize){
		while(i < NodeSize){
			if(*(firstNode->value) != *(secondNode->value)) return false;
			
            else{
                firstNode = firstNode->next;
                secondNode = secondNode->next;
            }
            i++;
		}
	}

    else if(listNodeSize != NodeSize) return false;

	return true;
}


template<class T>
ostream& operator<<(ostream& output, const DynamicList<T>& list){	
    int size = list.getSize();
    Node<T>* nodePtr = list.head;
	output<< "";
	if(size == 0 || !list.head) return output;
	
	while(nodePtr){
		if(nodePtr->next == list.head){
			output << *(nodePtr->value);
            output <<"[";
            output << *(nodePtr->prev->value);
            output << ",";
            output << *(nodePtr->next->value);
            output << "]";
			break;
		}

        else{
            output << *(nodePtr->value);
            output << "[";
            output << *(nodePtr->prev->value);
            output << ",";
            output << *(nodePtr->next->value);
            output <<"] -> ";
		    nodePtr = nodePtr->next;
        }
		
	}
    return output;
}
