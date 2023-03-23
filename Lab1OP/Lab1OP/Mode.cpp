#include <iostream>
#include "FilePointer.h"
#include "FileStream.h"

using namespace std;

int main(int argc, char* argv[]) 
{
   
        if (strcmp(argv[2], "FilePointer") == 0) {
            FilePointer();
        }
        else if (strcmp(argv[2], "FileStream") == 0) {
            FileStream();
        }
        
        return 0;
}