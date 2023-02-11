#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin(); MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << std::endl;
    std::cout << "Mstack normal" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }

    MutantStack<int> mstack_c;
    mstack_c.push(5);
    mstack_c.push(3);
    mstack_c.push(5);
    mstack_c.push(737);

    MutantStack<int>::const_iterator itc = mstack_c.cbegin(); MutantStack<int>::const_iterator itec = mstack_c.cend();

    std::cout << std::endl;
    std::cout << "Mstack c" << std::endl;
    while (itc != itec) {
        std::cout << *itc << std::endl;
        ++itc; 
    }

    MutantStack<int> mstack_r;
    mstack_r.push(5);
    mstack_r.push(3);
    mstack_r.push(5);
    mstack_r.push(737);

    MutantStack<int>::reverse_iterator itr = mstack_r.rbegin(); MutantStack<int>::reverse_iterator iter = mstack_r.rend();

    std::cout << std::endl;
    std::cout << "Mstack r" << std::endl;
    while (itr != iter) {
        std::cout << *itr << std::endl;
        ++itr; 
    }

    MutantStack<int> mstack_cr;
    mstack_cr.push(5);
    mstack_cr.push(3);
    mstack_cr.push(5);
    mstack_cr.push(737);

    MutantStack<int>::const_reverse_iterator itcr = mstack_cr.crbegin(); MutantStack<int>::const_reverse_iterator itecr = mstack_cr.crend();

    std::cout << std::endl;
    std::cout << "Mstack cr" << std::endl;
    while (itcr != itecr) {
        std::cout << *itcr << std::endl;
        ++itcr; 
    }

    std::cout << std::endl;
    std::cout << "Real stack" << std::endl;
    std::stack<int> s(mstack);
    int size = static_cast<int>(s.size());
    for (int i = 0; i < size; i++) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}
