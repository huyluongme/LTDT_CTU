void add_edge(Graph *pG, int x, int y){
    pG->edges[pG->m].x = x;
    pG->edges[pG->m].y = y;
    pG->m++;
}