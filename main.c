int a;
int b;
int c;
int d;
int e;

int function_sum(int x, int y) {
  int sum;
  sum=x+y;
  
  return sum;
}

int function_sub(int x, int y) {
	int sub;
	sub = x-y;
}

int main(void){
  a=2;
  b=3;
  c = function_sum(a, b);
  d = function_sub(b, a)
  
  return 0;
  
}


