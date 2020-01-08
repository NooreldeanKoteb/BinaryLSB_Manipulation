#include<stdio.h>
#include<stdlib.h>
#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte)  \
  (byte & 0x80 ? 1 : 0), \
    (byte & 0x40 ? 1 : 0), \
    (byte & 0x20 ? 1 : 0), \
    (byte & 0x10 ? 1 : 0), \
    (byte & 0x08 ? 1 : 0), \
    (byte & 0x04 ? 1 : 0), \
    (byte & 0x02 ? 1 : 0), \
    (byte & 0x01 ? 1 : 0)
#define PRINTBIN(x); printf(BYTETOBINARYPATTERN, BYTETOBINARY(x));

unsigned char getlsbs(unsigned char *p){
  unsigned char byte0=0;
  for(int i=0; i<8;i++){
    unsigned char tempByte[8]={BYTETOBINARY(p[i])};
    if (tempByte[7] == 1){
      byte0 = byte0|(1<<i);
    }
  }
  printf("Byte0: %d --> ",byte0);
  PRINTBIN(byte0);
  printf("\n");
  return byte0;
}
void setlsbs(unsigned char *p, unsigned char b0){
  unsigned char byte[8]={BYTETOBINARY(b0)};
  unsigned char newArr[8];
  for(int i=0; i<8;i++){
    if (byte[7-i]==1){
      newArr[i]=(p[i]|1);
      printf("Array val %d: %d --> ",i,newArr[i]);
      PRINTBIN(newArr[i]);
      printf("\n");
    }else{
      newArr[i]=(p[i]&254);
      printf("Array val %d: %d --> ",i,newArr[i]);
      PRINTBIN(newArr[i]);
      printf("\n");
    }
  }
  getlsbs(newArr);
}
int main(int argc, char* argv[]){
  if (argc != 2){
    exit(0);
    printf("Error: Inccorrect Number Of Arguments!");
  }
  unsigned char val[8]={};
  int seed;
  sscanf(argv[1],"%d",&seed);
  srand(seed);
  unsigned char byte0 = rand()%255;
  for(int i=0; i<8;i++){
    val[i]= rand()%255;
    printf("Array val %d: %d --> ",i,val[i]);
    PRINTBIN(val[i]);
    printf("\n");
  }
  printf("Byte0: %d --> ",byte0);
  PRINTBIN(byte0);
  printf("\n");
  setlsbs(val,byte0);
}
