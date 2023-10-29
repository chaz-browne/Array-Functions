#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#define size (4000000ULL)

int min = RAND_MAX;
int r, min_count = 0;
int idx2 = 0;
int sum = 0, sum2 = 0;
long long unsigned int i = 0;

struct array_t{
        uint8_t *arr;
        uint8_t *arr2;
        size_t len;
        size_t len2;
};

uint8_t arr_malloc(struct array_t *a, struct array_t b){
        a->len = 0xaaaaaaa;
        b.len = 0xbbbbbbb;

        return 0;
}

//creates an array.
void arr_make(struct array_t a){
        for(i = 0; i < a.len; i++){
                r = rand() % 1000;
                a.arr[i] = r;
                sum += a.arr[i];
        }
//finds the minimum of this array. 
uint8_t find_minimum(struct array_t a){
        for(i = 0; i < a.len; i++){
                if(a.arr[i] < min){
                        min = a.arr[i];
                }
        return min;
}

//finds the amount of minimum occurences and modifies the length. 
uint8_t min_amount(struct array_t a){
        for(i = 0; i < a.len; i++){
                if(a.arr[i] == min){
                        min_count++;
                }
        }
        a.len2 = a.len - min_count;
        printf("The new length is %d\n", a.len2);
        return min_count;
}
uint8_t find_and_delete_minimum(struct array_t a){
        for(i = 0; i < a.len; i++){
                //adjusts the minimum.
                if(a.arr[i] < min){
                        min = a.arr[i];
                }
                //when it isnt the minimum it will be added to the new array.
                //my problem with this is.... what if the array is already copied in but a minimum isn't really found.
                else if(a.arr[i] != min){               
                        a.arr2[idx2] = a.arr[i];
                        sum2 += a.arr2[idx2];
                        idx2++;
                        }
                }
                a.len2 = a.len - min_count;
                printf("The new length is %d\n", a.len2);
                return min;
 }

int main(){
        struct array_t x,y;
        x.len = y.len = 0;
        arr_malloc(&x,y);
        printf("x.len = %h\n");
        arr_make();
        find_delete_minimum();
        return 0;
 }
