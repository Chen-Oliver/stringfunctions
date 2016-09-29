#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mystrlen(char *s){
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
char *mystrncpy(char *dest, char *src, int len){
  int i=0;
  for(;i<len&&src[i]!=0;i++)dest[i] = src[i];
  for(;i<len;i++)dest[i] = 0;
  return dest;
}
char *mystrcat(char *dest, char *src){
  mystrcpy(mystrlen(dest)+dest,src);
  return dest;
}
char *mystrncat(char *dest, char *src, int len){
  mystrncpy(mystrlen(dest)+dest,src,len);
  return dest;
}
int mystrcmp(char *s1, char *s2){
  while(*s1 == *s2 && *s1 && *s2){
    s1++;
    s2++;
  }
  return *s1 - *s2;
}
int mystrncmp(char *s1,char *s2, int len){
  
}
int main(){
  char a[100] = "cool";
  char b[20] = "cat";
//  printf("%s\n",mystrncpy(a,b,4));
//  printf("%s\n",mystrncat(a,b,2));
  char c[10]="abcde";
  char d[10]="abc";
  //printf("%d\n",mystrcmp(c,d));
  //printf("%d\n",strcmp(c,d));
  printf("%d\n",mystrncmp(c,d,3));
  printf("%d\n",strncmp(c,d,3));
  return 0;
}
