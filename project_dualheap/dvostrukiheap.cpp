#ifndef DVOSTRUKIHEAP_CPP
#define DVOSTRUKIHEAP_CPP
#include <iostream>
#include "dvostrukiheap.h"
using namespace std;
/*
DHeap(const DHeap& kopija);
    DHeap& operator=(const DHeap& rhs);
    ~DHeap(){while(!niz.empty()) niz.pop_back();}
    DHeap(DHeap&& kopija);
    DHeap& operator=(DHeap&& rhs);

*/
template<typename Tip>
void DHeap<Tip>::UpDHeap(int indeks){

    if(Dubina(indeks) % 2 == 0){//parna dubina
        if(niz[indeks] < niz[Roditelj(indeks)] && niz[indeks] > niz[RoditeljRoditelja(indeks)]){
            return;//ovdje je on na dobrom mjestu za parne brojeve
        }
        if(niz[indeks] > niz[RoditeljRoditelja(indeks)] && niz[indeks] > niz[Roditelj(indeks)]){
            swap(niz[indeks], niz[Roditelj(indeks)]);
            UpDHeap(Roditelj(indeks));
        }
        if(niz[indeks] < niz[Roditelj(indeks)] && niz[indeks] < niz[RoditeljRoditelja(indeks)]){
            swap(niz[indeks], niz[RoditeljRoditelja(indeks)]);
            UpDHeap(RoditeljRoditelja(indeks));
        }
        if(niz[indeks] > niz[Roditelj(indeks)] && niz[indeks] < niz[RoditeljRoditelja(indeks)]){
            swap(niz[indeks], niz[Roditelj(indeks)]);
            UpDHeap(Roditelj(indeks));
        }
    }
    else{//neparna dubina
        if(niz[indeks] > niz[Roditelj(indeks)] && niz[indeks] < niz[RoditeljRoditelja(indeks)])
            return; //dobro mjesto
        if(niz[indeks] > niz[Roditelj(indeks)] && niz[indeks] > niz[RoditeljRoditelja(indeks)]){
            swap(niz[indeks], niz[RoditeljRoditelja(indeks)]);
            UpDHeap(RoditeljRoditelja(indeks));
        }
        if(niz[indeks] < niz[Roditelj(indeks)] && niz[indeks] < niz[RoditeljRoditelja(indeks)]){
            swap(niz[indeks], niz[Roditelj(indeks)]);
            UpDHeap(Roditelj(indeks));
        }
        if(niz[indeks] < niz[Roditelj(indeks)] && niz[indeks] > niz[Roditelj(indeks)]){
            swap(niz[indeks], niz[RoditeljRoditelja(indeks)]);
            UpDHeap(RoditeljRoditelja(indeks));
        }
    }
}

