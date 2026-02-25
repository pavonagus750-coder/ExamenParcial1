#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

void escribirEnArchivo(string texto) {
    mtx.lock();  
    
    ofstream archivo("salida.txt", ios::app);
    archivo << texto << endl;
    archivo.close();
    
    mtx.unlock();  
}

int main() {

    thread t1(escribirEnArchivo, "Hola desde el thread 1");
    thread t2(escribirEnArchivo, "Hola desde el thread 2");
    thread t3(escribirEnArchivo, "Hola desde el thread 3");
    thread t4(escribirEnArchivo, "Hola desde el thread 4");
    thread t5(escribirEnArchivo, "Hola desde el thread 5");

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    cout << "Los threads terminaron de escribir." << endl;

    return 0;
}
