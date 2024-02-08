#include "food.h"
#include <stdio.h>
#include <stdlib.h>

struct _spice_list {
    char **spices;
    int size;
};

struct _food {
    char *foodName;
    float price;
    int isVegan;
    int isFreeze;
    SpiceList *spices;
};


SpiceList *newSpiceList(int size) {
    SpiceList *newList = (SpiceList*) calloc(1, sizeof(SpiceList));
    newList->spices = (char**) calloc(size, sizeof(char*));
    newList->size = size;
    return newList;
}


Food *cookingFood(char *foodName, float price, int isVegan, int isFreeze,int spicesSize) {
    Food *newFood = (Food*) calloc(1, sizeof(Food));
    newFood->foodName = foodName;
    newFood->price = price;
    newFood->isVegan = isVegan;
    newFood->isFreeze = isFreeze;
    newFood->spices = newSpiceList(spicesSize);
    return newFood;
}