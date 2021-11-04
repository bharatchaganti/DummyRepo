#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int
main(int argc, char *argv[])
{
  int i, x;

  if(argc != 2){
    exit();
  }
  settickets(10);
  for(i=1; i< atoi(argv[1]); i++)
      x += i;
  exit();
  return x;
}
