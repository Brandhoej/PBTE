#pragma twice

/**
 * \struct This struct caontains the information used to connect verticies in the graph.
 */
typedef struct {

    /**
     * This is one of the verticies that is conencted by this edge
    */
    int u;

    /**
     * This is one of the verticies that is conencted by this edge
    */
    int v;

    /**
     * This is the distance between the two verticies
    */
    double distance;
} edge;
