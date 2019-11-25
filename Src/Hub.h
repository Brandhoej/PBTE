typedef struct Hub {
    unsigned int inventory;
    unsigned int capacity;
    int balance;
    double weight;
} Hub;

void calcBalance(Hub *hub);
void calcWeight(Hub *hub);