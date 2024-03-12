#include <iostream>

#include "Poney.class.hpp"


int main() {
    //no checks about the the location of the instances, was it required for the exercice ?
    ponyOnTheHeap("My little poney", 2, "The Heap");
    ponyOnTheStack("Old and boring poney", 22, "The Stack");
    return 0;
}