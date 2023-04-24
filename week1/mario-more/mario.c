#include <cs50.h>
#include <stdio.h>

void mariomaker (int height);

int main(void) 
{
    int mheight;
    do
    {
        mheight = get_int("Start Size: ");
    }
    while (mheight <= 0 || mheight > 8);
    printf ("Height: %i\n", mheight);
    mariomaker(mheight);

    
}

void mariomaker (int height){
    

    for (int i = 0; i < height ; i++){
        
            for (int k =0; k <height-i-1; k++){
                printf(" ");
            }
            for (int l = 0; l<=i; l++){
                printf ("#");
            }
            printf("  ");
            for (int m = 0; m<=i; m++ ){
                printf ("#");
            }
            printf ("\n");




    }


}