#include <stdio.h>
#include <string.h>

#define  SIZE_TABLE     10
#define  SIZE_ITEM      20


int compare( const void *cmp1, const void *cmp2)
{
   return strcmp( (char *)cmp1, (char *)cmp2);
}


int main( void)
{
   char  table[SIZE_TABLE][SIZE_ITEM]  = { "com", "embedded", "falinux", "forum", "jwmx", "linux"};
   char *ptr;

   ptr   = (char *)bsearch( "forum", table, SIZE_TABLE, SIZE_ITEM, compare);
   printf( "찾아진 문자열= %s\n", ptr);

   ptr   = (char *)bsearch( "embedded", table, SIZE_TABLE, SIZE_ITEM, compare);
   printf( "찾아진 문자열= %s\n", ptr);

   ptr   = (char *)bsearch( "jwjw", table, SIZE_TABLE, SIZE_ITEM, compare);
   printf( "찾아진 문자열= %s\n", ptr);
   
   return 0;
}