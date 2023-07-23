#include "main.h"
int main ()
{
  int result =
    _printf ("Hello, %s! This is %c testing the %%printf function.\n", "user",
	     'A');
  printf ("Total characters printed: %d\n", result);
  return 0;
}
