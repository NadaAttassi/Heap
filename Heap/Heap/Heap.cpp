#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>  
#include "Minheap.h"
int main() {
    using namespace std::chrono; 

    // Exemple 1 : mini exempel
    Minheap heap;
    std::vector<int> values = { 10, 7, 11, 1, 5, 4, 16, 6 };
    std::cout << "Exemple 1: Tas min avec quelques valeurs fixes (Affichage vertical)" << std::endl;

    // Chronométrage pour l'Exemple 1
    auto start1 = high_resolution_clock::now();
    for (int value : values) {
        heap.insert(value);
    }
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);

    heap.printTreeVertical();
    std::cout << "Min après insertion: " << heap.getMin() << std::endl;

    heap.removeMin();
    std::cout << "Après avoir retiré l'élément minimum:" << std::endl;
    heap.printTreeVertical();
    std::cout << "Min après suppression: " << heap.getMin() << std::endl;

    std::cout << "\nTemps d'exécution de l'Exemple 1 : " << duration1.count() << " microsecondes." << std::endl;

    // Exemple 2 : 10000 valeurs
    Minheap heap2;
    std::cout << "\nExemple 2: Tas min avec des valeurs aléatoires entre 1 et 10000 (Affichage horizontal)" << std::endl;

    // Chronométrage pour l'Exemple 2
    auto start2 = high_resolution_clock::now();
    for (int i = 1; i <= 10000; ++i) {  // Insérer des valeurs aléatoires
        heap2.insert(i);
    }
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);

    heap2.printTreeHorizontal();
    std::cout << "Min apres insertion: " << heap2.getMin() << std::endl;

    heap2.removeMin();
    std::cout << "Apres avoir retire l'element minimum:" << std::endl;
    heap2.printTreeHorizontal();
    std::cout << "Min apres suppression: " << heap2.getMin() << std::endl;

    std::cout << "\nTemps d'execution de l'Exemple 2 : " << duration2.count() << " microsecondes." << std::endl;

    return 0;
}
