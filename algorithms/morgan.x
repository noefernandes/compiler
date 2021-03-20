def inteiro programa(){
    conjunto inteiro a = [1, 2, 3, 4, 5, 6, 7];
	conjunto inteiro b = [2, 3, 4];
	conjunto inteiro c;
	conjunto inteiro d;
        
	//c = (a /\ b)'
	c = a /\ b;
	//c = c';
 
	//d = a' \/ b'
	//a = a';
	//b = b';
    
    d = a \/ b;
        
    //Verificando equivalência
    escreva(c);
   	escreva(d);

   	retorne 0;
}
