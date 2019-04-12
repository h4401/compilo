int factoriel(int x){
    
    if(x<=1)
    {
	return 1;
    }
    else
    {
	return x*factoriel(x-1);
    }
}

int main(){
    int b = 5;
    int res;
    res = factoriel(b);
    return res;
}
