typedef struct Hub {
    int inventory;
    int capacity;
    int balance;
    double weight;
} Hub;

void calcBalance(Hub *hub) {
    hub->balance = hub->capacity/2;
}