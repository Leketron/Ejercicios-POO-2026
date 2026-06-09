#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    vector<string> expresiones;
    expresiones.push_back("pan comido");
    expresiones.push_back("lluvia de ideas");
    expresiones.push_back("dar en el clavo");
    expresiones.push_back("a mal tiempo buena cara");
    expresiones.push_back("no hay mal que por bien no venga");

    sort(expresiones.begin(), expresiones.end(), [](const string& a, const string& b) {
        string sa = a, sb = b;
        sa.erase(remove(sa.begin(), sa.end(), ' '), sa.end());
        sb.erase(remove(sb.begin(), sb.end(), ' '), sb.end());
        return sa < sb;
    });

    cout << "--- Expresiones ordenadas alfabeticamente (sin espacios) ---" << endl;
    for (const string& e : expresiones)
        cout << e << endl;

    return 0;
}
