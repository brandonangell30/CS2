#include "string.hpp"
#include <cassert>
#include <vector>
#include <iostream> 
int main(){
    {
    //------------------------------------------------------
    // SETUP FIXTURE
    String str("abc ef gh");
    std::vector<String> expected{ "abc", "ef", "gh" };

    // TEST
    std::vector<String> result = str.split(' ');

    // VERIFY
    assert(str == "abc ef gh");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); i++) {
        assert(result[i] == expected[i]);
    }
}


{
    String str("apple,banana,blueberry");
    std::vector<String> expected{"apple", "banana", "blueberry"};

    std::vector<String> result = str.split(',');
    assert(str == "apple,banana,blueberry");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str(",,,");
    std::vector<String> expected{"", "", "", ""};

    std::vector<String> result = str.split(',');
    assert(str == ",,,");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str("cowboy space ");
    std::vector<String> expected{"cowboy", "space", ""};

    std::vector<String> result = str.split(' ');
    assert(str == "cowboy space ");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str("outer-space-");
    std::vector<String> expected{"outer", "space", ""};

    std::vector<String> result = str.split('-');
    assert(str == "outer-space-");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str("123 456 789");
    std::vector<String> expected{"123", "456", "789"};

    std::vector<String> result = str.split(' ');
    assert(str == "123 456 789");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str("uno:dos:tres:quatro");
    std::vector<String> expected{"uno", "dos", "tres", "quatro"};

    std::vector<String> result = str.split(':');
    assert(str == "uno:dos:tres:quatro");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str("   ");
    std::vector<String> expected{"", "", "", ""};

    std::vector<String> result = str.split(' ');
    assert(str == "   ");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str("split.test.not.fun");
    std::vector<String> expected{"split", "test", "not", "fun"};

    std::vector<String> result = str.split('.');
    assert(str == "split.test.not.fun");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}

{
    String str("abc def  ghi");
    std::vector<String> expected{"abc", "def", "", "ghi"};

    std::vector<String> result = str.split(' ');
    assert(str == "abc def  ghi");
    assert(result.size() == expected.size());
    for (int i = 0; i < (int)expected.size(); ++i) assert(result[i] == expected[i]);
}
std::cout << "Done testing split." << std::endl;
}