template <typename Tip>
void DHeap<Tip>::DownDHeap(int indeks){
    if(Dubina(indeks) % 2 == 0){// parna dubina
        if(LijevoDijete(indeks) < niz.size()){//ima lijevož
            if(DesnoDijete(indeks) < niz.size()){//ima i desno, to nam treba jer samo tad moze imati nesto na sljedecoj parnoj dubini
                        if(niz[indeks] > min(niz[LijevoDijete(indeks)], niz[DesnoDijete(indeks)])){
                            if(niz[LijevoDijete(indeks)] < niz[DesnoDijete(indeks)]){
                                swap(niz[indeks], niz[LijevoDijete(indeks)]);
                                DownDHeap(indeks);//!!!!!
                            }
                            else{
                                swap(niz[indeks], niz[DesnoDijete(indeks)]);
                                DownDHeap(indeks);//!!!!
                                }
                        }
                if(LijevoDijete(LijevoDijete(indeks)) < niz.size()){//lijevo dijete ima lijevo dijete
                    if(LijevoDijete(DesnoDijete(indeks)) < niz.size()){//lijevo dijete ima desno
                        if(DesnoDijete(LijevoDijete(indeks)) < niz.size()){//desno dijete ima lijevo dijete
                            if(DesnoDijete(DesnoDijete(indeks)) < niz.size()){//sva djeca ima djecu
                                if(niz[LijevoDijete(LijevoDijete(indeks))] < min(min(niz[LijevoDijete(DesnoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]), min(niz[DesnoDijete(DesnoDijete(indeks))],niz[indeks]))){
                                    swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                                    DownDHeap(LijevoDijete(LijevoDijete(indeks)));
                                }
                                if(niz[LijevoDijete(DesnoDijete(indeks))] < min(min(niz[LijevoDijete(LijevoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]), min(niz[DesnoDijete(DesnoDijete(indeks))],niz[indeks]))){
                                    swap(niz[indeks], niz[LijevoDijete(DesnoDijete(indeks))]);
                                    DownDHeap(LijevoDijete(DesnoDijete(indeks)));
                                }
                                if(niz[DesnoDijete(LijevoDijete(indeks))] < min(min(niz[LijevoDijete(LijevoDijete(indeks))], niz[LijevoDijete(DesnoDijete(indeks))]), min(niz[DesnoDijete(DesnoDijete(indeks))],niz[indeks]))){
                                    swap(niz[indeks], niz[DesnoDijete(LijevoDijete(indeks))]);
                                    DownDHeap(DesnoDijete(LijevoDijete(indeks)));
                                }
                                if(niz[DesnoDijete(DesnoDijete(indeks))] < min(min(niz[LijevoDijete(LijevoDijete(indeks))], niz[LijevoDijete(DesnoDijete(indeks))]), min(niz[DesnoDijete(LijevoDijete(indeks))],niz[indeks]))){
                                    swap(niz[indeks], niz[DesnoDijete(DesnoDijete(indeks))]);
                                    DownDHeap(DesnoDijete(DesnoDijete(indeks)));
                                }
                            }
                            //slucaj kad desno dijete nema desno:
                            if(niz[LijevoDijete(LijevoDijete(indeks))] < min(min(niz[LijevoDijete(DesnoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]),niz[indeks])){
                                swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                            }
                            if(niz[LijevoDijete(DesnoDijete(indeks))] < min(min(niz[LijevoDijete(LijevoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]),niz[indeks])){
                                swap(niz[indeks], niz[LijevoDijete(DesnoDijete(indeks))]);
                            }
                            if(niz[DesnoDijete(LijevoDijete(indeks))] < min(min(niz[LijevoDijete(LijevoDijete(indeks))], niz[LijevoDijete(DesnoDijete(indeks))]),niz[indeks])){
                                swap(niz[indeks], niz[DesnoDijete(LijevoDijete(indeks))]);
                            }
                    }
                    //desno dijete nema djecu
                        if(niz[LijevoDijete(LijevoDijete(indeks))] < min(niz[LijevoDijete(DesnoDijete(indeks))],niz[indeks])){
                            swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                            }
                        if(niz[LijevoDijete(DesnoDijete(indeks))] < min(niz[LijevoDijete(LijevoDijete(indeks))],niz[indeks])){
                            swap(niz[indeks], niz[LijevoDijete(DesnoDijete(indeks))]);
                        }
                    }
                    //lijevo dijete ima samo lijevo
                    if(niz[LijevoDijete(LijevoDijete(indeks))] < niz[indeks]){
                            swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                        }
                }
            }
        //ima samo lijevo
        if(niz[LijevoDijete(indeks)] < niz[indeks]){
            swap(niz[indeks], niz[LijevoDijete(indeks)]);
            }
        }
    }
    else{//neparna dubina
        if(LijevoDijete(indeks) < niz.size()){//ima lijevo
        if(DesnoDijete(indeks) < niz.size()){//ima i desno, to nam treba jer samo tad moze imati nesto na sljedecoj neparnoj dubini
                if(niz[indeks] < max(niz[LijevoDijete(indeks)], niz[DesnoDijete(indeks)])){
                    if(niz[LijevoDijete(indeks)] > niz[DesnoDijete(indeks)]){
                        swap(niz[indeks], niz[LijevoDijete(indeks)]);
                        DownDHeap(LijevoDijete(indeks));
                    }
                    else{
                        swap(niz[indeks], niz[DesnoDijete(indeks)]);
                        DownDHeap(DesnoDijete(indeks));
                        }
                }
            if(LijevoDijete(LijevoDijete(indeks)) < niz.size()){//lijevo dijete ima lijevo dijete
                if(LijevoDijete(DesnoDijete(indeks)) < niz.size()){//lijevo dijete ima desno
                    if(DesnoDijete(LijevoDijete(indeks)) < niz.size()){//desno dijete ima lijevo dijete
                        if(DesnoDijete(DesnoDijete(indeks)) < niz.size()){//sva djeca ima djecu
                            if(niz[LijevoDijete(LijevoDijete(indeks))] > max(max(niz[LijevoDijete(DesnoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]), max(niz[DesnoDijete(DesnoDijete(indeks))],niz[indeks]))){
                                swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                                DownDHeap(LijevoDijete(LijevoDijete(indeks)));
                            }
                            if(niz[LijevoDijete(DesnoDijete(indeks))] > max(max(niz[LijevoDijete(LijevoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]), max(niz[DesnoDijete(DesnoDijete(indeks))],niz[indeks]))){
                                swap(niz[indeks], niz[LijevoDijete(DesnoDijete(indeks))]);
                                DownDHeap(LijevoDijete(DesnoDijete(indeks)));
                            }
                            if(niz[DesnoDijete(LijevoDijete(indeks))] > max(max(niz[LijevoDijete(LijevoDijete(indeks))], niz[LijevoDijete(DesnoDijete(indeks))]), max(niz[DesnoDijete(DesnoDijete(indeks))],niz[indeks]))){
                                swap(niz[indeks], niz[DesnoDijete(LijevoDijete(indeks))]);
                                DownDHeap(DesnoDijete(LijevoDijete(indeks)));
                            }
                            if(niz[DesnoDijete(DesnoDijete(indeks))] > max(max(niz[LijevoDijete(LijevoDijete(indeks))], niz[LijevoDijete(DesnoDijete(indeks))]), max(niz[DesnoDijete(LijevoDijete(indeks))],niz[indeks]))){
                                swap(niz[indeks], niz[DesnoDijete(DesnoDijete(indeks))]);
                                DownDHeap(DesnoDijete(DesnoDijete(indeks)));
                            }
                        }
                        //slucaj kad desno dijete nema desno:
                        if(niz[LijevoDijete(LijevoDijete(indeks))] > max(max(niz[LijevoDijete(DesnoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]),niz[indeks])){
                            swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                        }
                        if(niz[LijevoDijete(DesnoDijete(indeks))] > max(max(niz[LijevoDijete(LijevoDijete(indeks))], niz[DesnoDijete(LijevoDijete(indeks))]),niz[indeks])){
                            swap(niz[indeks], niz[LijevoDijete(DesnoDijete(indeks))]);
                        }
                        if(niz[DesnoDijete(LijevoDijete(indeks))] > max(max(niz[LijevoDijete(LijevoDijete(indeks))], niz[LijevoDijete(DesnoDijete(indeks))]),niz[indeks])){
                            swap(niz[indeks], niz[DesnoDijete(LijevoDijete(indeks))]);
                        }
                    }
                //desno dijete nema djecu
                    if(niz[LijevoDijete(LijevoDijete(indeks))] > max(niz[LijevoDijete(DesnoDijete(indeks))],niz[indeks])){
                        swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                        }
                    if(niz[LijevoDijete(DesnoDijete(indeks))] > max(niz[LijevoDijete(LijevoDijete(indeks))],niz[indeks])){
                        swap(niz[indeks], niz[LijevoDijete(DesnoDijete(indeks))]);
                    }
                }
                //lijevo dijete ima samo lijevo
                if(niz[LijevoDijete(LijevoDijete(indeks))] > niz[indeks]){
                    swap(niz[indeks], niz[LijevoDijete(LijevoDijete(indeks))]);
                    }
            }
        }
    //ima samo lijevo
    if(niz[LijevoDijete(indeks)] > niz[indeks]){
        swap(niz[indeks], niz[LijevoDijete(indeks)]);
        }
    }
    }
}

template<typename Tip>
void DHeap<Tip>::Push(Tip element){
    niz.push_back(element);
    UpDHeap(niz.size() - 1);
}

template<typename Tip>
Tip DHeap<Tip>::DHeapmaks(){
    return max(niz[1], niz[2]);
}

template<typename Tip>
Tip DHeap<Tip>::DHeapmin(){
    return niz[0];
}

template <typename Tip>
void DHeap<Tip>::Izbrisimin(){
    swap(niz[0], niz[niz.size() - 1]);
    niz.pop_back();
    DownDHeap(0);
}

template <typename Tip>
void DHeap<Tip>::Izbrisimaks(){
    int indeks_maksimalnog;
    int indeks_drugog;
    if(niz[1] > niz[2]){
        indeks_maksimalnog = 1;
        indeks_drugog = 2;
    }
    else{
        indeks_maksimalnog = 2;
        indeks_drugog = 1;
    }
    swap(niz[indeks_maksimalnog], niz[niz.size() - 1]);
    niz.pop_back();
    DownDHeap(indeks_maksimalnog);
}


template <typename Tip>
void DHeap<Tip>::Ispisi(){
    int broj_praznih_mjesta_prije_ispisa = niz.size() / 2;
    int brojac = 0;
    int za_novi_red = 1;
    for(int i = 0; i < niz.size(); i++){
        cout << niz[i] << "   ";
        brojac++;
        if(za_novi_red == brojac){
            za_novi_red *= 2;
            brojac = 0;
            cout << endl;
        }
    }
}

#endif // DVOSTRUKIHEAP_CPP
