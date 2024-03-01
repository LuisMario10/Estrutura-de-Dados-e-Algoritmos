typedef struct _integer_Array {
    int *array;
    int now;
    int size;
}integerArray;

integerArray *newIntegerArray(int size);
void print(integerArray *arrayRef);
void add(integerArray *arrayRef, int numberRef);
void removeNumber(integerArray **arrayRef, int numberId);
void removeFinal(integerArray **arrayRef);
int sumAll(integerArray *arrayRef);
void sort(integerArray **arrayRef);
void deleteIntergerArray(integerArray **arrayRef);