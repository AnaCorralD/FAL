// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


/*
predicate todoLLano (a: array<int>, i : int)
requires a.Length > 0 && i = 1
ensures todoLLano (a,i) == a[i-1] == a[i] || a[i - 1] + 1 == a[i] || a[i - 1] - 1 == a[i]

function resolver (a: array<int>, L: int) : array<int>
requires a.Length > 0
ensures #cont = todoLLano(a,i) && cont >= L && pos[i] = todoLLano(a,i)


invariant = {
	PT k : 0<= k < i
	#cont = todoLLano(a,k)
	pos[k] = todoLLano(a,k)
}
decreases = a.Length - i

Coste: O(n)
Se van a dar dim vueltas
while (i < dim){
	if (...) -> constante
		cont++ -> constante
	else
		if (...) -> constante
			pos.push_back() -> constante
		cont = 1 constante
}
if (...) -> constante
		cont++ -> constante

Por tanto O(n)
*/

std::vector<int> resolver(std::vector<int> const &numeros, int const &L) {

	int i = 1;
	int cont = 1;
	std::vector<int> pos;
	while (i < numeros.size()) {
		if (numeros[i-1] == numeros[i] || numeros[i - 1] + 1 == numeros[i] || numeros[i - 1] - 1 == numeros[i])
			cont++;
		else {
			if (cont >= L) {
				pos.push_back(i - cont);
			}
			cont = 1;
		}
		i++;
	}

	if (cont >= L) {
		pos.push_back(i - cont);
	}

	return pos;


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int dim, L;
	std::cin >> dim >> L;

	if (dim == 0 && L==0)
		return false;

	std::vector<int> numeros(dim);
	for (int i = 0; i < dim; i++)
		std::cin>>numeros[i];

	std::vector<int>  sol = resolver(numeros, L);

	std::cout << sol.size();
	for (int i = 0; i < sol.size(); i++)
		std::cout << " " << sol[i];
	std::cout << "\n";

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}