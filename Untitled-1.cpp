#include <iostream>
#include <vector>
#include <fstream> 
#include <cstdlib> 
#include <string> 

using namespace std;
char cache[8] = {};
char memoria[200];
int i,f,acerto,erro =0;

int main(){
    ifstream arquivo;
    string linha;
    arquivo.open("ValoresInt.txt");
    if (arquivo.is_open()){
        while (getline(arquivo,linha))// leitura do arquivo por linha
        {
            memoria[i] = stoi(linha);//cast string para int
            i++;
            f++;//limitador de arquivos de memoria (para maior que 200 mudar linha 9)
        }
    }else{
        cout << "Não foi possivel abrir o arquivo"<< endl;// mensagem se arquivo não abrir
    }
    // tratamento de dados
    for ( i = 0; i < f; i++){
        if (cache[memoria[i]%8] == (memoria[i])){
            cout << cache[i]; 
            acerto ++;
        }
        else{
            cache[memoria[i]%8] = (memoria[i]);
            erro++;
        }
    }
    cout << "teste erro " << erro << endl;
    cout << "teste acerto " << acerto << endl;
    cout << "teste total " << f << endl;
    cout << "Porcentagem de acerto = " << float(acerto*100/f)<< "%" << endl;
    cout << "Porcentagem de erro = " << float(erro*100/f)<< "%" << endl;

    cout << "Colunas de memorias utilizadas: " << endl;

    for ( i = 0; i < f; i++)
    {
       cout << float(cache[i]) << " "; 
    }   
    return 0;
}