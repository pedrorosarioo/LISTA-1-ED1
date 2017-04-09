#include <stdio.h>
#include <stdlib.h>

int multiplica(int x, int y){
    if (y==1){
        return x;
    }else{
        return (x+multiplica(x,y-1));
    }
}





int main (){
int r;
r=multiplica(2,3);
printf("%d", r);

return 0;
}
