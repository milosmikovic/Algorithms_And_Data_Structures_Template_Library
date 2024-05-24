#include "DataStructures/vector.hpp"
#include "DataStructures/sllist.hpp"
#include <list>

struct Foo
{
    friend std::ostream& operator<<(std::ostream&, const Foo&);

    Foo(int a = 0, int b = 0, int *memory = new int(0)) : a(a), b(b), memory(memory) {}
    
    Foo(const Foo &rhs) : a(rhs.a), b(rhs.b), memory(new int(*rhs.memory)) {std::cout << "cpy=" << std::endl;}
    Foo(Foo &&rhs) noexcept : a(rhs.a), b(rhs.b), memory(rhs.memory) { rhs.memory = nullptr; std::cout << "move=" << std::endl;}

    ~Foo() { delete memory; std::cout << "~Foo()" << std::endl;}
    
    Foo& operator=(const Foo &rhs)
    {
        std::cout << "cpy=" << std::endl;

        if(this != &rhs)
        {
            a = rhs.a;
            b = rhs.b;
            memory = new int(*rhs.memory);
        }

        return *this;
    }

    Foo& operator=(Foo &&rhs) noexcept
    {
        std::cout << "move=" << std::endl;

        if(this != &rhs)
        {
            a = rhs.a;
            b = rhs.b;
            memory = rhs.memory;

            rhs.a = 0;
            rhs.b = 0;
            rhs.memory = nullptr;
        }
        
        return *this;
    }

    void change_a(int value)
    {
        a = value;
    }

    private:
        int a;
        int b;
        int *memory;
};

std::ostream& operator<<(std::ostream &os, const Foo &foo)
{
    os << foo.a << "-" << foo.b << "-" << *foo.memory;
    return os;
}

int main(int argc, char **argv)
{

    std::list<int> l;
    // erase(iterator), insert(iterator, value)

    // adstl::vector<int>::change_realloc_size(3);

    // adstl::vector<int> vec1;
    // vec1.push_back(2);
    // vec1.push_back(3);
    // vec1.push_back(4);
    // vec1.push_back(5);
    // adstl::vector<int> vec2 = vec1;
    
    // std::cout << vec2 << std::endl;
    
    // vec2.push_back(123);

    // adstl::vector<int> vec3;
    // vec3 = vec2;

    // std::cout << vec3 << std::endl;

    // adstl::vector<int> vec4(std::move(vec3));

    // std::cout << vec4 << std::endl;

    // adstl::vector<int> vec5;
    // vec5 = std::move(vec4);

    // std::cout << vec5 << std::endl;

    // std::cout << vec5[3] << std::endl;

    // adstl::vector<Foo> fVec1;
    // fVec1.push_back(Foo(2,3));
    // fVec1.push_back(Foo(3,4));
    // fVec1.push_back(Foo(2,3));
    // fVec1.push_back(Foo(3,4));
    // fVec1.push_back(Foo(2,3));
    // fVec1.push_back(Foo(3,4));
    // Foo f(31, 213);
    // fVec1.push_back(f);
    // std::cout << "#" << std::endl;
    // adstl::vector<Foo> fVec2(fVec1.begin(), fVec1.end());

    // std::cout << fVec2 << std::endl;


    adstl::sllist<Foo> sl1;
    sl1.push_back(Foo(1,2, new int(2)));
    sl1.push_back(Foo(3,4, new int(3)));
    sl1.push_back(Foo(4,5, new int(4)));


    adstl::sllist<Foo> sl2 = sl1;
    adstl::sllist<Foo> sl3 = std::move(sl1);
    adstl::sllist<Foo> sl4;
    adstl::sllist<Foo> sl5;
    sl4 = sl3;
    sl5 = std::move(sl3);


    std::cout << sl2 << std::endl;
    std::cout << sl4 << std::endl;
    std::cout << sl5 << std::endl;

    std::cout << sl5[1] << std::endl;

    try
    {
        std::cout << sl5[3] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    Foo &a = sl5[1];
    a.change_a(123);

    std::cout << sl5 << std::endl;
    

    // BEGIN_ITERATOR_TEST

    // adstl::sllist<Foo>::iterator iter1 = sl5.begin();
    // // adstl::sllist<Foo>::const_iterator iter2 = sl5.cbegin();

    // auto &item1 = *iter1;
    // // auto &item2 = *iter2;
    // item1.change_a(23);
    // // item2.change_a(23);


    // while(iter1 != sl5.end())
    // {
    //     std::cout << *iter1 << std::endl;
    //     ++iter1;
    // }
    // std::cout << "###" << std::endl;
    // for(auto it = sl5.begin(); it != sl5.end();++it)
    // {
    //     std::cout << *it << std::endl;
    //     *it = Foo();
    // }

    // const adstl::sllist<Foo> sl6 = sl5;
    // for(auto it = sl6.cbegin(); it != sl6.cend();++it)
    // {
    //     std::cout << *it << std::endl;
    //     // *it = Foo();
    // }

    // END_ITERATOR_TEST

    sl5.pop_back();
    sl5.pop_back();
    sl5.pop_back();
    sl5.push_back(Foo(321,321));
    std::cout << sl5 << std::endl;
    sl5.push_back(Foo(111,111));
    sl5.push_back(Foo(222,222));
    sl5.pop_back();
    sl5.push_back(Foo(333,333));
    std::cout << sl5 << std::endl;
    sl5.clear();
    std::cout << sl5 << std::endl;

    sl5.push_back(Foo(111,111));
    sl5.push_back(Foo(222,222));
    sl5.push_back(Foo(333,333));
    std::cout << sl5 << std::endl;
    sl5.insert(0, Foo(000,000));
    std::cout << sl5 << std::endl;
    sl5.insert(1, Foo(110,110));
    std::cout << sl5 << std::endl;
    sl5.insert(3, Foo(220,220));
    std::cout << sl5 << std::endl;
    sl5.insert(6, Foo(220,220));
    std::cout << sl5 << std::endl;

    try
    {
        sl5.insert(8, Foo(220,220));
    }
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << sl5 << std::endl;


    return 0;
}