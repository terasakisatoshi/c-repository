#include<stdio.h>

unsigned int xor32(void){
    static unsigned int y=2463534242;
    y=y^(y<<13);
    y=y^(y>>17);
    y=y^(y<<5);
    return y;
}

unsigned int xor64(void){
    static long x=88172645463325252ULL;
    x=x^(x<<13);
    x=x^(x>>7);
    x=x^(x<<17);
    return x;
}

unsigned int xor96(void){
    static unsigned int x=123456789;
    static unsigned int y=362436069;
    static unsigned int z=521288629;
    unsigned int t;
    t = (x ^ (x <<3)) ^ (y ^ (y >> 19))^(z^(z<<6));
    x=y;y=z;z=t;
    return z;
}

unsigned int xor128(void){
    static unsigned int x=123456789;
    static unsigned int y=362436069;
    static unsigned int z=521288629;
    static unsigned int w=88675123;
    unsigned int t;
    t=x^(x<<11);
    x=y;y=z;z=w;
    w=(w^(w>>19))^(t^(t>>8));
    return w;
}

int main(void){
    unsigned int count=100;
    for (unsigned int i = 0; i < count; ++i)
    {
        printf("%u\n",xor64() );
    }    
}
