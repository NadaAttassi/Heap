#include "MinHeap.h"

// Fonction pour échanger deux éléments dans le tas
void Minheap::swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

// Fonction pour réorganiser le tas vers le haut (heapifyUp)
void Minheap::heapifyUp(int index) {
    int parent = (index - 1) / 2; // Calcul de l'indice du parent
    if (index > 0 && heap[index] < heap[parent]) {
        swap(index, parent);        // On échange l'élément avec son parent
        heapifyUp(parent);          // On continue à vérifier l'ordre en remontant
    }
}

// Fonction pour réorganiser le tas vers le bas (heapifyDown)
void Minheap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;  // Calcul de l'indice du fils gauche
    int rightChild = 2 * index + 2; // Calcul de l'indice du fils droit
    int smallest = index;

    // On cherche le plus petit enfant
    if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
        smallest = rightChild;
    }

    // Si l'élément courant n'est pas le plus petit, on échange et on poursuit
    if (smallest != index) {
        swap(index, smallest);
        heapifyDown(smallest);  // On continue à réorganiser vers le bas
    }
}

// Fonction pour insérer une valeur dans le tas
void Minheap::insert(int value) {
    heap.push_back(value);       // On ajoute la valeur à la fin du tas
    heapifyUp(heap.size() - 1);  // On réorganise le tas en remontant l'élément
}

// Fonction pour retirer le minimum du tas (racine)
void Minheap::removeMin() {
    if (heap.empty()) return;  // Si le tas est vide, on ne fait rien
    heap[0] = heap.back();     // On remplace la racine par le dernier élément
    heap.pop_back();           // On retire le dernier élément
    heapifyDown(0);            // On réorganise le tas en descendant l'élément
}

// Fonction pour afficher le tas sous forme d'arbre vertical
void Minheap::printTreeVertical() const {
    if (heap.empty()) {
        std::cout << "Le tas est vide !" << std::endl;
        return;
    }

    int maxLevel = static_cast<int>(std::log2(heap.size())); // Niveau maximum de l'arbre
    for (int level = 0; level <= maxLevel; ++level) {
        printNodesAtLevel(level, maxLevel);  // Affichage des nœuds à un niveau donné
        if (level < maxLevel) {
            printBranchesBetweenLevels(level, maxLevel);  // Affichage des branches
        }
    }
}

// Fonction pour afficher le tas sous forme horizontale
void Minheap::printTreeHorizontal() const {
    if (heap.empty()) {
        std::cout << "Le tas est vide !" << std::endl;
        return;
    }

    int maxLevel = static_cast<int>(std::log2(heap.size())); // Niveau maximum de l'arbre
    for (int level = 0; level <= maxLevel; ++level) {
        printNodesAtLevelHorizontal(level, maxLevel);  // Affichage des nœuds horizontalement
    }
}

// Fonction pour obtenir la valeur minimale (racine)
int Minheap::getMin() const {
    if (heap.empty()) return -1;  // Retourner -1 si le tas est vide
    return heap[0];                // Retourner la valeur minimale (racine)
}

// Fonction pour calculer l'espacement entre les éléments
int Minheap::calculateSpacing(int level, int maxLevel) const {
    return (1 << (maxLevel - level + 1)) - 1;  // Calcul de l'espacement en fonction du niveau
}

// Fonction pour afficher les nœuds à un niveau donné (format vertical)
void Minheap::printNodesAtLevel(int level, int maxLevel) const {
    int startIndex = (1 << level) - 1;   // Calcul de l'indice du premier élément à ce niveau
    int endIndex = std::min(static_cast<int>(heap.size()), (1 << (level + 1)) - 1); // Dernier élément à ce niveau
    int spacing = calculateSpacing(level, maxLevel);  // Espacement entre les nœuds

    std::cout << std::string(spacing, ' ');  // Espacement avant le premier nœud

    for (int i = startIndex; i < endIndex; ++i) {
        std::cout << heap[i];   // Affichage de la valeur du nœud
        if (i < endIndex - 1) {
            std::cout << std::string(2 * spacing + 1, ' ');  // Espacement entre les nœuds
        }
    }
    std::cout << std::endl;
}

// Fonction pour afficher les branches entre les niveaux (version verticale)
void Minheap::printBranchesBetweenLevels(int level, int maxLevel) const {
    int numNodes = (1 << level); // Nombre de nœuds à ce niveau
    int spacing = calculateSpacing(level, maxLevel);  // Espacement entre les niveaux
    int branchSpacing = calculateSpacing(level + 1, maxLevel);  // Espacement entre les branches

    for (int i = 1; i <= branchSpacing; ++i) {
        std::cout << std::string(spacing - i, ' ');  // Espacement avant la branche

        for (int j = 0; j < numNodes; ++j) {
            std::cout << "/ ";
            std::cout << std::string(2 * i - 1, ' ');  // Espacement entre les branches
            std::cout << "\\";

            if (j < numNodes - 1) {
                std::cout << std::string(2 * (spacing - i) + 1, ' ');  // Espace entre les branches
            }
        }
        std::cout << std::endl;
    }
}

// Fonction pour afficher les nœuds à un niveau donné (version horizontale)
void Minheap::printNodesAtLevelHorizontal(int level, int maxLevel) const {
    int startIndex = (1 << level) - 1;  // Calcul de l'indice du premier élément à ce niveau
    int endIndex = std::min(static_cast<int>(heap.size()), (1 << (level + 1)) - 1);  // Dernier élément à ce niveau

    for (int i = startIndex; i < endIndex; ++i) {
        std::cout << heap[i] << " ";  // Affichage de la valeur du nœud
    }
    std::cout << std::endl;
}
