#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  int r,g,b;
  char head[20];
  snprintf(head,sizeof(head),"P3 500 500 255\n");
  int fd = open("pic.ppm", O_CREAT|O_TRUNC|O_WRONLY, 0644);
  write(fd,head,sizeof(head));
  
  int x,y;
  char pixel[15];
  for (x=0;x<500;x++){
    for (y=0;y<500;y++){
      r = (y+100)%255;
      g = (x*y-124)%255;
      b = (x-162)%255;
      snprintf(pixel,sizeof(pixel),"%d %d %d\n",r,g,b);
      write(fd,pixel,sizeof(pixel));
    }
  }
  close(fd);
  return 0;
}
	    
