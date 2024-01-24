#include <stdio.h>
#include <math.h>

int *arrayAdder(int numOfBits, int *arr1, int *arr2, int *add)
{
    int reminder=0;
    int adding[numOfBits];
    for (int i = numOfBits-1; i >= 0; i=i-1)
    {
        if (reminder+*(arr1+i)+*(arr2+i)==3)
        {
            adding[i]=1;
            reminder=1;
        }
        else if(reminder+*(arr1+i)+*(arr2+i)==2)
        {
            adding[i]=0;
            reminder=1;
        }
        else if(reminder+*(arr1+i)+*(arr2+i)==1)
        {
            adding[i]=1;
            reminder=0;            
        }
        else if(reminder+*(arr1+i)+*(arr2+i)==0)
        {
            adding[i]=0;
            reminder=0;            
        }
    }
    add=adding;
    return add;
}

int *decimalToBinary(int decimalNum, int numOfBits, int *pointOfBinary)        //converting decimal to binary
{
    int binaryNum[numOfBits];
    int rem;      //reminder and base of the binary number -0 or 1- (10,100,1000,...) debending on the number of division 
    numOfBits=numOfBits-1;
    for (int i=0; i<numOfBits; i++)
      binaryNum[i]=0;
    while (decimalNum!=0)
    {
        rem = decimalNum%2;
        decimalNum = decimalNum / 2;
        binaryNum[numOfBits] = rem;
        numOfBits=numOfBits-1;
    }
    pointOfBinary = binaryNum;      //convert to binary array
    return pointOfBinary;
}

int *onescomp(int numOfBits, int *binaryNumber, int *onecomp)
{
    int onecomplementarray[numOfBits];
    for(int j = 0; j < numOfBits; j++)
    {
        if(*(binaryNumber+j)==1)
          onecomplementarray[j]=0;
        else onecomplementarray[j]=1;
    }
    onecomp=onecomplementarray;
    return onecomp;
}

int main()
{
    int decimalNum;
    int decimalNum2;
    int numOfBits;
    int *pointerBinary;
    int *pointerBinary2;
    printf("Enter first Decimal Number: ");
    scanf("%d", &decimalNum);
    printf("Enter second Decimal Number: ");
    scanf("%d", &decimalNum2);
    printf("Enter Number of bits use for representation: ");
    scanf("%d", &numOfBits);
    pointerBinary=decimalToBinary(decimalNum,numOfBits,pointerBinary);
    
    int binaryArray[numOfBits];
    int binaryArray2[numOfBits];
    for (int i = 0; i < numOfBits; i++) 
      binaryArray[i]=*(pointerBinary+i);
    for(int loop = 0; loop < numOfBits; loop++)
      printf("%d ", binaryArray[loop]);
    printf(" + ");
    pointerBinary2=decimalToBinary(decimalNum2,numOfBits,pointerBinary2);
    for (int i = 0; i < numOfBits; i++) 
      binaryArray2[i]=*(pointerBinary2+i);
    for(int loop = 0; loop < numOfBits; loop++)
      printf("%d ", binaryArray2[loop]);
    
    
    //if we give pointer pointOfBinary directly to add func we get an error and pointers exchange 
    //so we refere it first to array then to pointer again and then use it in add func
    //and you have to give values of pointers to array before begining to use at any functions
    int *sumPointer;
    int sumArray[numOfBits]; 
    sumPointer = arrayAdder(numOfBits,binaryArray,binaryArray2,sumPointer);
    for (int i = 0; i < numOfBits; i++) 
      sumArray[i]=*(sumPointer+i);
    printf(" = ");
    for(int loop = 0; loop < numOfBits; loop++)
      printf(" %d ", sumArray[loop]);
    printf("\n");


    /*two's complement*/
    int onecomp[numOfBits];
    for(int j = 0; j < numOfBits; j++)
    {
        if(binaryArray2[j]==1)
          onecomp[j]=0;
         else onecomp[j]=1;
    }
    int *comp=onecomp;
    int *complement;
    int one[numOfBits];
    for(int i = 0; i < numOfBits; i++)
    {
          if (i==(numOfBits-1))
          {
              one[i]=1;
          }
          else one[i]=0;
    }
    
    int *onearr;
    onearr=one;
    complement = arrayAdder(numOfBits,onearr,comp,complement);
    int complementarray[numOfBits];
    for (int i = 0; i < numOfBits; i++) 
      complementarray[i]=*(complement+i);
    printf("the two's complement for the second binary number = ");
    for(int loop = 0; loop < numOfBits; loop++)
      printf("%d ", complementarray[loop]);
    
    
    return 0;
}