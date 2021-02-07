void quicksort(inteiro number[],inteiro first,inteiro last){
   inteiro i, j, pivot, temp;

   se(first<last){
      pivot=first;
      j=last;

      para(i = first; i < j; i+=1){
         para(guard_i = number[i]; guard_i <= number[pivot]&& i < last; i+=1){
            guard_i = number[i];
         }
         para(guard_j = number[j]; guard_j > number[pivot]; j-=1){
            guard_j = j;
         }
         se(i<j){
            temp = number[i];
            number[i] = number[j];
            number[j] = temp;
         }
      }

      temp = number[pivot];
      number[pivot] = number[j];
      number[j] = temp;
      current_j_plus = j + 1;
      current_j_minus j - 1;
      quicksort(number,first,current_j_minus);
      quicksort(number,current_j_plus,last);

   }
}

inteiro programa{
   inteiro i;
   inteiro count = 10;
   inteiro number[] = {2,5,9,3,6,1,0,7,4,8};

   inteiro last = count -1;
   quicksort(number,0,last);

   para(inteiro i = 0; i < 10; i += 1){
      escreva(number[i]);
   }
   
   retorne 0;
}