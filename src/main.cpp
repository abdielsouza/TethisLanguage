#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int main(int argc, char const *argv[])
{
    
    return 0;
}

static void RunFile(const std::string& path)
{
    try
    {
        std::ifstream file(path, std::ios::in);
    }
    catch(const std::exception& e)
    {
        throw e.what();
    }
    
}

static void RunPrompt()
{

}