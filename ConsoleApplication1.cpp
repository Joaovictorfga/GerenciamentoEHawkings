#include <iostream>
#include <list>
using namespace std;


class Membro {

private:
	string nome;
	string curso;
	bool isEfetivado;

public:
	Membro(string nome, string curso) { //CONSTRUTOR
		this->nome = nome;
		this->curso = curso;
		this->isEfetivado = false;
	}

	void efetivar() {
		if (!this->isEfetivado) {
			this->isEfetivado = true;
			cout << "Membro Efetivado\n";
		}
		else {
			cout << "Membro já é efetivo\n";
		}

	}

	string pegar_nome() {
		return nome;
	}

};

class NucleoDeEstudos {

private:
	string nome = "Equipe Hawkings";
	list<Membro> lista_de_membros;
	
public:
	void adicionar_membro(Membro m) {
		lista_de_membros.push_front(m);
	}

	void ver_membros() {
		if (!lista_de_membros.empty()) {
			for (list<Membro>::iterator it = lista_de_membros.begin(); it != lista_de_membros.end(); it++) {
				cout << it->pegar_nome() << endl;
			}
		}
		else {
			cout << "Nao ha membros cadastrados\n";
		}
	}

	void efetivar_membro(string nome) {
		bool membro_existe = false;
		if (!lista_de_membros.empty()) {
			for (list<Membro>::iterator it = lista_de_membros.begin(); it != lista_de_membros.end(); it++) {
				if (it->pegar_nome() == nome) {
					it->efetivar();
					membro_existe = true;
				}
			}
		}
		else {
			cout << "Nao ha membros cadastrados\n";
		}
		if (!membro_existe) {
			cout << "Membro nao existe\n";
		}
	}
};


int main()
{
	NucleoDeEstudos* hawkings = new NucleoDeEstudos();

	string option;
	bool apertou_sair = false;
	cout << "Bem vindo ao sistema de gestao da Equipe Hawkings! Selecione uma opcao:\n";

	while (!apertou_sair) {
		cout << "----------------------------------" << endl;
		cout << "1. Adicionar novo membro\n";
		cout << "2. Ver todos os membros\n";
		cout << "3. Efetivar membro\n";
		cout << "4. Sair\n";
		cin >> option;

		if (option == "1") {
			string nome;
			cout << "Nome do membro: ";
			cin >> nome;
			string curso;
			cout << "Nome do curso: ";
			cin >> curso;
			Membro* m = new Membro(nome, curso);
			hawkings->adicionar_membro(*m);
		}

		if (option == "2") {
			hawkings->ver_membros();
		}

		if (option == "3") {
			cout << "Digite o nome do membro a ser efetivado: ";
			string nome;
			cin >> nome;
			hawkings->efetivar_membro(nome);
		}

		if (option == "4") {
			apertou_sair = true;
		}
	}
}



























