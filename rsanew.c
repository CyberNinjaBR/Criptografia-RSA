#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//BLOCO DE FUNCOES ESSENCIAIS
//calcula qualquer exponenciacao_modular CUIDADO!!!(ALTO NIVEL DE CABULOSIDADE)
long long int exponenciacao_modular_rapida(long long int denominador, long long int potencia, long long int mod)
{
    long long int resultado = 1, numaux = denominador % mod;

    //calculando a exponenciacao modular
    for ( ; potencia > 0; potencia /= 2) 
    {
        if (potencia % 2 == 1)
        {
            resultado = (resultado * numaux) % mod;
        }
    
        numaux = (numaux * numaux) % mod;
     }
    
      return resultado;
}



//BLOCO DE FUNCOES QUE DESCRIPTOGRAFAM A MENSAGEM
//escreve a mensagem final no vetor
void escreve2(char b[], int pos, int final)
{
    int i;
    //Cria um ponteiro para o arquivo
    FILE *pont_trad;

    //Abrindo ou criando o arquivo no modo 'a' de escrita
    pont_trad = fopen("mensagem.txt", "a");

    //Testando se realmente o arquivo foi criado
    if(pont_trad == NULL)
    {
        printf("Erro na abertura/criacao do arquivo!\nO programa sera fechado\n");
        return;
    }

    for(i = pos; i < final; i++)
    {
        //Usando o fprintf para gravar no txt
        fprintf(pont_trad, "%c", b[i]);
    }
    //Usando o fclose para fechar o arquivo
    fclose(pont_trad);

    printf("Dados gravados com sucesso em: mensagem.txt!\n");
    return;
}

//pega a mensagem encriptada e transforma em letras
void desencripta(int cod[], char trad[], int pos)
{
    if(cod[pos] == 2)
    {
        trad[pos] = 'a';
    }
    else if(cod[pos] == 3)
    {
        trad[pos] = 'b';
    }
    else if(cod[pos] == 4)
    {
        trad[pos] = 'c';
    }
    else if(cod[pos] == 5)
    {
        trad[pos] = 'd';
    }
    else if(cod[pos] == 6)
    {
        trad[pos] = 'e';
    }
    else if(cod[pos] == 7)
    {
        trad[pos] = 'f';
    }
    else if(cod[pos] == 8)
    {
        trad[pos] = 'g';
    }
    else if(cod[pos] == 9)
    {
        trad[pos] = 'h';
    }
    else if(cod[pos] == 10)
    {
        trad[pos] = 'i';
    }
    else if(cod[pos] == 11)
    {
        trad[pos] = 'j';
    }
    else if(cod[pos] == 12)
    {
        trad[pos] = 'k';
    }
    else if(cod[pos] == 13)
    {
        trad[pos] = 'l';
    }
    else if(cod[pos] == 14)
    {
        trad[pos] = 'm';
    }
    else if(cod[pos] == 15)
    {
        trad[pos] = 'n';
    }
    else if(cod[pos] == 16)
    {
        trad[pos] = 'o';
    }
    else if(cod[pos] == 17)
    {
        trad[pos] = 'p';
    }
    else if(cod[pos] == 18)
    {
        trad[pos] = 'q';
    }
    else if(cod[pos] == 19)
    {
        trad[pos] = 'r';
    }
    else if(cod[pos] == 20)
    {
        trad[pos] = 's';
    }
    else if(cod[pos] == 21)
    {
        trad[pos] = 't';
    }
    else if(cod[pos] == 22)
    {
        trad[pos] = 'u';
    }
    else if(cod[pos] == 23)
    {
        trad[pos] = 'v';
    }
    else if(cod[pos] == 24)
    {
        trad[pos] = 'w';
    }
    else if(cod[pos] == 25)
    {
        trad[pos] = 'x';
    }
    else if(cod[pos] == 26)
    {
        trad[pos] = 'y';
    }
    else if(cod[pos] == 27)
    {
        trad[pos] = 'z';
    }
    else if(cod[pos] == 28)
    {
        trad[pos] = ' ';
    }
    else
    {
        return;
    }
    desencripta(cod, trad, pos+1);
}

