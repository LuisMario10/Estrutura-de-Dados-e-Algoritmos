typedef struct _integer_Array {
    int *array;
    int now;
    int size;
}integerArray;

integerArray *newIntegerArray(int size);
void add(integerArray *arrayRef, int numberRef);
void remove(integerArray *arrayRef, int numberId);
void removeFinal(integerArray *arrayRef);
int sumAll(integerArray *arrayRef);
int search(int numberRef);
int sort(integerArray *arrayRef);
void deleteIntergerArray(integerArray **arrayRef);