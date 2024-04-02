template <class T>
Monostack<T>::Monostack(){
    mSize = 64; // default stack size
    top = -1;
    myArray = new T[mSize];
    direction = 'i';
}

template <class T>
Monostack<T>::Monostack(int maxSize, char monotonicDirection){
    mSize = maxSize; // custom max stack size
    top = -1;
    myArray = new T[mSize];
    direction = monotonicDirection;
}

template <class T>
Monostack<T>::~Monostack() {
    delete[] myArray;
}

template <class T>
void Monostack<T>::push(T data){
    // resize if stack is full
    if (isFull()) {
        // create array twice the size
        T *temp = new T[2*mSize];
        
        // copy data from old array to new array
        for (int i = 0; i < mSize; ++i) {
            temp[i] = myArray[i]; 
        }

        // update variables
        mSize *= 2; 
        delete[] myArray;
        myArray = temp;
    }

    if (isEmpty()) {
        myArray[++top] = data;
        return;
    }
    else if (direction == 'i') {
        // continue until empty
        while (!isEmpty()) {
            if (peek() > data) pop(); // discards values larger than data
            else  {
                break; // break early if values start to be less than data
            }
        }
        myArray[++top] = data;
    }
    else {
        while (!isEmpty()) {
            if (peek() < data) pop(); // discards values smaller than data
            else  {
                break; // break early if values start to be greater than data
            }
        }
        myArray[++top] = data;
    }
}

template <class T>
T Monostack<T>::pop(){
    if (isEmpty()) {
        throw runtime_error("Stack is empty, nothing to pop");
    }

    return myArray[top--];
}

template <class T>
T Monostack<T>::peek(){
    if (isEmpty()) {
        throw runtime_error("Stack is empty, nothing to peek");
    }

    return myArray[top];
}

template <class T>
bool Monostack<T>::isFull() {
    return (top == mSize -1);
}

template <class T>
bool Monostack<T>::isEmpty() {
    return (top == -1);
}

template <class T>
int Monostack<T>::getSize() {
    return top + 1;
}

