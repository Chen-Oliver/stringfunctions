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
  *dest =0;
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
char *mystrchr(char *s, char c){
  while(*s){
    if(*s == c)return s;
    s++;
  }
  return NULL;
}

int main(){
  char testlen[10] = "string";
  printf("Testing strlen...\n");
  printf("Length of 'string': %d\n\n",mystrlen(testlen));
  printf("Testing strcpy...\n");
  char cpydest[100] = "this is the destination";
  char cpysrc[50] = "this is the source";
  printf("dest: %s\n", cpydest);
  printf("src: %s\n", cpysrc);
  printf("dest after strcpy: %s\n\n",mystrcpy(cpydest,cpysrc));
  printf("Testing strncpy...\n");
  char ncpydest[10] = "bye world";
  char ncpysrc[4]="hey";
  printf("dest: %s\n", ncpydest);
  printf("src: %s\n", ncpysrc);
  printf("strncpy(length 3): %s\n\n",mystrncpy(ncpydest,ncpysrc,3));
  printf("Testing strcat/strncat...\n");
  char str1[20] = "foo";
  char str2[]="bar";
  printf("str1: %s\n", str1);
  printf("str2: %s\n", str2);
  printf("str1 after strcat: %s\n",mystrcat(str1,str2));
  printf("str1 after strncat(length 2): %s\n\n",mystrncat(str1,str2,2));
  printf("Testing strcmp...\n");
  printf("comparing abcd to abc:  %d\n",mystrcmp("abcd","abc"));
  printf("comparing abcd to abcz: %d\n",mystrcmp("abcd","abcz"));
  printf("comparing abcd to abcd:  %d\n\n",mystrcmp("abcd","abcd"));
  printf("Testing strchr...\n");
  char haystack[]="octopus";
  char needle ='u';
  printf("haystack:%s\n",haystack);
  printf("needle:%c\n",needle);
  printf("needle found at: %p\n\n", mystrchr(haystack,needle));

  return 0;
}
