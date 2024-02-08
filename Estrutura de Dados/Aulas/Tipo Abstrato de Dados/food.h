typedef struct _food Food;
typedef struct _spice_list SpiceList;


SpiceList *newSpiceList(int size);
void viewSpiceList(SpiceList *spices);
void sizeofSpiceList(SpiceList *sipicesRef);
void addSpice(Food *foodRef, char *siceAddRef);
void destroySpiceList(SpiceList **sipicesRef);


Food *cookingFood(char *foodName, float price, int isVegan, int isFreeze, int spicesSize);
void viewFood(Food foodRef);
void isVegan(Food foodRef);
void addFoodInFreeze(Food foodRef);
void unFreeze(Food foodRef);
int isFreeze(Food foodRef);
void eat(Food **foodRef);




