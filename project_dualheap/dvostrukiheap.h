#ifndef DVOSTRUKIHEAP_H
#define DVOSTRUKIHEAP_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename Tip>
class DHeap{
    vector<Tip> niz;
    int LijevoDijete(int indeks){return 2*indeks+1;}
    int DesnoDijete(int indeks){return 2*indeks + 2;}
    int RoditeljRoditelja(int indeks){return Roditelj(Roditelj(indeks));}
    int Roditelj(int indeks){return (indeks-1) / 2;}
    void UpDHeap(int indeks);
    void DownDHeap(int indeks);
    void MakeDHeap(){for(int i = Roditelj(niz.size() - 1); i >= 0; i--) DownDHeap(i);}
    int Dubina(int indeks){return floor(log2(indeks + 1));}
public:
    DHeap(vector<Tip> v){niz = v; MakeDHeap();}
    void Push(Tip element);
    Tip DHeapmaks();//fja za max
    Tip DHeapmin();//fja za min
    void Ispisi();
    void Izbrisimin();
    void Izbrisimaks();
};

#include "dvostrukiheap.cpp"

#endif // DVOSTRUKIHEAP_H
