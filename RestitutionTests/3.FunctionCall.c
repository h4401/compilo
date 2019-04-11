int sum(int a, int b){
    int c;
    c = a + b;
    return c;
}

int main(){
	int a;
    int b;
	a=4;
    b=0;
	if(a==2){
		return 1;
	} else {
		b = sum(a,a);
	}
	return b;
}