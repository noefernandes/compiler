deftipo registro Pessoa{
	palavra nome;
	vetor inteiro[] numeros = {1, 2, 3, 4};
}

def inteiro programa(){
	inteiro i;
	i = 8 + 4;
	(inteiro) i = 1 * 2;

	para(inteiro i = 0; i < 6; i = i + 1){
		se(i < 5){
			pare;
		};
	}
}