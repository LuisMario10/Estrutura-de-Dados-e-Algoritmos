typedef struct _string_list StringList;

char *createDynamicString(int sizeString);
void destroyDynamicString(char **stringRef);
StringList *newStringList( int capacity);
void sizeStringList(StringList *stringListRef);
void capacityStringList(StringList *stringListRef);
char *atStringList(StringList *stringListRef, int index);
char *getStringList(StringList *stringListRef, int index);
void appendStringList(StringList *stringListRef, char *element);
void printStringList(StringList *strigListRef);
void destroyStringList(StringList **stringListRef);


struct _string_list  {
    char **strings;
    int capacity; 
    int size;
};