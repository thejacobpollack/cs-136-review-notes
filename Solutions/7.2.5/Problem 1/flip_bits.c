// Solution to Bitwise Problem.

#include <assert.h>

/**
 * flip_bits( c ): Is passed one argument, a character, c. This
 *                 function will flip the bits in the character
 *                 and return the bytes' binary representation
 *                 as an integer.
 * PRE: c >= 0, and
 *      sizeof( char ) == 1, and
 *      sizeof( int ) == 4.
 * POST: returns an integer >= 0.
 */
int flip_bits( char c ) {
   // Checks pre conditions.
   assert( c >= 0 );
   assert( sizeof( char ) == 1 );
   assert( sizeof( int ) == 4 );
   
   // Declaring our new byte that will be constantly overwritten
   // in memory 
   int new_byte = 0;
   // Declaring the bit multiple starting from the most
   // significant bit.
   int multiple = 10000000;
   // Declaring the bit mask. It's 128 because we know our
   // input will be 1 byte. It is important the bit mask is
   // an unsigned char, otherwise 128 would not be possible.
   unsigned char mask = 0x80;
   
   // Iterates as long as the bitmask is non-zero. Each
   // iteration it will shift the bits one spot to the left.
   // If the character and the bit mask do not share an on
   // bit then it will give the new bit an on bit, otherwise
   // it wil give the new bit an off bit (by doing nothing).
   for ( ; mask != 0; mask >>= 1 ) {
      if ( !( c & mask ) ) {
         new_byte += multiple;
      }
      
      // Updates the multiple according to the bit we are
      // working with.
      multiple /= 10;
   }
   
   return new_byte;
}

int main( void  ) {
   // Some tests.
   assert( flip_bits( 0 ) == 11111111 );
   assert( flip_bits( 9 ) == 11110110 );
   
   return 0;
}