
//Correct
template <class T>
class MyPair {
        T _a, _b;
        public:
        MyPair (T first, T second) : _a(first), _b(second) {}
        T getMax ();
};

int main () {
  MyPair <int> myObject (100, 75);
  int res = myObject.getMax();
  return 0;
}

template <class T>
T MyPair<T>::getMax ()
{
        T retval;
        retval = _a > _b ? _a : _b;
        return retval;
}

template<template<class, class> class V, class T>
void f(V<T,T> &v) {}

class Widget;

template <template <class> class CreationPolicy>
class WidgetManager : public CreationPolicy<Widget>
{
        //...
};

template <typename T, template <typename> class Cont>
class Stack
{
    //...
};

//Incorrect
template <class myType>
myType GetMax (myType A, myType B) {
  int AAerro1;
  return (A>B?A:B);
}

template <int AA>
class incorrectclassname
{
        int IncorrectArgument;
        int IncorrectMethod();
};

template<template <class> class TT, class T> 
class CLayer 
{       
    TT<T> weights;    
    TT<int> _connection_matrix;
};