//descriptografa a mensagem
void mod2(int d, int n, int cod[], int msg[], int pos, int lim, int *final)
{
    if(pos == lim)
    {
        msg[pos] = -1;
        return;
    }
    else
    {
        *final+=1;
        msg[pos] = exponenciacao_modular_rapida(cod[pos], d, n);

        mod2(d, n, cod, msg, pos+1, lim, final);
    }
}

//valida a chave privada
void validachave2(int chave[])
{
    int n, e;
    scanf("%d %d", &n, &e);
    if(chave[0] == n && chave[1] == e)
    {
        printf("Chave valida, iniciando incriptacao\n");
        return;
    }
    else
    {
        printf("Chave invalida, tente novamente\n");
        validachave2(chave);
    }
}

//le a chave privada
void lerchave2(int chave[])
{
    //Cria um ponteiro para o arquivo
    FILE *pont_key;

    //Abrindo ou criando o arquivo no modo 'r' de leitura
    pont_key = fopen("chave_privada.txt", "r");

    //Usando o fprintf para gravar no txt
    fscanf(pont_key, "%d %d", &chave[0], &chave[1]);
    //Usando o fclose para fechar o arquivo
    fclose(pont_key);

    return;
}

//corpo da funcao desencripta
void mngdesencripta()
{
    char msg[2000];
    int cod[2000];
    int chave[2], i = 0, num, final;
    lerchave2(chave);
    printf("Digite a chave privada para desencriptar a mensagem\n");
    validachave2(chave);

    //lendo a mensagem
    //Cria um ponteiro para o arquivo
    FILE *pont_cod;

    //Abrindo ou criando o arquivo no modo 'r' de leitura
    pont_cod = fopen("script.txt", "r");

    //Lendo o codigo
    if(pont_cod == NULL)
    {
        printf("Erro na leitura do arquivo!\nO programa sera fechado\n");
        return;
    }
    
    else
    {
        //pega os valores do arquivo e joga no vetor cod
        while(fscanf(pont_cod, "%d", &num) != EOF)
        {
            cod[i] = num;
            i++;
        }
    }

    //Usando o fclose para fechar o arquivo
    fclose(pont_cod);

    mod2(chave[0], chave[1], cod, cod, 0, i, &final);
    desencripta(cod, msg, 0);
    //Funcao de escrever no arquivo (OK)
    escreve2(msg, 0, final);

    return;
}



//BLOCO DE FUNCOES QUE ENCRIPTAM  MENSAGEM
//escreve a mensagem criptografada em forma de números no arquivo txt
void escreve(int b[], int pos, int final)
{
    int i;
    //Cria um ponteiro para o arquivo
    FILE *pont_msg;

    //Abrindo ou criando o arquivo no modo 'w' de escrita
    pont_msg = fopen("script.txt", "a");

    //Testando se realmente o arquivo foi criado
    if(pont_msg == NULL)
    {
        printf("Erro na abertura/criacao do arquivo!\nO programa sera fechado\n");
        return;
    }
    for(i = pos; i < final; i++)
    {
        //Usando o fprintf para gravar no txt
        fprintf(pont_msg, "%d ", b[i]);
    }

    //Usando o fclose para fechar o arquivo
    fclose(pont_msg);

    printf("Dados gravados com sucesso em: script.txt!\n");
    return;
}

//criptografa a mensagem
void mod(int scpt[], int pos, int e, int n, int *final)
{
    
    if(scpt[pos] == 2 || scpt[pos] == 3 || scpt[pos] == 4 || scpt[pos] == 5  || scpt[pos] == 6  || scpt[pos] == 7  || scpt[pos] == 8  ||
    scpt[pos] == 9  || scpt[pos] == 10 || scpt[pos] == 11 || scpt[pos] == 12 || scpt[pos] == 13 || scpt[pos] == 14 || scpt[pos] == 15 ||
    scpt[pos] == 16 || scpt[pos] == 17 || scpt[pos] == 18 || scpt[pos] == 19 || scpt[pos] == 20 || scpt[pos] == 21 || scpt[pos] == 22 ||
    scpt[pos] == 23 || scpt[pos] == 24 || scpt[pos] == 25 || scpt[pos] == 26 || scpt[pos] == 27 || scpt[pos] == 28)
    {
        *final+=1;
        scpt[pos] = exponenciacao_modular_rapida(scpt[pos], e, n);
        mod(scpt, pos + 1, e, n, final);
    }
    else
    {
        scpt[pos] = -1;
        return;
    }
}

