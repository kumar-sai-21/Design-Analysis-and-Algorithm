#include<stdio.h>
#include<stdlib.h>
#define MAX 30
struct linked {
    int freq;
    char ch;
    struct linked *left;
    struct linked *right;
};
typedef struct linked code;
void build_min_heap(code[],int);
void min_heapify(code[],int,int);
int left(int);
int right(int);
int parent(int);
void swap(code*,code*);
code extract_min_heap(code[],int*);
void heap_decrease_key(code[],int,int);
void min_heap_insert(code[],int*,code);
void huffman(code[],int);
void display(code*,int);
int main() {
    int i,heapsize;
    code ar[MAX];
    printf("\nEnter no. of elements : ");
    scanf("%d",&heapsize);
    //char ar[MAX] = {'a','b','c','d','e','f'};
    //int f[MAX] = {45,13,12,16,9,5};
    for(i = 0;i<heapsize;i++) {
        printf("\nEnter character : ");
        scanf(" %c",&ar[i].ch);
        printf("Enter frequency : ");
        scanf(" %d",&ar[i].freq);
        ar[i].left = NULL;
        ar[i].right = NULL;
    }
    huffman(ar,heapsize);
    return 0;
}

void display(code *ar,int number) {
    int left_no,right_no;
    if(ar->left != NULL) {
        left_no = number*10 + 0;
        display(ar->left,left_no);
    }
    if(ar->right != NULL) {
        right_no = number*10 + 1;
        display(ar->right,right_no);
    }
    else {
        printf("%c - %d\n",ar->ch,number);
    }
}

void huffman(code ar[],int heapsize) {
    int n;
    code *left,*right,*z;
    n = heapsize;
    build_min_heap(ar,heapsize);
    while(n!=1) {
        left = (code*)malloc(sizeof(code));
        right = (code*)malloc(sizeof(code));
        *left = extract_min_heap(ar,&n);
        *right = extract_min_heap(ar,&n);
        z = (code*)malloc(sizeof(code));
        z->ch = 0;
        z->freq = left->freq + right->freq;
        z->left = left;
        z->right = right;
        min_heap_insert(ar,&n,(*z));
        left = NULL;
        right = NULL;
        z = NULL;
    }
    display(&ar[0],0);
}

void min_heap_insert(code ar[],int *n,code ele) {
    int heapsize = (*n);
	if(heapsize == MAX) {
		printf("Heap Overflow");
		return;
	}
	heapsize += 1;
	ar[heapsize - 1].ch = ele.ch;
	ar[heapsize - 1].freq = 999;
    ar[heapsize - 1].left = ele.left;
    ar[heapsize - 1].right = ele.right;
	(*n) = heapsize;
    heap_decrease_key(ar,heapsize-1,ele.freq);
}

void heap_decrease_key(code ar[],int i,int ele) {
    if(ar[i].freq < ele) {
		printf("\nWrong element entered");
		return;
	}
	ar[i].freq = ele;
	while((i>=1) && (ar[i].freq < ar[parent(i)].freq)) {
		swap(&ar[i],&ar[parent(i)]);
		i = parent(i);
	}
}


code extract_min_heap(code ar[],int *n) {
    int heapsize = (*n);
	if(heapsize < 1) {
		printf("\nHeap Underflow");
	}
	code small = ar[0];
	heapsize = heapsize - 1;
	swap(&ar[0],&ar[heapsize]);
	min_heapify(ar,heapsize,0);
	(*n) = heapsize;
	return small;
}

void build_min_heap(code ar[],int arraysize) {
    int i;
    for(i = arraysize/2-1;i>=0;i--)
        min_heapify(ar,arraysize,i);
}

void min_heapify(code ar[],int heapsize,int pos) {
    int l,r,min;
    l = left(pos);
    r = right(pos);
    min = pos;
    if((l<heapsize) && (ar[l].freq < ar[min].freq))
        min = l;
    if((r<heapsize) && (ar[r].freq < ar[min].freq))
        min = r;
    if(min != pos) {
        swap(&ar[min],&ar[pos]);
        min_heapify(ar,heapsize,min);
    }
}


int left(int i) {
    return 2*i + 1;
}

int right(int i) {
    return 2*i + 2;
}

int parent(int i) {
    return (i-1) / 2;
}

void swap(code *a,code *b) {
    code tmp = *a;
    *a = *b;
    *b = tmp;
}
