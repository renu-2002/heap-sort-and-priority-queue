
#include<bits/stdc++.h>
using namespace std;
//function for swping
	int maximum=10000;
void swap(int &x,int &y){
	int temp=x;
	x=y;
	y=temp;
	
}
//for checking if heap is full or not
int isfull(int a,int b){
	if(a<b)
	  return 0;
	else 
	return 1;
}
//function for displaying array
void display(int array[],int size){
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}
//function heapify
void heapify(int *a,int size,int i){
	int max=i;
	int l=2*i+1;//left chid
	int r=2*i+2;//right child
	//whether right is less than size or not
	if(r<size){
		//content on left and right size of i 
		if(a[l]<a[r]){
			max=r;
		}
		else{max=l;
		}
	}
	else if(l<size){
		if(a[l]>a[i]){
			max=l;
		}
		else{
		
		max=i;
	}
	}
	if(a[i]<a[max]){
		swap(a[max],a[i]);
		heapify(a,size,max);
	}
}
//function for bulding heap
void heap_build(int arr[],int n){
	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	}
	//heap short function
void heapsort(int array[],int n){
	heap_build(array,n);
	for(int i=n-1;i>0;i--){
		swap(array[i],array[0]);
		heapify(array,i,0);
	}
}
//fr deleting any random element
void delete_elemet(int array[],int &size,int i){
	if(i<size){
		int x=array[i];
		array[i]=array[size-1];
		size--;
		int parent = ceil(i/2.0)-1;
		if(array[i]>x){
			while(i>0&&array[i]>array[parent]){
				swap(array[i],array[parent]);
				i=parent;
				parent=ceil(i/2.0)-1;
			}
		}
		else{
			heapify(array,size,i);
		}
	}
}
//for inserting an element
void insert_element(int array[],int &size,int x){
	if(isfull(size,maximum)){
		cout<<"HEAP IS FULL\n";
		return ;
		
	}
	else{
	
	array[size]=x;
	size++;
	int i=size-1;
	int parent=ceil(i/2.0)-1;
	while(i>0&&array[i]>array[parent]){
				swap(array[i],array[parent]);
				i=parent;
				parent=ceil(i/2.0)-1;
			}
 }
	
}
//for deleting maximum element
int maximumremove(int array[],int &size){
	int x=array[0];
	array[0]=array[size-1];
	size--;
	heapify(array,size,0);
	return x;
}

int main(){

	int size=0;
	int count;
	cout<<"ENTER A SIZE OF HEAP:";
	cin>>count;
	int array[maximum]={0};
	cout<<"ENTER AN ELEMENETS:\n";
	for(int i=0;i<count;i++){
		cin>>array[i];
		size++;
	}
	heapsort(array,size);
	cout<<"SORTED ARRAY:"<<endl;
	display(array,size);
	cout<<endl;
	heap_build(array,size);
	insert_element(array,size,20);
	cout<<"AFTER INSERTION ARRAY:\n";
	display(array,size);
	cout<<"AFTER REMOVING MAXIMUM ELEMENT:\n";
	maximumremove(array,size);
	display(array,size);
	if(isfull(size,maximum)){
		cout<<"HEAP IS FULL.\n";
	}
	else{
		cout<<"HEAP IS EMPTY.\n";
		
	}
    return 0;
}
