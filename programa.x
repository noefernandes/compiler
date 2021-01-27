programa{
	inteiro a;
	real b = 2.73;

	leia(a);
	
	inteiro i = 0;
	enquanto(i < 5){
		se(a > 30){
			pare;
		}
		a = a + b;
	}

	escreva("o resultado eh: ", a);
}
