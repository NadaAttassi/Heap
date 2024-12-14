#pragma once
#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>

class Minheap {
private:
    std::vector<int> heap;  // Vecteur pour stocker les �l�ments du tas

    // Fonction pour �changer deux �l�ments
    void swap(int i, int j);

    // Fonction pour r�organiser l'�l�ment vers le haut dans le tas (heapifyUp)
    void heapifyUp(int index);

    // Fonction pour r�organiser l'�l�ment vers le bas dans le tas (heapifyDown)
    void heapifyDown(int index);

public:
    // Fonction pour ins�rer une valeur dans le tas min
    void insert(int value);

    // Fonction pour retirer l'�l�ment minimum (racine du tas)
    void removeMin();

    // Fonction pour afficher le tas sous forme d'arbre vertical
    void printTreeVertical() const;

    // Fonction pour afficher le tas avec des branches horizontales
    void printTreeHorizontal() const;

    // Fonction pour obtenir la valeur minimale (racine)
    int getMin() const;

private:
    // Fonction pour calculer l'espacement entre les �l�ments dans l'arbre
    int calculateSpacing(int level, int maxLevel) const;

    // Fonction pour afficher les n�uds � un niveau donn� (format vertical)
    void printNodesAtLevel(int level, int maxLevel) const;

    // Fonction pour afficher les branches entre les niveaux (version verticale)
    void printBranchesBetweenLevels(int level, int maxLevel) const;

    // Fonction pour afficher les n�uds � un niveau donn� (version horizontale)
    void printNodesAtLevelHorizontal(int level, int maxLevel) const;
};
