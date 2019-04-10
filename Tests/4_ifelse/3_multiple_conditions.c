void main(){
	int a;
	int b;
	int c;
	a=4;
	b=8;
	c=b+1;
	if(a==4 && (b==a || b>c || c==b+1) && a<=b){
		return 1;
	}
	else{
		return 3;
	}
	return 8;
}
