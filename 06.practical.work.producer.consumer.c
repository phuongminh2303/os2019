#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

typedef struct {
    char type;      // 0 = fried chicken, 1 = French fries
    int amount;     // piesces or weights
    char unit;      // 0 = piece, 1 = gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
    while ((first + 1) % BUFFER_SIZE == last){
        // do nothing -- no free buffer item
    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
    item *i = malloc(sizeof(item));
    while (first == last){
        // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    
    // print out to confirm
    printf("Output 3: first: %d, last: %d\n", first, last);
    return i;
}

item *initItem(char type, int amount, char unit){
    item *i = malloc(sizeof(item));
    i -> amount = amount;
    i -> type = type;
    i -> unit = unit;
    return i;
}

int main(){
    item *input1 = initItem('0', 2, '0');
    item *input2 = initItem('1', 2, '1');

    printf("Input 1: type: %c, amount: %d, unit %c \n", input1 -> type, input1 -> amount, input1 -> unit);
    printf("Input 2: type: %c, amount: %d, unit %c \n", input2 -> type, input2 -> amount, input2 -> unit);
    printf("Initial value: first: %d, last: %d\n\n", first, last);

    // produce herer
    produce(input1);
    printf("Output 1: first: %d, last: %d\n", first, last);
    produce(input2);
    printf("Output 2: first: %d, last: %d\n", first, last);
    
    // consume here
    consume();

    return 0;
}