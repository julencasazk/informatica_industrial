#include <stdio.h>

 typedef struct st_ex {

      long                  var1 :  4;
      unsigned long  var2 : 24;
      long                  var3;

} EX;

int main() {

   EX  a, *b;
  a.var1 = 0x0F;
  a.var2 = 0x80F321;
  a.var3 = -2;
  b = &a;

  *((unsigned char*)&(b->var3) + 1) = (char)(a.var1+2);
  a.var2 = ((char)a.var1 << 6); 
  printf("0x%08X\n", (&a)->var2);
  printf("%d\n", *((unsigned short*)&(b->var3) + 1));
  printf("0x%08X\n", a.var3);

  return(0);

}
