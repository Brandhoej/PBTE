#pragma twice

<<<<<<< HEAD
typedef struct edge {
	int distance;
=======
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
>>>>>>> 1c675b14178f44365b50c0c6b2fe32324793bace
} edge;
