#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char s[]){
  int i=0;
  while(s[i]) i++;
return i;
}
char *mystrcpy(char *dest, char *src){
  char *orig = dest;
  while(*src) *(dest++) = *(src++);
  *(++dest) = 0;
  return orig;
}
char *mystrncpy(char *dest, char *src, size_t len){
  int i=0;
  for(;i<len&&src[i]!=0;i++)dest[i] = src[i];
  for(;i<len;i++)dest[i] = 0;
  return dest;
}

int main(){
  char a[100] = "dankest";
  char b[20] = "meme";
  printf("%s\n",mystrcpy(a,b));
  return 0;
}
