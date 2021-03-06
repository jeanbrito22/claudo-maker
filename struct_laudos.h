typedef struct{
	char cnpj[15];
	char nome_produto[51];
	int qt_produto;
	int num_chamado;
	char opcao_embal[5];
	char estado_embalagem[21];
	char cond_embal[21];
	char opcao_pragas[5];
	char nivel_ident[21];
	char conclusao[200];
}laudos;

void copia_string(char *copiar, char *colar){
	int i;
	for (i = 0; i < strlen(copiar); i++)
		colar[i] = copiar[i];
	colar[i] = '\0';
	return;
}

void validar_cnpj_laudo(char *cnpj){
	int valido, i;
	do{
		printf("CNPJ [apenas numeros]: ");
		scanf(" %14[^\n]",  cnpj);
		valido = 1;
		for (i = 0; i < strlen(cnpj); i++){
			if (!isdigit(cnpj[i])){
				valido = 0;
				break;
			}
		}
	}while(strlen(cnpj) != 14 ||  valido == 0);

	return;
}


void preencher_laudo(laudos *laudo){
	int opcao, opcao_embalagem1, opcao_embalagem2;

	validar_cnpj_laudo(laudo->cnpj);

	printf("Nome do produto: ");
	scanf(" %50[^\n]", laudo->nome_produto);

	printf("Quantidade do produto: ");
	scanf("%d", &laudo->qt_produto);

	printf("Numero do chamado: ");
	scanf("%d", &laudo->num_chamado);

	do{
		printf("Os produtos tinham embalagem: [1] SIM [2] NAO: ");
		scanf("%d", &opcao);
	}while(opcao != 1 && opcao != 2);

	if (opcao == 1){
		fflush(stdin);
		copia_string("Sim",laudo->opcao_embal);

		do{
			printf("Qual o estado da embalagem:  [1] ABERTA [2] FECHADA: ");
			scanf("%d", &opcao_embalagem1);
		}while(opcao_embalagem1 != 1 && opcao_embalagem1 != 2);


		if (opcao_embalagem1 == 1)
			copia_string("Aberta", laudo->estado_embalagem);
		else
			copia_string("Fechada", laudo->estado_embalagem);


		do{
			printf("Qual a condicao da embalagem: [1] SEM ALTERACOES FISICAS [2] COM ORIFICIOS [3] RASGADA:  ");
			scanf("%d", &opcao_embalagem2);
		}while(opcao_embalagem2 != 1 && opcao_embalagem2 != 2 && opcao_embalagem2 != 3);


		if (opcao_embalagem2 == 1)
			copia_string("Sem alteracoes fisicas", laudo->cond_embal);
		else if (opcao_embalagem2 == 2)
			copia_string("Com orificios", laudo->cond_embal);
		else
			copia_string("Rasgada", laudo->cond_embal);

	}
	else{
		fflush(stdin);
		copia_string("Nao", laudo->opcao_embal);
		fflush(stdin);
		copia_string("None", laudo->estado_embalagem);
		fflush(stdin);
		copia_string("None",laudo->cond_embal);
	}


	do{
		printf("Os produtos tinham praga: [1] SIM [2] NAO: ");
		scanf("%d", &opcao);
	}while(opcao != 1 && opcao != 2);

	if (opcao == 1){
		copia_string("Sim",laudo->opcao_pragas);
		printf("Qual o nivel de identificacao? : ");
		scanf(" %20[^\n]", laudo->nivel_ident);

	}
	else{
		copia_string("Nao", laudo->opcao_pragas);
		copia_string("None", laudo->nivel_ident);
	}

	printf("Conclusao: ");
	scanf(" %200[^\n]", laudo->conclusao);


}


void exibir_laudo(laudos laudo){
	printf("CNPJ: %s\n", laudo.cnpj);
	printf("Nome do produto: %s\n", laudo.nome_produto);
	printf("Quantidade do produto: %d\n", laudo.qt_produto);
	printf("Numero do chamado: %d\n", laudo.num_chamado);
	printf("Ha embalagem: %s\n", laudo.opcao_embal);
	printf("Estado da embalagem: %s\n", laudo.estado_embalagem);
	printf("Condicao da embalagem: %s\n", laudo.cond_embal);
	printf("Ha praga: %s\n", laudo.opcao_pragas);
	printf("Nivel de identificacao: %s\n", laudo.nivel_ident);
	printf("Conclusao: %s\n", laudo.conclusao);
	return;
}