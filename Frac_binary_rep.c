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

int *fractionToBinary(float fractionNum, int numOfFractionBits, int *pointOfBinary)        //converting decimal to binary
{
    
    int fracBinaryNum[numOfFractionBits];
    int closeFrac[numOfFractionBits];
    float closeAdd;
    float addition=0.0;       
    for (int i=0; i<numOfFractionBits; i++)
      fracBinaryNum[i]=0;
    for (int i=0; i<numOfFractionBits; i++)
        {
            addition=addition+(pow(2,-(i+1)));
            if (addition<=fractionNum)
                fracBinaryNum[i]=1;
            if (addition>fractionNum) 
            {
                closeAdd=addition;
                for (int j=0; j<numOfFractionBits; j++) 
                    closeFrac[j]=fracBinaryNum[j];
                closeFrac[i]=1;
                addition=addition-(pow(2,-(i+1)));
            }
        }
    float A,B;
    A=fractionNum-addition;
    B=closeAdd-fractionNum;
    if (A<B)
        pointOfBinary = fracBinaryNum;      
    if (A>B)
        pointOfBinary = closeFrac;      
    return pointOfBinary;
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
    float Number;
    float fraction;
    double integer;
    int decimalNum;
    int numOfFracBits;
    int numOfintBits;
    int *pointerFractionBinary;
    int *pointerIntBinary; 
    int integerPart;  
    printf("Enter first Decimal Number: ");
    scanf("%f", &Number);
    printf("Enter Number of bits use for representation of integer part: ");
    scanf("%d", &numOfintBits);
    printf("Enter Number of bits use for representation of fraction part: ");
    scanf("%d", &numOfFracBits);
    fraction = modf(Number, &integer);
    printf("%f \n",fraction);
    printf("%f \n",integer);

    integerPart=(int)integer;
    pointerIntBinary=decimalToBinary(integerPart,numOfintBits,pointerIntBinary);
    int intBinaryArray[numOfintBits];
    for (int i = 0; i < numOfintBits; i++) 
      intBinaryArray[i]=*(pointerIntBinary+i);
    for(int loop = 0; loop < numOfintBits; loop++)
      printf("%d ", intBinaryArray[loop]);

    printf(". ");

    pointerFractionBinary=fractionToBinary(fraction,numOfFracBits,pointerFractionBinary);
    int fracBinaryArray[numOfFracBits];
    for (int i = 0; i < numOfFracBits; i++) 
      fracBinaryArray[i]=*(pointerFractionBinary+i);
    for(int loop = 0; loop < numOfFracBits; loop++)
      printf("%d ", fracBinaryArray[loop]);

    return 0;
}