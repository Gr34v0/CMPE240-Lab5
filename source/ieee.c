#include <stdint.h>
#include "ieee.h"

#define checkBit(bit, bitfield) ((bitfield & (1 << bit)) == 0 )

//typedef struct {int32_t real; uint32_t fraction;} INT_FRACT;


IEEE_FLT IeeeEncode(INT_FRACT num){

    uint32_t loopCount;

    IEEE_FLT encodedNum;

    //Record sign of real number, then make the real number pos
    uint32_t signBit = checkBit(31, num.real);
    num.real &= (0 << 31);

    while(checkBit(31, num.real) != 1){
        loopCount = 0;
        //Shift the real number one to the left and backfill the low bit
        // from the high bit of the fraction
        num.real = (num.real << 1);
        num.real |= (checkBit(31, num.fraction) << 0);

        //Shift the fraction part one to the left
        num.fraction = (num.fraction << 1);

        //Keep executing this shifting loop until bit 31 is a one. Keep track of
        // the total number of shifts

        loopCount++;

    }

    //After bit 31 is a one, shift the real number eight bits to the right and remove
    // the implied 1. This is the mantissa
    num.real = (num.real >> 8);  //31 - 8 = 23


    //Calculate the bias exponent by subtracting the number of shifts from 158
    uint32_t baisExp = loopCount - 158;

    //Shift the exponent into the correct position and combine it with the sign and mantissa
    

    //Return the IEEE number
    return encodedNum;

}

IEEE_FLT IeeeMult(IEEE_FLT a, IEEE_FLT b){

    /*
        This function will multiply the IEEE single precision numbers “a” and “b” together and 
        return an IEEE single precision number.  You may use the underlying integer multiplication 
        routine “*”.  This routine must maximize precision.  This routine does not need to check for 
        overflow or underflow but does need to handle the 0.0 case
    */


}

IEEE_FLT IeeeAdd(IEEE_FLT a, IEEE_FLT b){

    /*
        This function will add the IEEE single precision numbers “a” and “b” together and return 
        an IEEE single precision number.  This routine must maximize precision.  This routine does 
        not need to check for overflow or underflow but does need to handle the 0.0 case
    */

}