//substitui as letras por numeros
void encripta(char a[], int b[], int pos)
{
    if(a[pos] == 'A' || a[pos] == 'a')
    {
        b[pos] = 2;
    }
    else if(a[pos] == 'B' || a[pos] == 'b')
    {
        b[pos] = 3;
    }
    else if(a[pos] == 'C' || a[pos] == 'c')
    {
        b[pos] = 4;
    }
    else if(a[pos] == 'D' || a[pos] == 'd')
    {
        b[pos] = 5;
    }
    else if(a[pos] == 'E' || a[pos] == 'e')
    {
        b[pos] = 6;
    }
    else if(a[pos] == 'F' || a[pos] == 'f')
    {
        b[pos] = 7;
    }
    else if(a[pos] == 'G' || a[pos] == 'g')
    {
        b[pos] = 8;
    }
    else if(a[pos] == 'H' || a[pos] == 'h')
    {
        b[pos] = 9;
    }
    else if(a[pos] == 'I' || a[pos] == 'i')
    {
        b[pos] = 10;
    }
    else if(a[pos] == 'J' || a[pos] == 'j')
    {
        b[pos] = 11;
    }
    else if(a[pos] == 'K' || a[pos] == 'k')
    {
        b[pos] = 12;
    }
    else if(a[pos] == 'L' || a[pos] == 'l')
    {
        b[pos] = 13;
    }
    else if(a[pos] == 'M' || a[pos] == 'm')
    {
        b[pos] = 14;
    }
    else if(a[pos] == 'N' || a[pos] == 'n')
    {
        b[pos] = 15;
    }
    else if(a[pos] == 'O' || a[pos] == 'o')
    {
        b[pos] = 16;
    }
    else if(a[pos] == 'P' || a[pos] == 'p')
    {
        b[pos] = 17;
    }
    else if(a[pos] == 'Q' || a[pos] == 'q')
    {
        b[pos] = 18;
    }
    else if(a[pos] == 'R' || a[pos] == 'r')
    {
        b[pos] = 19;
    }
    else if(a[pos] == 'S' || a[pos] == 's')
    {
        b[pos] = 20;
    }
    else if(a[pos] == 'T' || a[pos] == 't')
    {
        b[pos] = 21;
    }
    else if(a[pos] == 'U' || a[pos] == 'u')
    {
        b[pos] = 22;
    }
    else if(a[pos] == 'V' || a[pos] == 'v')
    {
        b[pos] = 23;
    }
    else if(a[pos] == 'W' || a[pos] == 'w')
    {
        b[pos] = 24;
    }
    else if(a[pos] == 'X' || a[pos] == 'x')
    {
        b[pos] = 25;
    }
    else if(a[pos] == 'Y' || a[pos] == 'y')
    {
        b[pos] = 26;
    }
    else if(a[pos] == 'Z' || a[pos] == 'z')
    {
        b[pos] = 27;
    }
    else if(a[pos] == ' ')
    {
        b[pos] = 28;
    }
    else
    {
        return;
    }
    encripta(a, b, pos+1);
}

//valida a chave publica
void validachave(int chave[])
{
    int n, e;
    scanf("%d %d", &n, &e);
    if(chave[0] == n && chave[1] == e)
    {
        printf("Chave valida, iniciando incriptacao\n");
        return;
    }
    else
    {
        printf("Chave invalida, tente novamente\n");
        validachave(chave);
    }
}

