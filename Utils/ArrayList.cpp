#include <Utils/ArrayList.hh>
#include <Utils/memory.hh>
#include <Utils/types.hh>
namespace Utils{
    //template<typename E>
    //ArrayList<E>::ArrayList()

    template<typename E>
    void ArrayList<E>::add(E &item){
        if(this->getRealSize() == this->size)
            this->grow();
        this->array[size++] = item;
    }

    template<typename E>
    E ArrayList<E>::remove(E &item){
        int index = this->indexOf(item);
        if(index == -1){
            return NULL;
        } 
        return this->remove(index);
    }

    template<typename E>
    E ArrayList<E>::remove(int index){
        E ret = this->array[index];
        memmov(this->array, this->array, index + 1, this->getRealSize(), index);
        return ret;
    }

    template<typename E>
    int ArrayList<E>::indexOf(E &item){
        for(int i = 0; i < this->size; i++)
            if(item == this->array[i])
                return i;
        return -1;
    }

    template<typename E>
    void ArrayList<E>::grow(){
        E * tmp = new E[this->getRealSize()*2];
        memcpy(tmp, this->array, this->getRealSize());
        this->array = tmp;
    }
    
    template<typename E>
    int ArrayList<E>::getRealSize(){
        return sizeof(this->array)/sizeof(E);
    }
};