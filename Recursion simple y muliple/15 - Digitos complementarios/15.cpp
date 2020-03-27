// Ana Laura Corral Descargue
// E17


#include <iostream>
#include <iomanip>
#include <fstream>

struct datos{
	int numero;
	int potencia;
};

// función que resuelve el problema
int complementarios (const int n, int potencia) {

	if (n < 10) return { (9 - n) * potencia };

	else {
		int c = 9 - (n % 10);
		return complementarios(n / 10, potencia * 10) + c * potencia;
	}

}


int invertir(const int n, int pot) {

	if (pot == 0 && n < 10) return 9 - n;
	else if (n == 0) return pot;
	else return invertir(n / 10, pot * 10 + (9 - (n % 10)));
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	
	int numero;
	std::cin >> numero;
	
	int comple = complementarios(numero,1);
	int inver = invertir(numero, 0);	
	std::cout << comple << " " << inver << "\n";


}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}