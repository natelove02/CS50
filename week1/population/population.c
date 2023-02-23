#include <cs50.h>
#include <stdio.h>

int threshold (int start, int end);

int main(void)
{
   int start_size;
    do
    {
        start_size = get_int("Start Size: ");
    }
    while (start_size < 9);

    int end_size;
    do
    {
        end_size = get_int("End Size: ");
    } 
    while (start_size > end_size);
    
    printf("Years: %i\n",threshold(start_size, end_size));
}

int threshold (int start, int end){
    int years = 1;
    int born;
    int died;
    int currpop = start;
    if (start == end){
        return years = 0;
    }
    while (currpop < end){
        born = currpop/3;
        died = currpop/4;
        currpop = currpop + born - died;
        if (currpop >= end){
            return years;
        }
        else years++;


    }
}
