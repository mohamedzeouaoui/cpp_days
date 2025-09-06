#include <iostream>
#include <vector>
#include <algorithm> // std::lower_bound

// Génère la suite de Jacobsthal
std::vector<size_t> generateJacobsthal(size_t n) {
    std::vector<size_t> seq;
    size_t j0 = 0, j1 = 1;
    seq.push_back(j1);
    while (j1 < n) {
        size_t j2 = j1 + 2 * j0;
        seq.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    return seq;
}

// Étape MERGE : créer et trier des blocs de taille `order`
std::vector<int> mergePhase(const std::vector<int> &arr, size_t order) {
    std::vector<std::vector<int> > blocks;

    // Créer les blocs
    for (size_t i = 0; i < arr.size(); i += order) {
        std::vector<int> block;
        size_t j = i;
        while (j < i + order && j < arr.size())
		{
			block.push_back(arr[j]);
			++j;
		}
        blocks.push_back(block);
    }

    // Trier les blocs deux par deux par rapport au dernier élément
    for (size_t i = 0; i + 1 < blocks.size(); i += 2) {
        if (blocks[i].back() > blocks[i + 1].back())
            std::swap(blocks[i], blocks[i + 1]);
    }

    // Réassembler
    std::vector<int> merged;
    for (size_t i = 0; i < blocks.size(); ++i) {
        merged.insert(merged.end(), blocks[i].begin(), blocks[i].end());
    }

    return merged;
}

// Séparer en main et pend
void splitMainPend(const std::vector<int> &arr,
                   std::vector<int> &main,
                   std::vector<int> &pend) {
    size_t mid = arr.size() / 2;
    main.insert(main.end(), arr.begin(), arr.begin() + mid);
    pend.insert(pend.end(), arr.begin() + mid, arr.end());
}

// Phase INSERTION : insérer pend dans main
void insertionPhase(std::vector<int> &main, const std::vector<int> &pend) {
    std::vector<size_t> jac = generateJacobsthal(pend.size());

    // Ici on insère simplement (Jacobsthal = optimisation possible)
    for (size_t i = 0; i < pend.size(); ++i) {
        std::vector<int>::iterator pos =
            std::lower_bound(main.begin(), main.end(), pend[i]);
        main.insert(pos, pend[i]);
    }
}

// Fonction principale Ford–Johnson
std::vector<int> fordJohnsonSort(const std::vector<int> &input) {
    if (input.size() <= 1)
        return input;

    std::vector<int> work = input;
    size_t order = 1;

    // Phase MERGE
    while (order * 2 <= work.size()) {
        work = mergePhase(work, order);
        order *= 2;
    }

    // Phase INSERTION
    std::vector<int> main, pend;
    splitMainPend(work, main, pend);
    insertionPhase(main, pend);

    return main;
}

// -------------------------------
// Programme principal
// -------------------------------
int main() {
    std::vector<int> arr;
    for (int i = 25; i >= 0; --i)
        arr.push_back(i);

    std::cout << "Avant tri : ";
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::vector<int> sorted = fordJohnsonSort(arr);

    std::cout << "Après tri : ";
    for (size_t i = 0; i < sorted.size(); ++i)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;

    return 0;
}
