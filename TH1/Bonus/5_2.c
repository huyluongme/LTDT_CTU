void add_edge(Graph *pG, int x, int y){
    if(x < 1 || x > pG->n || y < 1 || y > pG->n) return;
    pG->edges[pG->m].x = x;
    pG->edges[pG->m].y = y;
    pG->m++;
}