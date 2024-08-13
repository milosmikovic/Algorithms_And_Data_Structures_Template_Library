#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <memory>
#include "config.hpp" // Include the configuration header

namespace adstl
{

template <typename T>
class queue
{
    // 0 1 2 3 4 5
    public:
        

    private:

        static std::allocator<T> alloc;
        T *begin;
        T *end;
        


};


}


#endif