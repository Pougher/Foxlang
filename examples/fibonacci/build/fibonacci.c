#include <stdint.h>
#include <stdio.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int64_t i64;
typedef int32_t i32;
typedef int16_t i16;
typedef int8_t i8;
typedef float f32;
typedef double f64;

;

i32 fib(i32 i){
    if (i==0)return 0;
    else if (i==1)return 1;
    else return (fib(i-1)+fib(i-2));
}

i32 main(){
    
    printf("The 10th fibonacci number is: %d\n", fib(9));
    return 0;
}
