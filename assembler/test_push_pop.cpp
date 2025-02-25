#include "stack.hpp"
#include <cassert>
#include <iostream>
#include "../string/string.hpp"

int main ()
{
    {
        stack<int> int_stack;
        
        assert(int_stack.empty() == true); 
        int_stack.push(1);
        int_stack.push(2);
        int_stack.push(3);
        assert(int_stack.full() == false);  
        assert(int_stack.empty() == false); 
        assert(int_stack.top() == 3);       
        int three = int_stack.pop();
        int two = int_stack.pop();
        assert(int_stack.top() == 1);       
        int one = int_stack.pop();
        assert(int_stack.empty() == true); 
        assert(one == 1);
        assert(two == 2);
        assert(three == 3);
    }
    {
        stack<double> double_stack;

        assert(double_stack.empty() == true); 
        double_stack.push(1.7);
        double_stack.push(2.4);
        double_stack.push(3.3);
        assert(double_stack.full() == false);  
        assert(double_stack.empty() == false); 
        assert(double_stack.top() == 3.3);   
        double three = double_stack.pop();
        double two = double_stack.pop();
        assert(double_stack.top() == 1.7);     
        double one = double_stack.pop();
        assert(double_stack.empty() == true); 

        assert(one == 1.7);
        assert(two == 2.4);
        assert(three == 3.3);
    }
    {
        stack<String> str_stack;

        assert(str_stack.empty() == true); 
        str_stack.push("ab");
        str_stack.push("cd");
        str_stack.push("ef");
        assert(str_stack.full() == false);  
        assert(str_stack.empty() == false); 
        assert(str_stack.top() == "ef");  
        String three = str_stack.pop();
        String two = str_stack.pop();
        assert(str_stack.top() == "ab");   
        String one = str_stack.pop();
        assert(str_stack.empty() == true); 
        assert(one == "ab");
        assert(two == "cd");
        assert(three == "ef");
    }
    std::cout << "Done Testing Push and Pop" <<std::endl;
}