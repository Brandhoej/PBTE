typedef struct vehicle {
    int inventory;
    int capacity;
} vehicle;

typedef enum vehicleType {TRUCK, BICYCLE} vehicleType; 
int availableCapacity(vehicle *v);