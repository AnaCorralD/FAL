// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>

struct sol{
	int numero;
	int potencia;
};
sol resolver(const int n) {

	if (n < 10) return {n,10};
	else {
		sol s = resolver(n / 10);
		return { s.numero + (n % 10) * s.potencia , s.potencia * 10 };
	}
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {

	int numero;
	std::cin >> numero;

	if (numero == 0)
		return false;

	sol sol = resolver(numero);

	std::cout << sol.numero << "\n";

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