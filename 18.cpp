//Ana Laura Corral
//E17

#include <iostream>
#include <fstream>
#include <vector>

/*
//T(n) = { 
//			c					ini==fin
//			T(n/2) + c			resto de casos
//		}
*/

//El coste para este ejercicio en el caso peor es: O(log n)

struct tSol {
	bool esCruce;
	int ini;
	int fin;
};

tSol resolver(int const& ini, int const& fin, std::vector<int> const& v1, std::vector<int> const& v2) {

	if (ini == fin) {
		if (v1[ini] == v2[fin]) return { true,ini};
		else {
			if(v1[ini]>v2[ini])return { false,ini-1,ini };
			else return { false, ini,ini+1 };
		}
	}
	else {
		int m = (ini + fin) / 2;

		if (v1[m] < v2[m]) return resolver(m + 1, fin, v1, v2);
		else return resolver(ini, m, v1, v2);
	}
}

bool resuelveCaso()
{
	int numElem;
	std::cin >> numElem;
	if (numElem == 0) return false;
	std::vector<int> v1(numElem);
	std::vector<int> v2(numElem);
	for (int& i : v1) std::cin >> i;
	for (int& i : v2) std::cin >> i;

	// Aqui codigo del alumno
	tSol sol = resolver(0, numElem - 1, v1, v2);

	if (sol.esCruce)std::cout << "SI " << sol.ini << " \n";
	else std::cout << "NO " << sol.ini << " " << sol.fin << "\n";
	return true;

}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

	while (resuelveCaso())
		;

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}