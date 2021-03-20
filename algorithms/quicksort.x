def inteiro programa(){
   inteiro i;
   inteiro count = 10;
   vetor inteiro[] number = [2,5,9,3,6,1,0,7,4,8];

   inteiro last = count -1;
   quicksort(number,0,last);

   para(inteiro i = 0; i < 10; i += 1){
      escreva(number[i]);
   }
   
   retorne 0;
}

def vazio quicksort(vetor inteiro[] number, inteiro first, inteiro last){
   inteiro j, pivot, temp;

   se(first<last){
      pivot=first;
      j=last;

      para(inteiro i = first; i < j; i+=1){
         para(inteiro guardi = number[i]; guardi <= number[pivot]&& i < last; i+=1){
            guardi = number[i];
         }
         para(inteiro guardj = number[j]; guardj > number[pivot]; j-=1){
            guardj = j;
         }
         se(i<j){
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         };
      }

      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;
      currentjplus = j + 1;
      currentjminus = j - 1;
      quicksort(number,first,currentjminus);
      quicksort(number,currentjplus,last);

   };
}
