
#include<stdio.h>
#include<math.h>
#include<ctype.h>
char s[100];
int i,top=-1;
void push(char x){
	
	s[++top]=x;
}
char pop(){
	if(top==-1)
	return -1;
	else{
		return s[top--];
	}
}
void print(){

	for(i=top;i>=0;i--)
		printf("%c",s[i]);
}
int priority(char x){
	switch(x) {
		case '^': return 3;
		case '*':
		case '/': return 2;
		case '+':
		case '-': return 1;
	}
	return -1;
}
int post_eval( char post[],int n){
	int A[20],j=0,m,x,y,op,res;
	i=0;
	while(post[i]!='#'){
		if(isalpha(post[i])){
			printf("Enter value for %c:",post[i]);
			scanf("%d",&A[j]);j++;
		}
		i++;
	}
	i=0;m=j;j=0;
	while(post[i]!='#'){
		if(isalpha(post[i])){
			push(A[j]);j++;
		}
		else{
			op=post[i];
			y=pop();x=pop();
			switch(op){
				case '+':res=x+y;break;
				case '-':res=x-y;break;
				case '*':res=x*y;break;
				case '/':res=x/y;break;
				case '^':res=pow(x,y);break;	
			}
			push(res);
			
		}
		i++;
	}
	return pop();
}
int main(){
	char exp[100],post[100];
	i=0;
	char *p,x,x1;
	printf("Enter expression\n");
	scanf("%s",exp);
	p=exp;
	printf("The postfix expression is:\n");
	while(*p!='\0'){
		if(isalnum(*p)){
			printf("%c",*p);
			post[i]=*p;
			i++;
			}
			
		else if(*p=='(')
			push(*p);
		else if(*p==')'){
			x=pop();
			while(x !='('){
				printf("%c",x);
				post[i]=x;i++;
				x=pop();
				}
			}
		else{
			while(priority(s[top]) >=priority(*p)){
				x1=pop();
				printf("%c",x1);
				post[i]=x1;i++;
				}
			push(*p);
				
		}
		p++;
		}
	while(top!=-1){
		x1=pop();
		printf("%c",x1);
		post[i]=x1;i++;
		}
	printf("\n");
	int n=i;
	post[n]='#';
	int result = post_eval(post,n);
	printf("The result of the expression is = %d",result);
}
