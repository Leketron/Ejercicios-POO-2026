#include <iostream>
#include <vector>
using namespace std;

class Satelite {
public:
    Satelite(int id, float masa) : id(id), masa(masa) {
        for (int i = 0; i < 1000; i++)
            datos[i] = id % 256;
    }
    int getId() const { return id; }
    float getMasa() const { return masa; }
private:
    int id;
    float masa;
    char datos[1000]; // ~1KB por objeto
};

int main() {
    vector<Satelite> satelites;
    const long long LIMITE_BYTES = 200LL * 1024 * 1024; // 200 MB

    long long contador = 0;
    while (true) {
        long long memActual = satelites.size() * sizeof(Satelite);
        if (memActual >= LIMITE_BYTES)
            break;
        satelites.push_back(Satelite(contador, contador * 1.5f));
        contador++;
    }

    cout << "Objetos agregados antes de alcanzar 200 MB: " << contador << endl;
    cout << "Memoria aproximada usada: "
         << (satelites.size() * sizeof(Satelite)) / (1024 * 1024)
         << " MB" << endl;

    return 0;
}