//le a chave publica
void lerchave(int chave[])
{
    //Cria um ponteiro para o arquivo
    FILE *pont_key;

    //Abrindo ou criando o arquivo no modo 'r' de leitura
    pont_key = fopen("chave_publica.txt", "r");

    //Usando o fprintf para gravar no txt
    fscanf(pont_key, "%d %d", &chave[0], &chave[1]);
    //Usando o fclose para fechar o arquivo
    fclose(pont_key);

    return;
}

//funcao corpo de encriptar
void mngencripta()
{
    printf("Digite uma mensagem de texto de ate 2000 caracteres, apos concluida a mensagem aperte enter\n");
    char msg[2000];
    int scpt[2000];
    scanf(" %[^\n]", msg);
    int chave[2], final;
    //valida a chave publica gerada
    lerchave(chave);
    printf("Digite a chave publica recebida previamente\n");
    validachave(chave);
    //substitui a mensagem escrita por uma mensagem numerica
    encripta(msg, scpt, 0);
    //encripta a mensagem
    mod(scpt, 0, chave[0], chave[1], &final);
    //escreve ela em caracteres
    escreve(scpt, 0,final);

    return;
}



//BLOCO DE FUNCOES GERADORAS DE CHAVE PUBLICA E PRIVADA
//gera o arquivo da chave privada
void gerachave_privada(long long int d, long long int mult)
{
    //Cria um ponteiro para o arquivo
    FILE *pont_num;

    //Abrindo ou criando o arquivo no modo 'w' de escrita
    pont_num = fopen("chave_privada.txt", "w");

    //Testando se realmente o arquivo foi criado
    if(pont_num == NULL)
    {
        printf("Erro na abertura/criacao do arquivo!\nO programa sera fechado\n");
        return;
    }

    //Usando o fprintf para gravar no txt
    fprintf(pont_num, "%lld %lld", d, mult);

    //Usando o fclose para fechar o arquivo
    fclose(pont_num);

    printf("Chave privada: %lld %lld\nDados gravados com sucesso em: chave_privada.txt!\n", d, mult);
    return;

}

//gera o arquivo da chave publica
void gerachave_publica(long long int e, long long int multi)
{
    //Cria um ponteiro para o arquivo
    FILE *pont_num;

    //Abrindo ou criando o arquivo no modo 'w' de escrita
    pont_num = fopen("chave_publica.txt", "w");

    //Testando se realmente o arquivo foi criado
    if(pont_num == NULL)
    {
        printf("Erro na abertura/criacao do arquivo!\nO programa sera fechado\n");
        return;
    }

    //Usando o fprintf para gravar no txt
    fprintf(pont_num, "%lld %lld", e, multi);

    //Usando o fclose para fechar o arquivo
    fclose(pont_num);

    printf("Chave publica: %lld %lld\nDados gravados com sucesso em: chave_publica.txt!\n", e, multi);
    return;

}

//verifica se (p-1)*(q-1) e sao coprimos
long long int verifica_coprimo(long long int p, long long int q)
{
    long long int resto = 1, i;
    //caso em que o p for maior que o q
    if(q <  p)
    {
        //calcula o MDC por euclides dos dois numeros digitados
        for(i = q; resto != 0; i = resto)
        {
            resto = p % i;
            p = i;
        }
        //caso o MDC seja 1 entao eles sao copirmos(1), caso contrario nao sao coprimos(0)
        if(p == 1)
        {
            return 1;
        }
        return 0;
    }

    //caso em que o q for maior que o p
    //calcula o MDC por euclides dos dois numeros digitados
    for(i = p; resto != 0; i = resto)
    {
        resto = q % i;
        q = i;
    }
     //caso o MDC seja 1 entao eles sao copirmos(1), caso contrario nao sao coprimos(0)
    if(q == 1)
    {
        return 1;
    }
    return 0;
}

//verifica se p e q sao primos
long long int verifica_primo(long long int valor)
{
    long long int i, cont = 0, resultado;
    //Se o valor for divisivel por i ele acrescenta 1 no contador
    for(i = 1; i < valor; i++)
    {
        if(valor % i == 0)
        {
            cont += 1;
        }
        //faz a verificacao, se o contador for igual a 2 entao e primo(1), caso contrario nao e(0)
        if(i + 1 == valor)
        {
            cont += 1;
            if(cont == 2)
            {
                resultado = 1;
            }
            else
            {
                resultado = 0;
            }
        }
    }
    return resultado;
}

