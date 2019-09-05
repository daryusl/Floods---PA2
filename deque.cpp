/**
 * @file deque.cpp
 * Implementation of the Deque class.
 *
 */

/* Constructor for the Deque class */
template <class T>
Deque<T>::Deque(){

/* your code here */
    k1 = 0;
    k2 = -1;

}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
 */
template <class T>
void Deque<T>::pushR(T const& newItem)
{
    /**
     * @todo Your code here!
     */
    data.push_back(newItem);
    k2++;
}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes. 
 *
 * @return The leftmost item of the Deque.
 */
template <class T>
T Deque<T>::popL()
{
    /**
     * @todo Your code here! 
     */
    
    T left = data[k1];
    k1++;
    if(k1 > k2/2){
        vector<T> temp;
        
        for(int i = k1; i <= k2; i++){
            temp.push_back(data[i]);
        }
        k1 = 0;
        if(k2%2==0){
            k2 = k2/2 - 1;
        }
        else{
            k2 = k2/2;
        }
        data.resize(k2+1);
        data = temp;
        
        
    }
    return left;
}
/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The rightmost item of the Deque.
 */
template <class T>
T Deque<T>::popR()
{
    /**
     * @todo Your code here! 
     */
    T right = data[k2];
    data.pop_back();
    k2--;
    if(k1 > k2/2){
        vector<T> temp;
        
        for(int i = k1; i <= k2; i++){
            temp.push_back(data[i]);
        }
        k1 = 0;
        if(k2%2==0){
            k2 = k2/2 - 1;
        }
        else{
            k2 = k2/2;
        }
        data.resize(k2+1);
        data = temp;
        
        
    }
    return right;

}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike popL(), this operation does not alter the deque.
 *
 * @return The item at the left of the deque.
 */
template <class T>
T Deque<T>::peekL()
{
    /**
     * @todo Your code here! 
     */
    return data[k1];

}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike popR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
 */
template <class T>
T Deque<T>::peekR()
{
    /**
     * @todo Your code here! 
     */
    return data[k2];
}

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
 */
template <class T>
bool Deque<T>::isEmpty() const
{
    /**
     * @todo Your code here! 
     */
    return data.empty();
}
