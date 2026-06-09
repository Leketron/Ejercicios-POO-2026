#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Poste {
public:
    Poste(int altura, float diametro) : altura(altura), diametro(diametro) {}
    int getAltura() const { return altura; }
    float getDiametro() const { return diametro; }
    void mostrar() const {
        cout << "Altura: " << altura << "m | Diametro: " << diametro << "cm" << endl;
    }
private:
    int altura;
    float diametro;
};

int main() {
    vector<Poste> postes;
    postes.push_back(Poste(10, 15.5));
    postes.push_back(Poste(4,  8.0));
    postes.push_back(Poste(7,  12.3));
    postes.push_back(Poste(2,  5.5));
    postes.push_back(Poste(15, 20.0));

    cout << "--- Antes de ordenar ---" << endl;
    for (const Poste& p : postes)
        p.mostrar();

    sort(postes.begin(), postes.end(), [](const Poste& a, const Poste& b) {
        return a.getAltura() < b.getAltura();
    });

    cout << "\n--- Despues de ordenar ---" << endl;
    for (const Poste& p : postes)
        p.mostrar();

    return 0;
}
