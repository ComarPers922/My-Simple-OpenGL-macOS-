#include "utils.h"
#include <cstdlib>
#include <cstring>

unsigned char* utils::imgData(char *rawBmpData, int &width, int &height)
{
    if((*(unsigned short*)rawBmpData) != 0x4D42)
    {
        return nullptr;
    }

    int dataOffset = *((int*)(rawBmpData + 10));
    width = *((int*)(rawBmpData + 18));
    height = *((int*)(rawBmpData + 22));

    unsigned char colorContent[width * height * 3 + 1];
    memset(colorContent,'\0',width * height * 3 + 1);
    memcpy(colorContent, (unsigned char*)(rawBmpData + dataOffset),width * height * 3);

    for(int i = 0; i < width * height * 3;i += 3)
    {
        unsigned char temp = colorContent[i];
        colorContent[i] = colorContent[i+2];
        colorContent[i+2] = temp;
    }
    return colorContent;
}
