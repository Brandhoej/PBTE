typedef struct Vehicle {
    int inventory;
    int capacity;
} Vehicle;

typedef enum VehicleType {TRUCK, BICYCLE} VehicleType; 
int availableCapacity(Vehicle *vehicle);