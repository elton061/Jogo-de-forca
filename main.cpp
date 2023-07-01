#include <iostream>
#include <string>

using namespace std;

int main()
{
    string palavra, chute, resp;
    int tamanho, i, k, chances = 3;
    char letra;
    bool acertou = false;

    cout << "Digite a palavra desconhecida para o outro jogador: ";
    getline(cin, palavra);
    system("cls"); // limpa a tela para iniciar o jogo.

    tamanho = palavra.size();

    char tentativa[tamanho+1];

    tentativa[tamanho] = '\0'; // adiciona um caractere nulo no final do vetor para realizar a leitura corretamente

    for(i = 0; i < tamanho; i++) // para esconder a palavra para o jogador 2.
       tentativa[i] = '-';

    for(i = 0; chances != 0; i++)
    {
       cout << "\nChances = " << chances;
       cout << "\nDigite uma letra: ";
       cin >> letra;

       for(int k = 0; k < tamanho; k++)
       {
          if(palavra[k] == letra)
          {
             acertou = true;
             tentativa[k] = letra;
          }
       }

       cout << tentativa << endl;

       if (tentativa == palavra)
       {
          cout << "\nParabens voce ganhou :)" << endl;
          return 0;
       }

       if(acertou == true)
       {
          chances++;
          cout << "\n\nquer chutar qual e a palavra? [s/n]" << endl;
          cin >> resp;

          if(resp == "s" || resp == "S" || resp == "sim" || resp == "SIM" || resp == "Sim")
          {
              cout << "\n\nDigite a palavra: ";
              cin >> chute;

              if(chute == palavra)
              {
                 cout << "\n Parabens voce ganhou :) " << endl;
                 return 0;
              }
              else
              {
                 cout << "\nVoce perdeu :( " << endl;
                 return 0;
              }
          }
       }
       acertou = false;
       chances--;
    }

    if(chances == 0)
       cout << "\nSuas chances acabaram :(" << endl << "Obrigado por jogar <3" << endl;

    return 0;
}
