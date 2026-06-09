#ifndef ENCODER_H  // Define para evitar inclusão múltipla do arquivo de cabeçalho encoder.h. Esse mecanismo é usado para garantir que o conteúdo do arquivo seja incluído apenas uma vez durante a compilação, evitando erros de redefinição de tipos, funções ou variáveis. O uso de #ifndef, #define e #endif é uma prática comum em C e C++ para proteger os arquivos de cabeçalho contra inclusões múltiplas, garantindo que o código seja compilado corretamente mesmo que o arquivo seja incluído em vários lugares do projeto.
#define ENCODER_H  // Define para evitar inclusão múltipla do arquivo de cabeçalho encoder.h

#ifdef __cplusplus // Permite que o código seja compilado tanto em C quanto em C++
extern "C" { // Início do bloco de código C
#endif

#include <stdint.h> // Biblioteca padrão do C para tipos de dados inteiros com tamanhos específicos, como int16_t e uint32_t, que são usados para garantir a portabilidade do código em diferentes plataformas e arquiteturas de microcontroladores.

typedef enum // Enumeração para representar os eventos do encoder rotativo. Essa enumeração define os possíveis eventos que podem ocorrer ao interagir com o encoder, como rotação no sentido horário (ENC_CW), rotação no sentido anti-horário (ENC_CCW) e pressão do botão (ENC_PRESS). O valor ENC_NONE é usado para indicar que não houve nenhum evento, permitindo que a função encoder_get_event retorne um valor padrão quando não houver mudanças no estado do encoder.
{
    ENC_NONE = 0, // Valor padrão para indicar que não houve nenhum evento do encoder. Esse valor é retornado pela função encoder_get_event quando não há mudanças no estado do encoder, como rotação ou pressão do botão. O valor 0 é usado para facilitar a verificação de eventos, permitindo que a aplicação possa simplesmente verificar se o valor retornado é diferente de ENC_NONE para determinar se ocorreu um evento do encoder.
    ENC_CW,   // Valor para indicar uma rotação no sentido horário do encoder rotativo. Esse valor é retornado pela função encoder_get_event quando o encoder é girado no sentido horário, permitindo que a aplicação possa executar ações específicas em resposta a esse evento, como navegar para baixo em um menu ou aumentar um valor configurável.
    ENC_CCW,  // Valor para indicar uma rotação no sentido anti-horário do encoder rotativo. Esse valor é retornado pela função encoder_get_event quando o encoder é girado no sentido anti-horário, permitindo que a aplicação possa executar ações específicas em resposta a esse evento, como navigate para cima em um menu ou diminuir um valor configurável.
    ENC_PRESS  // Valor para indicar que o botão do encoder foi pressionado. Esse valor é retornado pela função encoder_get_event quando o botão do encoder é pressionado, permitindo que a aplicação possa executar ações específicas em resposta a esse evento, como selecionar uma opção em um menu ou confirmar uma configuração.

}EncoderEvent_t; // Tipo de dado para representar os eventos do encoder rotativo, usando a enumeração EncoderEvent_t. Esse tipo de dado é usado como o tipo de retorno da função encoder_get_event, permitindo que a aplicação possa verificar o evento retornado e executar ações específicas com base no tipo de evento do encoder que ocorreu.

void encoder_init(void); // Função para inicializar o timer configurado no modo Encoder Interface para ler o encoder rotativo. Essa função deve ser chamada durante a fase de inicialização do programa, após a configuração do timer e dos GPIOs necessários para o funcionamento do encoder. A função encoder_init é responsável por iniciar o timer no modo Encoder Interface, permitindo que a função encoder_get_event possa ler os pulsos gerados pelo encoder rotativo e determinar a direção de rotação, bem como ler o estado do botão do encoder para detectar eventos de pressão.

EncoderEvent_t encoder_get_event(void); // Função para ler o estado do encoder rotativo e retornar um evento correspondente. Essa função verifica a diferença entre o valor atual do contador do timer e o valor anterior (old_count) para determinar a direção de rotação do encoder (horário ou anti-horário).

#ifdef __cplusplus // Fim do bloco de código C
}  // Fecha o bloco de código C para permitir a compilação em C++
#endif

#endif
