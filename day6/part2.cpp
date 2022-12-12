
#include <iostream>

bool isDuplicates(std::string &in)
{
    for (int i = 0; i < in.length(); i++)
    {
        if (in.find_last_of(in[i]) != i)
            return true;
    }
    
    return false;
}

int getCharacterCount()
{
    std::string datastream;
    std::getline(std::cin, datastream);
    std::cout<<datastream<<std::endl;
    std::string subString;
    std::string uniqueSubstr;
    int count = 0;
    for (int i = 0; i < datastream.length(); i++)
    {
        subString = datastream.substr(i,4);
        if (!isDuplicates(subString))
        {
            std::cout<<"no duplicates were found: "<<subString<<std::endl;
            return i+14;
        }
    }
    std::cout<<count<<std::endl;
    return count;
}

int main()
{
    std::cout<<getCharacterCount()<<std::endl;
    return 0;
}
