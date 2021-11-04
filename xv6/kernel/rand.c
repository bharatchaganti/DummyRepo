/* The following code is added by Bharat vxc210006
** Modified by Brighton Mica (bdm210003)
** function to create a random number to pick the tickets for next running process. 
*/
#include "rand.h"

#define PHI 0x9e3779b9
static unsigned int Q[4096], c = 362436;

void srand(unsigned int x)
{
  int i;

  Q[0] = x;
  Q[1] = x + PHI;
  Q[2] = x + PHI + PHI;

  for (i = 3; i < 4096; i++)
    Q[i] = Q[i - 3] ^ Q[i - 2] ^ PHI ^ i;
}

unsigned int rand(void)
{
  if(sizeof(unsigned long long) != 8){
    return 0;
  }
  unsigned long long t, a = 18782LL;
  static unsigned int i = 4095;
  unsigned int x, r = 0xfffffffe;
  i = (i + 1) & 4095;
  t = a * Q[i] + c;
  c = (t >> 32);
  x = t + c;
  if (x < c) {
    x++;
    c++;
  }
  return (Q[i] = r - x);
}
/* End of code added/modified */


