 #include <stdio.h>
 int hashTable[5][1];
 
int hash(int key)
{
  return key % 5;
}
 
void addKey(int key)
{
  int bucket;
  bucket=hash(key);
  while(hashTable[bucket][0] !=0) {
   	printf("%d가 충돌 발생\n",key);
   	//bucket+=1;
  }
  hashTable[bucket][0]=key;
 
  if(hashTable[bucket][0] == 0) {
  	hashTable[bucket][0] = key;
  }
   printf("hashTable[%d][0] =%d\n", bucket,key);
 }
 
int findKey(int input)
{
	int key;
  	key = hash(input);
  	return hashTable[key][0];
}
  
int main(void)
{
	int i,input , key;
	for(i = 0; i < 5; i++) {
		printf("%d 번째 값을 입력하시오 : ",i+1);
	   	scanf("%d",&input);
	  	key = hash(input);
	   	addKey(input);
	}
  
  	for(i = 0; i < 5; i++)
   		printf("hashTable[%d][0] = %d\n", i, hashTable[i][0]);
 
	printf("찾는값을 입력하시오 : ");
 	scanf("%d",&input);
  	
	if(findKey(input) == input)
   		printf("검색되었습니다.\n");
  	else
   		printf("입력한 값은 없습니다.\n");
 
 }