//funcao corpo de gerar chave
void chave()
{
    long long int p, q, e, i, tot, form;
    scanf("%lld %lld %lld", &p, &q, &e);
    long long int primop = verifica_primo(p);
    long long int primoq = verifica_primo(q);; 
    long long int coprimo_pqe = verifica_coprimo((p-1)*(q-1), e);
    //testa se 'p' e menor que 5
    if(p < 5)
    {
        printf("O numero %lld e menor que 5\n", p);
    }
    //testa se 'q' e menor que 5
    if(q < 5)
    {
        printf("O numero %lld e menor que 5\n", p);
    }
    //testa se 'p' e 'q' sao iguais a 5
    if(q == p && q == 5)
    {
        printf("O numero %lld e igual a %lld\n", q, p);
    }
    //testa se 'e' e menor que 5
    if(e < 5)
    {
        printf("O numero %lld e menor que 5\n", p);
    } 
    //testa 'e' e igual a 'p' ou 'q' e se 'e' e 5
    if(e == p && e == 5 || e == q && e == 5)
    {
        printf("O numero %lld e igual a %lld\n", q, e);
    }
    //testa se o 'p' informado e primo
    if(primop != 1)
    {
        printf("O numero (p = %lld) nao e primo.\n", p);
    }
    //testa se o 'q' informado e primo
    if(primoq != 1)
    {
        printf("O numero (q = %lld) nao e primo\n", q);
    }
    //testa se o (p-1)*(q-1) e 'e' sao coprimos
    if(coprimo_pqe != 1)
    {
        printf("(e = %lld) nao e coprimo em relacao a (p-1)*(q-1)\n", e);
    }
    //se 'p', 'q' e 'e' nao atenderem ao requesito recomeca
    if(primop != 1 || primoq != 1 || coprimo_pqe != 1 || p < 5 || q < 5 || 
    q == p && q == 5 || e < 5 || e == p && e == 5 || e == q && e == 5)
    {
        printf("Tente novamente\n");
        chave();
    }
    //se 'p', 'q' e 'e' nao atenderem ao requesito continua
    else if(primop == 1 && primoq == 1 && coprimo_pqe == 1)
    {
        //procura parte da chave privada
        for(i = 0; form != 1; i++)
        {
            tot = ((p-1)*(q-1));
            form = (e*i) % tot;
        }
        i-=1;
        //gera um arquivo txt com a chave privada
        gerachave_privada(i, (p)*(q));
        //gera um arquivo txt com a chave publica
        gerachave_publica(e, (p)*(q));
    }
    return;
}

//inicio da funcao gerar chave
void mngchave()
{
    printf("Digite um par de numeros primos: 'p' e 'q' em que p e q sejam maiores que ou iguais a 5.\nOBS: se p = 5, ou q = 5 ou e = 5, digitar um valor diferente para as demais variaveis\nEm seguida digite um expoente 'e', que seja coprimo ao produto (p-1)*(q-1) em que 'e' seja maior ou igual a que 5\n");
    chave();
    return;
}



//BLOCO DE FUNCOES REDIRECIONADORAS
//funcao primordial
void mngopcoes()
{
    int opc;
    scanf("%d", &opc);
    //chama o bloco de funcoes para gerar as chaves
    if(opc == 1)
    {
        mngchave();
        return;
    }
    //chama o bloco de funcoes para encriptar
    if(opc == 2)
    {
        mngencripta();
        return;
    }
    //chama o bloco de funcoes para desencriptar
    else if(opc == 3)
    {
        mngdesencripta();
        return;
    }
    //caso o valor digitado tenha sido errado ela recomeca
    else
    {
        printf("Opcao invalida, tente novamente\n");
        mngopcoes();
    }
}

//chama a funcao primordial
int main()
{
    printf("Escolha uma das opcoes:\n1 - Gerar chaves\n2 - Encriptar mensagem\n3 - Desencriptar mensagem\n");
    mngopcoes();
    
    return 0;
}