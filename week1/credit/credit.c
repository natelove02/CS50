#include <cs50.h>
#include <stdio.h>

void Validate(long CCNumber);
int TypeCheck(void);
int GetDigits(long Number);
void GetCCType(long CCNumber);
long CardNumber = 0;
//int Length = 0;
int main(void)
{

    do{
        CardNumber = get_long("Number: ");
    }
    while (CardNumber == 0);
        Validate(CardNumber);
}

void Validate(long CCNumber)
{
    int CCNumLength = GetDigits(CardNumber);
    int CCNumLength2 = CCNumLength;
    int CurrCCDigit = 0;
    int LuhnStep1 = 0; //Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    int LuhnProductDigits = 0;
    int LuhnStep2 = 0; //Add the sum to the sum of the digits that weren’t multiplied by 2.
    int LuhnTotal = 0; //If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    long CCNumber2 = CCNumber;
    /*if (CCNumLength != 15 || CCNumLength != 13 || CCNumLength !=16){
        printf ("INVALID\n");
        return;
    }*/
    for(int pointer = 0; pointer < CCNumLength; pointer++)
    {
        CurrCCDigit = CCNumber2%10;
       // printf ("%i", CurrCCDigit);
        //printf ("\n");
        if (pointer%2 != 0) //odd numbers are what we multiply and do the weird digit thing to
        {
            //printf ("%i", LuhnStep1);
            //printf ("\n");
            int DoubleCCDigit = CurrCCDigit*2;
            if ((CurrCCDigit * 2) > 9)
            {
                for (int j = 0; j < 2; j++)
                {
                    LuhnStep2 += (DoubleCCDigit%10);
                    DoubleCCDigit = DoubleCCDigit/10;
                }
            }
            else
             {
                LuhnStep2 += CurrCCDigit * 2;
            }

        }
        else
        {
            LuhnStep2 += CurrCCDigit;
        }
        //("%i", LuhnStep2);
        //printf ("\n");
        CCNumber2 = CCNumber2/10;
       }
       if (LuhnStep2%10 == 0){
        GetCCType(CCNumber);
       }
       else{
        printf("INVALID\n");
        return;
       }
    //printf ("%i", CCNumLength);
    //printf ("\n");
}

int GetDigits (long Number){
    int Length = 0;
    long CardNumberClone = CardNumber;
    while (CardNumberClone != 0)
    {
        Length++;
        CardNumberClone = CardNumberClone/10;
    }
    return Length;
}

void GetCCType (long CCNumber){
    int CCNumLength = GetDigits(CCNumber);
    int CurrDigit = 0;
    if (CCNumLength == 15)
    {
        for(int i = 0; i < CCNumLength; i++)
        {
            CurrDigit = CCNumber%10;
            if (i < 13)
            {
                CCNumber = CCNumber/10;
            }
            else
            {
                if (CurrDigit == 4 || CurrDigit == 7)
                {
                    CCNumber = CCNumber/10;
                    CurrDigit = CCNumber%10;
                    if (CurrDigit == 3)
                    {
                        printf ("AMEX\n");
                        return;
                    }
                    else
                    {
                        printf("INVALID\n");
                        return;
                    }

                }
                else
                {
                    printf("INVALID\n");
                    return;
                }
            }
        }
    }
    else if (CCNumLength == 16)
    {
        for(int i = 0; i < CCNumLength; i++)
        {
            CurrDigit = CCNumber%10;
            if (i < 14)
            {
                CCNumber = CCNumber/10;
            }
            else if (CurrDigit > 0 && CurrDigit < 6)
            {
                CCNumber = CCNumber/10;
                CurrDigit = CCNumber%10;
                if (CurrDigit == 5)
                {
                    printf ("MASTERCARD\n");
                    return;
                }
                else if (CurrDigit == 4)
                {
                    printf ("VISA\n");
                    return;
                }
                else{
                    printf("INVALID\n");
                    return;
                }
             }
             else
             {
                CCNumber = CCNumber/10;
                CurrDigit = CCNumber%10;
                if (CurrDigit == 4)
                {
                    printf ("VISA\n");
                    return;
                }
                else
                {
                    printf("INVALID\n");
                        return;
                }

             }

                }
            }
    else if (CCNumLength == 13){
        for(int i = 0; i < CCNumLength; i++)
        {
            CurrDigit = CCNumber%10;
            if (i < 12)
            {
                CCNumber = CCNumber/10;
            }
            else
            {
                if (CurrDigit == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }

            }
        }
    }

     else{
        printf("INVALID\n");
    }
}



