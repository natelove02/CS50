// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");
    printf("You will owe $%.2f each!\n", half(bill_amount,tax_percent,tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float nonpercenttax = tax * .01;
    float nonpercenttip = tip * .01;
    float notiptotal = bill + (bill * nonpercenttax);
    float half = (notiptotal + (notiptotal * nonpercenttip))/2;
    return half;
}
