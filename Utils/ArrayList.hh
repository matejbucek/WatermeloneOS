#pragma once

namespace Utils{
    template<typename E>
    class ArrayList{
        const static int DEFAULT_SIZE = 10;
        int size;
        E * array;
    public:
        ArrayList(){
            this->array = new E[DEFAULT_SIZE];
            this->size = 0;           
        }
        void add(E &item);
        E remove(E &item);
        E remove(int index);
        void clear();
        int indexOf(E &item);
    private:
        //void grow(int size);
        void grow();
        int getRealSize();
    };
};