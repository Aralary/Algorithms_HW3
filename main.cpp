#include <iostream>

int main(){
    SetGraph gr1(5);
    gr1.AddEdge(0,1);
    gr1.AddEdge(0,4);
    gr1.AddEdge(0,3);
    gr1.AddEdge(2,1);
    gr1.AddEdge(3,1);
    gr1.AddEdge(3,4);
    gr1.AddEdge(4,2);
    gr1.AddEdge(4,3);
    gr1.print_data();

    IGraph* g = &gr1;
    MatrixGraph gr2(*g);
    gr2.print();
}