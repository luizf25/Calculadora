#include <iostream>
#include <cmath>     // Para pow e sqrt
#include <limits>    // Para std::numeric_limits

//#define NOMINMAX
#include <Windows.h> // Para SetConsoleOutputCP e SetConsoleCP

// Função para limpar o buffer de entrada em caso de erro
void limparBufferEntrada()
{
    std::cin.clear(); // Limpa os flags de erro
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta a entrada inválida
}

// Função para ler um número do tipo double com tratamento de erro
double lerNumero(const std::string &prompt)
{
    double num;
    while (true)
    {
        std::cout << prompt;
        std::cin >> num;
        if (std::cin.good())
        { // Verifica se a entrada foi bem-sucedida
            return num;
        }
        else
        {
            std::cout << "Entrada inválida. Por favor, insira um número.\n";
            limparBufferEntrada();
        }
    }
}

int main()
{
    // Configura a página de código do console para UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char operacao;
    double num1, num2, resultado;
    bool continuar = true;

    std::cout << "Bem-vindo à Calculadora em C++!\n";

    while (continuar)
    {
        std::cout << "\nEscolha a operação desejada:\n";
        std::cout << "  + : Soma\n";
        std::cout << "  - : Subtração\n";
        std::cout << "  * : Multiplicação\n";
        std::cout << "  / : Divisão\n";
        std::cout << "  ^ : Potência (num1 elevado a num2)\n";
        std::cout << "  r : Raiz Quadrada (do primeiro número)\n";
        std::cout << "  s : Sair\n";
        std::cout << "Operação: ";
        std::cin >> operacao;

        limparBufferEntrada(); // Limpa o buffer após ler o char

        if (operacao == 's' || operacao == 'S')
        {
            continuar = false;
            std::cout << "Obrigado por usar a calculadora. Até logo!\n";
            continue;
        }

        if (operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/' || operacao == '^')
        {
            num1 = lerNumero("Digite o primeiro número: ");
            num2 = lerNumero("Digite o segundo número: ");
        }
        else if (operacao == 'r' || operacao == 'R')
        {
            num1 = lerNumero("Digite o número para calcular a raiz quadrada: ");
        }
        else
        {
            std::cout << "Operação inválida. Tente novamente.\n";
            continue;
        }

        switch (operacao)
        {
        case '+':
            resultado = num1 + num2;
            std::cout << "Resultado: " << num1 << " + " << num2 << " = " << resultado << std::endl;
            break;
        case '-':
            resultado = num1 - num2;
            std::cout << "Resultado: " << num1 << " - " << num2 << " = " << resultado << std::endl;
            break;
        case '*':
            resultado = num1 * num2;
            std::cout << "Resultado: " << num1 << " * " << num2 << " = " << resultado << std::endl;
            break;
        case '/':
            if (num2 != 0)
            {
                resultado = num1 / num2;
                std::cout << "Resultado: " << num1 << " / " << num2 << " = " << resultado << std::endl;
            }
            else
            {
                std::cout << "Erro: Divisão por zero não é permitida.\n";
            }
            break;
        case '^':
            resultado = std::pow(num1, num2);
            std::cout << "Resultado: " << num1 << " ^ " << num2 << " = " << resultado << std::endl;
            break;
        case 'r':
        case 'R':
            if (num1 >= 0)
            {
                resultado = std::sqrt(num1);
                std::cout << "Resultado: Raiz quadrada de " << num1 << " = " << resultado << std::endl;
            }
            else
            {
                std::cout << "Erro: Não é possível calcular a raiz quadrada de um número negativo (no domínio dos reais).\n";
            }
            break;
        default:
            std::cout << "Operação inválida. Tente novamente.\n";
            break;
        }
    }

    return 0;
}