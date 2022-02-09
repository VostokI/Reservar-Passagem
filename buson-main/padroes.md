Requisitos a serem implementados:

b) Vender um acento para um cliente cadastrado.

c) Cadastrar um cliente para permitir realizar uma venda. (nome; CPF).

d) Excluir um cadastro.

e) Retirar a reserva de um cliente.

f) Alterar o acento vendido.

g) Alterar uma reserva.

h) Pesquisar um cliente por nome.

i) Pesquisar um cliente por CPF.

j) Imprimir todos os clientes cadastrados.

k) Imprimir os dados das poltronas na tela.


(clientes.bin)
Sempre que o programa for encerrado, os clientes cadastrados devem ser armazenados em
um arquivo binário 


(poltronas.bin)
e os dados das poltronas devem ser armazenadas em um arquivo binário

Quando o programa iniciar, os clientes e os dados das poltronas devem ser inicializados com
os dados contidos nestes arquivos binários.


Ao final do prazo estipulado pelo professor os alunos deverão apresentar o trabalho
efetuado.





Retornamos 0 para sucesso, e 1 (ou outro valor) para insucesso
independente disso, podemos atribuir alguma mensagem ao ptr msg,




//Toda String dentro de uma struct não é ponteiro, isso facilita para salvar, ainda que a um custo maior de memória.
 
//o id de um objeto, representa a posicao desse objeto em um vetor de objetos;


//Usar Casting em Ponteiros:
sem casting:
int * a = malloc(sizeof(int));
Com casting:
int *a = (int * ) malloc(sizeof(int));

#testar programas utilizando os testadores na pasta teste

Dado uma viacao -> id.via (CADA VIAÇÃO É UM ARQUIVO DIFERENTE COM NOME DIFERENTE ID.VIA)
ID      NOME        NUMERO_DE_ONIBUS HORARIOS
id_on   linha	    n_pol
id_on   linha	    n_pol
id_on   linha	    n_pol
id_on   linha	    n_pol
id_on   linha	    n_pol
id_on   linha	    n_pol
id_on   linha	    n_pol
id_on   linha	    n_pol

DADO VÁRIOS CLIENTES
CPF (uns)     NOME
000000000 nome\n
000000000 nome2 sobrenome\n

Dado os pedidos:
id_viacao   d_onibus    id_poltrona     CPF   DATA    STATUS (vouche reservado ou voucher vendido)
01  02  03  0000000000  31/12/2021 00:00 vr

Dado os horários: (id_onibus_id_via.hor)
id_via id_bus data hora